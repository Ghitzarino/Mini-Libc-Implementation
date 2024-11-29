#ifndef __TIME_H__
#define __TIME_H__

#include <internal/types.h>

// Definition of timespec structure
struct timespec {
  long tv_sec;
  long tv_nsec;
};

// Declaration of nanosleep
int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
