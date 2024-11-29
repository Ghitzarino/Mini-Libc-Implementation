// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int stat(const char *restrict path, struct stat *restrict buf) {
  int ret = syscall(__NR_stat, path, buf);

  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}
