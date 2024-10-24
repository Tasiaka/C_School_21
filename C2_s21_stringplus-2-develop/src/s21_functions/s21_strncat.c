#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t dest_len = s21_strlen(dest);
  size_t i;

  for (i = 0; i < n && src[i] != '\0'; ++i) {
    dest[dest_len + i] = src[i];
  }

  dest[dest_len + i] =
      '\0';  // Добавляем завершающий нулевой символ к конкатенированной строке

  return dest;
}