###############################################################################
# Bug #1418438: innobackupex --compress only compress innodb tables
###############################################################################

start_server

mysql -e "CREATE TABLE test (A INT PRIMARY KEY) ENGINE=MyISAM" test

xtrabackup --compress --backup --tables=test.test --target-dir=$topdir/backup

diff -u <(LANG=C ls $topdir/backup/test | sed 's/[0-9]/x/g') - <<EOF
test.MYD.zst
test.MYI.zst
test_xxx.sdi.zst
EOF
