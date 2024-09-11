# xtrabackup-monkey-patch

## Prepare for build

```bash
$ git clone https://github.com/yoku0825/xtrabackup-monkey-patch.git
$ cd xtrabackup-monkey-patch
$ git tag -l

$ git checkout tag_which_you_build

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
$ git tag "percona-xtrabackup-xxx_orig"

$ git cherry-pick commit_hash_of_old_version
$ git tag "percona-xtrabackup-xxx_patched"
```
