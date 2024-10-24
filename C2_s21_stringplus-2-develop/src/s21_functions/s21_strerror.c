//
// Created by lifefire1 on 11/15/23.
//
#include "../s21_string.h"
#include "stdio.h"

char *s21_strerror(int errnum) {
  static char res[200] = {0};
  ERROR_ARRAY;
  int flag = 0;

  for (int i = 0; i < MAX_ERROR; i++) {
    if (errnum == i) {
      s21_strncpy(res, errlist[i], MAX_LENGTH);
      flag = -1;
    }
  }

  if (flag == 0) {
    char str[100] = ERROR;

    // Преобразование числа в строку
    snprintf(res, sizeof(res), "%s%d", str, errnum);
  }

  return res;
}