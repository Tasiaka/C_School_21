#include "../s21_string.h"
size_t s21_strlen(const char *str) {
  if (str == NULL) {
    return 0;
  }
  size_t length = 0;
  while (*(str + length) != '\0') {
    length++;
  }
  return length;
}