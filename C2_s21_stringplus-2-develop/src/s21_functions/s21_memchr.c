#include "../s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  const unsigned char *ptr = str;

  for (size_t i = 0; i < n; ++i) {
    if (ptr[i] == (unsigned char)c) {
      return (void *)(ptr + i);
    }
  }

  return NULL;  // Символ не найден
}