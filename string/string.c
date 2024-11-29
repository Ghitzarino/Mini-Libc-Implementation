// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

// Implementation of strcpy
char *strcpy(char *destination, const char *source) {
  // Variable to store the destination pointer
  char *destination_copy = destination;
  // Copy the source to destination
  while (*source != '\0') {
    *destination = *source;
    source++;
    destination++;
  }
  // Add '\0' to the end of destination
  *destination = '\0';
  return destination_copy;
}

// Implementation of strncpy
char *strncpy(char *destination, const char *source, size_t len) {
  char *destination_copy = destination;
  // Copy the source to destination but maximum len characters
  while (*source != '\0' && len > 0) {
    *destination = *source;
    source++;
    destination++;
    len--;
  }
  // Add '\0' to the end of destination only if source string ended
  if (len > 0) {
    *destination = '\0';
  }
  return destination_copy;
}

// Implementation of strcat
char *strcat(char *destination, const char *source) {
  char *destination_copy = destination;
  // Go to the end of destination string
  while (*destination != '\0') {
    destination++;
  }
  // Add source to the end of destination
  while (*source != '\0') {
    *destination = *source;
    source++;
    destination++;
  }
  // Add '\0' to the end of destination
  *destination = '\0';
  return destination_copy;
}

// Implementation of strncat
char *strncat(char *destination, const char *source, size_t len) {
  char *destination_copy = destination;
  // Go to the end of destination string
  while (*destination != '\0') {
    destination++;
  }
  // Add source to the end of destination but maximum len characters
  while (*source != '\0' && len > 0) {
    *destination = *source;
    source++;
    destination++;
    len--;
  }
  // Add '\0' to the end of destination
  *destination = '\0';

  return destination_copy;
}

// Implementation of strcmp
int strcmp(const char *str1, const char *str2) {
  // Iterate through strings until different character or end of one of them
  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }

  // Check if the character is equal, smaller or bigger then the other character
  if (*str1 == *str2)
    return 0;
  else if (*str1 < *str2)
    return -1;
  else
    return 1;
}

// Implementation of strncmp
int strncmp(const char *str1, const char *str2, size_t len) {
  // Iterate through strings until different character or end of one of them or
  // maximum length
  while (len > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
    len--;
  }

  // Check if the character is equal, smaller or bigger then the other character
  // (on specified length)
  if (len == 0 || (*str1 == *str2))
    return 0;
  else if (*str1 < *str2)
    return -1;
  else
    return 1;
}

// Implementation of strlen
size_t strlen(const char *str) {
  size_t i = 0;

  for (; *str != '\0'; str++, i++)
    ;

  return i;
}

// Implementation of strchr
char *strchr(const char *str, int c) {
  // Check for appearances of c character (in ASCII) in str string
  while (*str != '\0') {
    // Returns first appearance
    if (*str == (char)c) {
      return (char *)str;
    }
    str++;
  }
  // No appearance found
  return NULL;
}

// Implementation of strrchr
char *strrchr(const char *str, int c) {
  char *last_appearance = NULL;
  // Check for appearances of c character (in ASCII) in str string
  while (*str != '\0') {
    // Store last appearance
    if (*str == (char)c) {
      last_appearance = (char *)str;
    }
    str++;
  }
  // Return the last appearence (or NULL if not found)
  return last_appearance;
}

// Implementation of strstr
char *strstr(const char *haystack, const char *needle) {
  size_t len = strlen(needle);
  // Go character by character through haystack and search for needle appearance
  while (*haystack != '\0') {
    if (strncmp(haystack, needle, len) == 0) {
      // Return first appearance
      return (char *)haystack;
    }
    haystack++;
  }
  // Needle not found
  return NULL;
}

// Implementation of strrstr
char *strrstr(const char *haystack, const char *needle) {
  char *last_appearance = NULL;
  size_t len = strlen(needle);
  // Go character by character through haystack and search for needle appearance
  while (*haystack != '\0') {
    // Store last appearance
    if (strncmp(haystack, needle, len) == 0) {
      last_appearance = (char *)haystack;
    }
    haystack++;
  }
  // Return the last appearence (or NULL if not found)
  return last_appearance;
}

// Implementation of memcpy
void *memcpy(void *destination, const void *source, size_t num) {
  // Cast source and destination to char*
  const char *src = (const char *)source;
  char *dest = (char *)destination;
  int i;
  // Change values in memory location of destination
  for (i = 0; i < (int)num; i++) {
    dest[i] = src[i];
  }
  return destination;
}

// Implementation of memmove
void *memmove(void *destination, const void *source, size_t num) {
  // Cast source and destination to char*
  const char *src = (const char *)source;
  char *dest = (char *)destination;
  int i;

  if (dest == src) {
    // Source and destiantion are the same
    return destination;
  } else if (dest < src || dest >= (src + num)) {
    // Source and destination don't overlap in the memory
    for (i = 0; i < (int)num; i++) {
      dest[i] = src[i];
    }
  } else {
    // Source and doestination overlap so copy from the end
    for (i = num - 1; i >= 0; i--) {
      dest[i] = src[i];
    }
  }
  return destination;
}

// Implementation of memcmp
int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  // Cast pointers to char*
  const char *p1 = (const char *)ptr1;
  const char *p2 = (const char *)ptr2;
  int i;
  // Compare char by char
  for (i = 0; i < (int)num; i++) {
    if (p1[i] < p2[i])
      return -1;
    else if (p1[i] > p2[i])
      return 1;
  }
  // Both pointers point to equal character sequences
  return 0;
}

// Implementation of memset
void *memset(void *source, int value, size_t num) {
  // Cast source to char*
  char *src = (char *)source;
  int i;
  // Give value to each character in src num times
  for (i = 0; i < (int)num; i++) {
    src[i] = (char)value;
  }
  return source;
}
