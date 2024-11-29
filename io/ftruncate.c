// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int ftruncate(int fd, long length) {
  int ret = syscall(__NR_ftruncate, fd, length);

  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}
