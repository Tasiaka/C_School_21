//
// Created by lifefire1 on 16.12.23.
//
#include "../s21_string.h"

size_t s21_strspn(const char *str, const char *accept) {
  size_t count = 0;
  while (str[count] != '\0' && s21_strchr(accept, str[count]) != NULL) {
    count++;
  }
  return count;
}