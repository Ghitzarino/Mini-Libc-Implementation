#include <stdio.h>

int puts(const char *s) {
  int len = 0;
  // Find length for s
  while (s[len] != '\0') {
    len++;
  }

  // Write s and endline at the end
  long ret1 = write(1, s, len);
  long ret2 = write(1, "\n", 1);

  if (ret1 < 0 || ret2 < 0) {
    return -1;
  } else {
    return len + 1;
  }
}
