#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strncmp_equal) {
  const char *str1 = "Hello, World!";
  const char *str2 = "Hello, World!";

  ck_assert_int_eq(s21_strncmp(str1, str2, 13), strncmp(str1, str2, 13));
}
END_TEST

START_TEST(test_s21_strncmp_less) {
  const char *str1 = "abc";
  const char *str2 = "def";

  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(test_s21_strncmp_greater) {
  const char *str1 = "def";
  const char *str2 = "abc";

  ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(test_s21_strncmp_partial) {
  const char *str1 = "abcd";
  const char *str2 = "abcdef";

  ck_assert_int_eq(s21_strncmp(str1, str2, 4), strncmp(str1, str2, 4));
}
END_TEST

Suite *strncmp_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strncmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncmp_equal);
  tcase_add_test(tc_core, test_s21_strncmp_less);
  tcase_add_test(tc_core, test_s21_strncmp_greater);
  tcase_add_test(tc_core, test_s21_strncmp_partial);
  //  tcase_add_test(tc_core, test_s21_strncmp_null);
  //  tcase_add_test(tc_core, test_s21_strncmp_null_sec);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strncmp_test() {
  Suite *s = strncmp_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strncmp_test(); }
