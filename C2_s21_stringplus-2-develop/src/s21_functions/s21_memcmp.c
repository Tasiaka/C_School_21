//
// Created by lifefire1 on 11/12/23.
//
#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *f_ptr = str1;
  const unsigned char *s_ptr = str2;
  for (size_t i = 0; i < n; ++i) {
    if (f_ptr[i] > s_ptr[i] || f_ptr[i] < s_ptr[i]) {
      return f_ptr[i] - s_ptr[i];
    }
  }
  return 0;
}