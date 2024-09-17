########################################################################
# Bug #983695: --copy-back should ignore *.qp files
########################################################################

. inc/common.sh

require_zstd

start_server --innodb_file_per_table
load_sakila

xtrabackup --backup --compress --target-dir=$topdir/backup

stop_server
rm -rf ${MYSQLD_DATADIR}/*

# Uncompress the backup
xtrabackup --decompress --target-dir=$topdir/backup


xtrabackup --prepare --target-dir=$topdir/backup
xtrabackup --copy-back --target-dir=$topdir/backup

run_cmd_expect_failure ls ${MYSQLD_DATADIR}/*.qp
run_cmd_expect_failure ls ${MYSQLD_DATADIR}/sakila/*.qp
