//
// Created by lifefire1 on 11/13/23.
//

#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    if (str1[i] == '\0' || str2[i] == '\0' || str1[i] > str2[i] ||
        str1[i] < str2[i]) {
      return str1[i] - str2[i];
    }
  }

  return 0;
}
