// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int truncate(const char *path, long length) {
  int ret = syscall(__NR_truncate, path, length);

  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}
