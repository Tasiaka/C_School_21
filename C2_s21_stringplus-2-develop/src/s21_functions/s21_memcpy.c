#include <stdlib.h>

#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  if (n == 0) {
    return dest;
  }

  char *d = dest;
  const char *s = src;  // Avoid casting away const

  char *tempBuffer = (char *)malloc(n);
  //  if (tempBuffer == NULL) {
  //    return NULL;  // Memory allocation failed
  //  }

  // Check for overlapping blocks
  if ((d > tempBuffer && d < tempBuffer + n) || (s > d && s < d + n)) {
    free(tempBuffer);
    return "";  // Overlapping blocks
  }

  for (size_t i = 0; i < n; ++i) {
    tempBuffer[i] = s[i];
  }

  for (size_t i = 0; i < n; ++i) {
    d[i] = tempBuffer[i];
  }

  free(tempBuffer);
  return dest;
}
