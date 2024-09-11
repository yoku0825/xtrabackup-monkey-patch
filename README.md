# xtrabackup-monkey-patch

## Prepare for build

```bash
$ git clone https://github.com/yoku0825/xtrabackup-monkey-patch.git
$ cd xtrabackup-monkey-patch
$ git tag -l

$ git checkout tag_which_you_build

$ cmake3 -DCMAKE_INSTALL_PREFIX=/usr/xtrabackup/8.0.35-1-patched -DWITH_BOOST=./boost -DDOWNLOAD_BOOST=1 -DFORCE_INSOURCE_BUILD=1
$ make
$ make install
```
