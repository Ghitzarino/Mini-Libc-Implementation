#include <time.h>

unsigned int sleep(unsigned int seconds) {
  // Create timespec element for sleep
  struct timespec req, rem;
  req.tv_sec = seconds;
  req.tv_nsec = 0;

  // Implement sleep using nanosleep
  while (nanosleep(&req, &rem) == -1) {
    if (rem.tv_sec == 0 && rem.tv_nsec == 0) {
      break;
    }
    req = rem;
  }

  return 0;
}
