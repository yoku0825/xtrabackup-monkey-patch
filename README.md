# xtrabackup-monkey-patch

## Feature

- Add `--history-disable-log-bin` to avoid errant GTID when backup from replica server

### How to use

```
$ xtrabackup --history --history-disable-log-bin ..
```

## Prepare for build

```bash
$ git clone https://github.com/yoku0825/xtrabackup-monkey-patch.git
$ cd xtrabackup-monkey-patch
$ git branch -a

$ git checkout branch_which_you_would_like_to_build

$ cd src
$ cmake3 -DCMAKE_INSTALL_PREFIX=/path/to/install -DWITH_BOOST=./boost -DDOWNLOAD_BOOST=1 -DFORCE_INSOURCE_BUILD=1
$ make
$ make install
```

## Generate new version

```bash
$ git clone https://github.com/yoku0825/xtrabackup-monkey-patch.git
$ cd xtrabackup-monkey-patch

$ git checkout main
$ git checkout -b new_branch
## Extract new version xtrabackup source into src ##
$ git add src
$ git commit -m "Original percona-xtrabackup-xxx"

$ git cherry-pick commit_hash_of_old_version
```
