//
// Created by lifefire1 on 16.12.23.
//
#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  void *res = s21_NULL;
  if (str != s21_NULL) {
    char *insert_str =
        malloc((s21_strlen(str) + s21_strlen(src) + 1) * sizeof(char));
    if (insert_str) {
      if (s21_strlen(src) < start_index) {
        free(insert_str);
      } else {
        res = insert_str;
        s21_strncpy(insert_str, src, start_index);
        insert_str[start_index] = '\0';
        s21_strcat(insert_str, str);
        s21_strcat(insert_str, src + start_index);
      }
    }
  }
  return res;
}
