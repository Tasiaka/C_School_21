//
// Created by lifefire1 on 11/12/23.
//
#include "../s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  unsigned char *ptr = str;

  for (size_t i = 0; i < n; ++i) {
    ptr[i] = (unsigned char)c;
  }

  return str;
}