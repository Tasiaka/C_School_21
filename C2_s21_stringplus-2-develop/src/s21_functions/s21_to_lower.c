//
// Created by lifefire1 on 16.12.23.
//

#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  if (str) {
    unsigned long len = s21_strlen(str);
    res = (char *)calloc(len + 1, s21_SIZE);
    if (res != s21_NULL) {
      for (unsigned long i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          res[i] = str[i] + 32;
        } else {
          res[i] = str[i];
        }
      }
      res[len] = '\0';
    }
  }
  return res;
}
