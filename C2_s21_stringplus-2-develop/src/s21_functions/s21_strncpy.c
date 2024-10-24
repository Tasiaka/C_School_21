#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *dest_start = dest;

  while (n > 0 && *src != '\0') {
    *dest++ = *src++;
    --n;
  }

  while (n > 0) {
    *dest++ = '\0';  // Заполнение оставшегося места нулевыми символами
    --n;
  }

  return dest_start;
}
