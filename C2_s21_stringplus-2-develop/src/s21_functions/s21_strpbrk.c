#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1 != '\0') {
    if (s21_strchr(str2, *str1) != NULL) {
      return (char *)str1;  // Нашли первое вхождение символа из str2
    }
    str1++;
  }

  return NULL;  // Символы из str2 не встречаются в str1
}
