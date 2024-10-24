#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strncat_basic) {
  char dest[20] = "Hello";
  char dest1[20] = "Hello";
  const char *src = " World!";

  char *res = s21_strncat(dest, src, 6);
  char *res1 = strncat(dest1, src, 6);
  ck_assert_str_eq(res, res1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

START_TEST(test_s21_strncat_empty_dest) {
  char dest[20] = "";
  char dest1[20] = "";
  const char *src = "Hello";

  char *res = s21_strncat(dest, src, 5);
  char *res1 = strncat(dest1, src, 5);
  ck_assert_str_eq(res, res1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
  char dest[20] = "Hello";
  char dest1[20] = "Hello";
  const char *src = "";

  char *res = s21_strncat(dest, src, 5);
  char *res1 = strncat(dest1, src, 5);
  ;

  ck_assert_str_eq(res, res1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

START_TEST(test_s21_strncat_long_src) {
  char dest[10] = "1234";
  char dest1[10] = "1234";
  const char *src = "567890";

  s21_strncat(dest, src, 5);
  strncat(dest1, src, 5);

  ck_assert_str_eq(dest, dest1);
}
END_TEST

Suite *strncat_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strncat");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncat_basic);
  tcase_add_test(tc_core, test_s21_strncat_empty_dest);
  tcase_add_test(tc_core, test_s21_strncat_empty_src);
  tcase_add_test(tc_core, test_s21_strncat_long_src);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strncat_test() {
  Suite *s = strncat_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strncat_test(); }
