// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int fstat(int fd, struct stat *st) {
  int ret = syscall(__NR_fstat, fd, st);

  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}
