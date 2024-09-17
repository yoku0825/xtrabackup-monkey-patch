/******************************************************
XtraBackup: hot backup tool for InnoDB
(c) 2009-2013 Percona LLC and/or its affiliates.
Originally Created 3/3/2009 Yasufumi Kinoshita
Written by Alexey Kopytov, Aleksandr Kuzminsky, Stewart Smith, Vadim Tkachenko,
Yasufumi Kinoshita, Ignacio Nin and Baron Schwartz.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA

*******************************************************/

/* Page write filters implementation */

#include "write_filt.h"
#include <my_base.h>
#include <vector>
#include "backup_copy.h"
#include "common.h"
#include "dict0dict.h"
#include "fil_cur.h"
#include "msg.h"
#include "xtrabackup.h"

/************************************************************************
Write-through page write filter. */
static bool wf_wt_init(xb_write_filt_ctxt_t *ctxt, char *dst_name,
                       xb_fil_cur_t *cursor);
static bool wf_wt_process(xb_write_filt_ctxt_t *ctxt, ds_file_t *dstfile);

xb_write_filt_t wf_write_through = {&wf_wt_init, &wf_wt_process, NULL, NULL};

/************************************************************************
Incremental page write filter. */
static bool wf_incremental_init(xb_write_filt_ctxt_t *ctxt, char *dst_name,
                                xb_fil_cur_t *cursor);
static bool wf_incremental_process(xb_write_filt_ctxt_t *ctxt,
                                   ds_file_t *dstfile);
static bool wf_incremental_finalize(xb_write_filt_ctxt_t *ctxt,
                                    ds_file_t *dstfile);
static void wf_incremental_deinit(xb_write_filt_ctxt_t *ctxt);

xb_write_filt_t wf_incremental = {&wf_incremental_init, &wf_incremental_process,
                                  &wf_incremental_finalize,
                                  &wf_incremental_deinit};

/************************************************************************
Initialize incremental page write filter.

@return true on success, false on error. */
static bool wf_incremental_init(xb_write_filt_ctxt_t *ctxt, char *dst_name,
                                xb_fil_cur_t *cursor) {
  char meta_name[FN_REFLEN];
  xb_delta_info_t info;
  ulint buf_size;
  xb_wf_incremental_ctxt_t *cp = &(ctxt->wf_incremental_ctxt);

  ctxt->cursor = cursor;

  /* allocate buffer for incremental backup (4096 pages) */
  buf_size =
      (cursor->page_size / 4 + 1) * cursor->page_size + UNIV_PAGE_SIZE_MAX;
  cp->delta_buf_base = static_cast<byte *>(
      ut::malloc_withkey(UT_NEW_THIS_FILE_PSI_KEY, buf_size));
  memset(cp->delta_buf_base, 0, buf_size);
  cp->delta_buf =
      static_cast<byte *>(ut_align(cp->delta_buf_base, UNIV_PAGE_SIZE_MAX));

  /* write delta meta info */
  snprintf(meta_name, sizeof(meta_name), "%s%s", dst_name,
           XB_DELTA_INFO_SUFFIX);
  info.page_size = cursor->page_size;
  info.zip_size = cursor->zip_size;
  info.space_id = cursor->space_id;
  info.space_flags = cursor->space_flags;
  if (!xb_write_delta_metadata(meta_name, &info)) {
    msg("[%02u] xtrabackup: Error: failed to write meta info for %s\n",
        cursor->thread_n, cursor->rel_path);
    return (false);
  }

  /* change the target file name, since we are only going to write
  delta pages */
  strcat(dst_name, ".delta");

  mach_write_to_4(cp->delta_buf, 0x78747261UL); /*"xtra"*/
  cp->npages = 1;

  return (true);
}

/************************************************************************
Run the next batch of pages through incremental page write filter.

@return true on success, false on error. */
static bool wf_incremental_process(xb_write_filt_ctxt_t *ctxt,
                                   ds_file_t *dstfile) {
  ulint i;
  xb_fil_cur_t *cursor = ctxt->cursor;
  ulint page_size = cursor->page_size;
  byte *page;
  xb_wf_incremental_ctxt_t *cp = &(ctxt->wf_incremental_ctxt);
  for (i = 0, page = cursor->buf; i < cursor->buf_npages;
       i++, page += page_size) {
    /*
     * We use metadata_from_lsn for mysql.ibd because we skip applying logical
     * redos (MLOG_TABLE_DYNAMIC_META) during the incremental prepare (except
     * the last prepare). These logical redos are converted to regular redo and
     * flushed to pages in mysql.ibd when the server process a checkpoint. So
     * we directly take the physical changes made to innodb_dynamic_metadata
     * since the last backup. Hence we copy all changes to mysql.ibd since last
     * backup start_lsn instead of last backup end_lsn.
     */
    if (cursor->space_id == dict_sys_t::s_dict_space_id &&
        metadata_from_lsn > mach_read_from_8(page + FIL_PAGE_LSN))
      continue;
    else if (incremental_lsn > mach_read_from_8(page + FIL_PAGE_LSN))
      continue;

    /* updated page */
    if (cp->npages == page_size / 4) {
      /* flush buffer */
      if (ds_write(dstfile, cp->delta_buf, cp->npages * page_size)) {
        return (false);
      }

      /* clear buffer */
      memset(cp->delta_buf, 0, page_size / 4 * page_size);
      /*"xtra"*/
      mach_write_to_4(cp->delta_buf, 0x78747261UL);
      cp->npages = 1;
    }

    mach_write_to_4(cp->delta_buf + cp->npages * 4, cursor->buf_page_no + i);
    memcpy(cp->delta_buf + cp->npages * page_size, page, page_size);

    cp->npages++;
  }

  return (true);
}

/************************************************************************
Flush the incremental page write filter's buffer.

@return true on success, false on error. */
static bool wf_incremental_finalize(xb_write_filt_ctxt_t *ctxt,
                                    ds_file_t *dstfile) {
  xb_fil_cur_t *cursor = ctxt->cursor;
  ulint page_size = cursor->page_size;
  xb_wf_incremental_ctxt_t *cp = &(ctxt->wf_incremental_ctxt);

  if (cp->npages != page_size / 4) {
    mach_write_to_4(cp->delta_buf + cp->npages * 4, 0xFFFFFFFFUL);
  }

  /* Mark the final block */
  mach_write_to_4(cp->delta_buf, 0x58545241UL); /*"XTRA"*/

  /* flush buffer */
  if (ds_write(dstfile, cp->delta_buf, cp->npages * page_size)) {
    return (false);
  }

  return (true);
}

/************************************************************************
Free the incremental page write filter's buffer. */
static void wf_incremental_deinit(xb_write_filt_ctxt_t *ctxt) {
  xb_wf_incremental_ctxt_t *cp = &(ctxt->wf_incremental_ctxt);

  if (cp->delta_buf_base != NULL) {
    ut::free(cp->delta_buf_base);
  }
}

/************************************************************************
Initialize the write-through page write filter.

@return true on success, false on error. */
static bool wf_wt_init(xb_write_filt_ctxt_t *ctxt,
                       char *dst_name __attribute__((unused)),
                       xb_fil_cur_t *cursor) {
  ctxt->cursor = cursor;

  return (true);
}

/************************************************************************
Write the next batch of pages to the destination datasink.

@return true on success, false on error. */
static bool wf_wt_process(xb_write_filt_ctxt_t *ctxt, ds_file_t *dstfile) {
  const auto cursor = ctxt->cursor;

  return write_ibd_buffer(
      dstfile, cursor->buf, cursor->buf_npages * cursor->page_size,
      cursor->page_size, cursor->block_size, punch_hole_supported);
}
