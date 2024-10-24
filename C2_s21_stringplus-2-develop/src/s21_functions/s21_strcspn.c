#include "../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t length = 0;

  while (str1[length] != '\0' && !s21_strchr(str2, str1[length])) {
    length++;
  }

  return length;
}
