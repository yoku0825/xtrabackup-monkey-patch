if is_server_version_higher_than 8.0.35
then
    die "We should check if smart memory is mature to transition to GA."
fi

. inc/common.sh
require_debug_pxb_version

function run_insert() {
  while true ; do
    mysql -e "INSERT INTO pxb_2710 VALUES (NULL); SELECT SLEEP(0.5)" test
  done
}
# PXB-2710 - Predict memory at --prepare

MYSQLD_EXTRA_MY_CNF_OPTS="
innodb-flush-log-at-trx-commit=0
sync-binlog=0
"
if is_server_version_higher_than 8.0.29
then
  MYSQLD_EXTRA_MY_CNF_OPTS="${MYSQLD_EXTRA_MY_CNF_OPTS:-""}
  innodb-redo-log-capacity=512M
  "
fi
start_server
backupdir="${topdir}/full"
backupdir2="${topdir}/full2"
pid_file=${backupdir}/xtrabackup_debug_sync
logfile="${topdir}/xtrabackup.out"
logfile2="${topdir}/xtrabackup2.out"

run_cmd $MYSQL $MYSQL_ARGS test <<EOF
CREATE TABLE pxb_2710(a INT PRIMARY KEY AUTO_INCREMENT) ENGINE=InnoDB;
INSERT INTO pxb_2710 VALUES (NULL);
EOF
innodb_wait_for_flush_all

xtrabackup --backup --estimate-memory --target-dir=${backupdir} --debug-sync=xtrabackup_pause_after_redo_catchup &
job_pid=$!
wait_for_xb_to_suspend $pid_file
xb_pid=`cat $pid_file`


# generate some data and check if it has reached 128M
vlog "Starting to generate some data ..."

# make sure we have a SQL that creates a lot of new pages
( while true ; do
    mysql -e "INSERT INTO pxb_2710 SELECT NULL FROM pxb_2710 LIMIT 10000" test
done ) 2>/dev/null &
insert_pid=$!

start_lsn=`innodb_lsn`
i=0
while true ; do
  new_lsn=`innodb_lsn`
  current_redo_size=$((${new_lsn} - ${start_lsn}))
  if [[ "${current_redo_size}" -gt "41943040" ]];
  then
    break
  fi
  i=$((${i}+1))
  # print log every 30 seconds
  if [[ "$((${i} % 3 ))" -eq "0" ]];
  then
    vlog "Populating database with some data, current size: ${current_redo_size}"
  fi
  sleep 10
done

#stop inserting data
kill -SIGKILL ${insert_pid}

# avoid race condition when we trx is running and backup get it without it been
# completed, having to roll it back and when we record db state it is completed.
while mysql -e 'SHOW PROCESSLIST' | grep 'INSERT INTO pxb_2710 SELECT NULL FROM pxb_2710 LIMIT 10000' ; do
  vlog "waiting for INSERT to complete"
  sleep 1;
done

# resume and wait for backup to complete
vlog "Resuming xtrabackup"
kill -SIGCONT $xb_pid
run_cmd wait $job_pid

record_db_state test
stop_server
rm -rf $mysql_datadir

vlog "Making a copy of backup dir"
cp -R ${backupdir} ${backupdir2}


# memory calculations to avoid false positves
redo_memory=$(grep 'redo_memory' ${backupdir}/xtrabackup_checkpoints | awk '{print $3}') #bytes
redo_frames=$(grep 'redo_frames' ${backupdir}/xtrabackup_checkpoints | awk '{print $3}') #pages
total_memory=$((redo_memory + (redo_frames * 16384))) #bytes

free_memory=$(cat /proc/meminfo | grep 'MemAvailable' | awk '{print $2}') #kb
free_memory_bytes=$((free_memory * 1024)) #bytes
free_memory_1_pct=$((free_memory_bytes  * 1 / 100)) #bytes
free_memory_99_pct=$((free_memory_bytes  * 99 / 100)) #bytes

if [[ "${free_memory_99_pct}" -lt "${total_memory}" ]];
then
  vlog "Skipping full memory workload test as 99% of free memory is lower than required by pxb"
else
  vlog "Preparing backup with --use-free-memory-pct=99"
  xtrabackup --prepare --use-free-memory-pct=99 --target-dir=${backupdir} 2> ${logfile}

  if grep -q "Required memory will exceed free memory configuration" ${logfile}
  then
    die "Xtrabackup should not have exceed free memory."
  fi

  if ! grep -q "Setting free frames to ${redo_frames}" ${logfile}
  then
    die "Xtrabackup should have adjusted frames to ${redo_frames}."
  fi
  xtrabackup --copy-back --target-dir=${backupdir}
  start_server
  run_cmd verify_db_state test
  stop_server
  rm -rf $mysql_datadir
fi

if [[ "${free_memory_1_pct}" -gt "${total_memory}" ]];
then
  vlog "Adjusting redo_memory to a very high value so it exceed 1% of memory"
  # 100G
  sed -i -e '/redo_memory =/ s/= .*/= 107374182400/' ${backupdir2}/xtrabackup_checkpoints
fi

vlog "Preparing backup with --use-free-memory-pct=1"
xtrabackup --prepare --use-free-memory-pct=1 --target-dir=${backupdir2} 2> ${logfile2}

if ! grep -q "Required memory will exceed Free memory configuration" ${logfile2}
then
    die "Xtrabackup should have exceed free memory."
fi
xtrabackup --copy-back --target-dir=${backupdir2}
start_server
run_cmd verify_db_state test
stop_server
rm -rf $mysql_datadir

# PXB-2980 - Add a parameter to disable memory estimation during backup
start_server
backupdir=${topdir}/backup
run_cmd $MYSQL $MYSQL_ARGS test <<EOF
CREATE TABLE pxb_2710(a INT PRIMARY KEY AUTO_INCREMENT) ENGINE=InnoDB;
INSERT INTO pxb_2710 VALUES (NULL);
EOF
innodb_wait_for_flush_all
run_insert &
insert_pid=$!
trap "kill -SIGKILL $insert_pid" EXIT

vlog "Test 1 - Default to off"
mkdir ${backupdir}
xtrabackup --backup --target-dir=${backupdir}

if ! grep -q "redo_memory = 0" ${backupdir}/xtrabackup_checkpoints
then
    die "Smart memory was enabled by default."
fi

vlog "Test 2 - Setting --estimate-memory to off"
rm -rf ${backupdir}
mkdir ${backupdir}
xtrabackup --backup --estimate-memory=OFF --target-dir=${backupdir}

if ! grep -q "redo_memory = 0" ${backupdir}/xtrabackup_checkpoints
then
    die "Smart memory was performed even with --estimate-memory=OFF."
fi


vlog "Test 3 - Setting --estimate-memory to on"
rm -rf ${backupdir}
mkdir ${backupdir}
xtrabackup --backup --estimate-memory=ON --target-dir=${backupdir}

if ! egrep -q 'redo_memory = [1-9][0-9]*' ${backupdir}/xtrabackup_checkpoints
then
    die "Smart memory was not performed even with --estimate-memory=ON."
fi
