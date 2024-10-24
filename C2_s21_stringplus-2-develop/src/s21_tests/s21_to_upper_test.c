// void *to_upper(const char *str)
// Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL

#include <check.h>

#include "../s21_string.h"  // Замените на имя вашего заголовочного файла
#include "stdio.h"
#include "string.h"

START_TEST(to_upper_test1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *func = s21_to_upper(str);
  ck_assert_str_eq(func, expected);
  if (func) free(func);
}
END_TEST

START_TEST(to_upper_test2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *func = (char *)s21_to_upper(str);
  ck_assert_str_eq(func, expected);
  if (func) free(func);
}
END_TEST

START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *func = (char *)s21_to_upper(str);
  ck_assert_str_eq(func, expected);
  if (func) free(func);
}
END_TEST

START_TEST(to_upper_test4) {
  char str[] = " ";
  char expected[] = " ";
  char *func = (char *)s21_to_upper(str);
  ck_assert_str_eq(func, expected);
  if (func) free(func);
}
END_TEST

START_TEST(to_upper_test5) {
  char str[] = "";
  char expected[] = "";
  char *func = (char *)s21_to_upper(str);
  ck_assert_str_eq(func, expected);
  if (func) free(func);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *suite = suite_create("s21_to_upper");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, to_upper_test1);
  tcase_add_test(tc_core, to_upper_test2);
  tcase_add_test(tc_core, to_upper_test3);
  tcase_add_test(tc_core, to_upper_test4);
  tcase_add_test(tc_core, to_upper_test5);
  suite_add_tcase(suite, tc_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_to_upper_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}