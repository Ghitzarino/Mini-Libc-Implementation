// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

long lseek(int fd, long offset, int whence) {
  long ret = syscall(__NR_lseek, fd, offset, whence);

  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}
