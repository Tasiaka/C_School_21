#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "stdio.h"
#include "string.h"

START_TEST(test_s21_strchr_basic) {
  const char *str = "Hello, World!";
  const char *str1 = "Hello, World!";
  char *result = s21_strchr(str, 'o');
  char *res = strchr(str1, 'o');
  ck_assert_str_eq(str, str1);
  ck_assert_str_eq(result, res);
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  const char *str = "Hello, World!";
  char *result = s21_strchr(str, 'z');
  char *result1 = strchr(str, 'z');
  ck_assert_ptr_eq(result, result1);
}
END_TEST

START_TEST(test_s21_strchr_empty_str) {
  const char *str = "";
  char *result = s21_strchr(str, 'a');
  char *result1 = strchr(str, 'a');

  ck_assert_ptr_eq(result, result1);
}
END_TEST

Suite *strchr_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strchr_basic);
  tcase_add_test(tc_core, test_s21_strchr_not_found);
  tcase_add_test(tc_core, test_s21_strchr_empty_str);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strchr_test() {
  Suite *s = strchr_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strchr_test(); }
