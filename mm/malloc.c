// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
  // Allocate memory for said size
  void *ret =
      mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  // Add the allocated memory to the list
  mem_list_add(ret, size);
  return ret;
}

void *calloc(size_t nmemb, size_t size) {
  size_t total_size = nmemb * size;
  // Allocate memory for said total size
  void *ret = mmap(NULL, total_size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANON, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  // Make all elements 0
  memset(ret, 0, total_size);
  // Add the allocated memory to the list
  mem_list_add(ret, total_size);
  return ret;
}

void free(void *ptr) {
  if (ptr == NULL) {
    return;
  }
  // Get the length to free from the list
  struct mem_list *elem = mem_list_find(ptr);
  // Free the memory
  munmap(ptr, elem->len);
  // Delete the element from the list
  mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size) {
  // Free the old memory
  free(ptr);
  // Allocate new sized memory for ptr
  void *ret =
      mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  // Add the allocated memory to the list
  mem_list_add(ret, size);
  return ret;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
  size_t total_size = nmemb * size;
  // Free the old memory
  free(ptr);
  // Allocate new sized memory for ptr
  void *ret = mmap(ptr, total_size, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANON, -1, 0);
  if (ret == MAP_FAILED) {
    return NULL;
  }
  // Add the allocated memory to the list
  mem_list_add(ret, total_size);
  return ret;
  return NULL;
}
