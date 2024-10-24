#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strstr_substring_present) {
  const char *haystack = "Hello, World!";
  const char *needle = "World";

  char *result = s21_strstr(haystack, needle);
  char *result1 = strstr(haystack, needle);

  ck_assert_ptr_ne(result, NULL);
  ck_assert_ptr_ne(result1, NULL);
  ck_assert_str_eq(result, result1);
}
END_TEST

START_TEST(test_s21_strstr_substring_not_present) {
  const char *haystack = "Hello, World!";
  const char *needle = "Universe";

  char *result = s21_strstr(haystack, needle);
  char *result1 = strstr(haystack, needle);

  ck_assert_ptr_eq(result, NULL);
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

START_TEST(test_s21_strstr_empty_haystack) {
  const char *haystack = "";
  const char *needle = "World";

  char *result = s21_strstr(haystack, needle);
  char *result1 = strstr(haystack, needle);

  ck_assert_ptr_eq(result, NULL);
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
  const char *haystack = "Hello, World!";
  const char *needle = "";

  char *result = s21_strstr(haystack, needle);
  char *result1 = strstr(haystack, needle);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_ptr_ne(result1, NULL);
  ck_assert_str_eq(result, result1);
}
END_TEST

// START_TEST(test_s21_strstr_null_haystack) {
//   const char *haystack = NULL;
//   const char *needle = "World";
//
//   char *result = s21_strstr(haystack, needle);
//   char *result1 = strstr(haystack, needle);
//
//   ck_assert_ptr_eq(result, NULL);
//   ck_assert_ptr_eq(result1, NULL);
// }
// END_TEST

// START_TEST(test_s21_strstr_null_needle) {
//   const char *haystack = "Hello, World!";
//   const char *needle = NULL;
//
//   char *result = s21_strstr(haystack, needle);
//   char *result1 = strstr(haystack, needle);
//   ck_assert_ptr_eq(result, NULL);
//   ck_assert_ptr_eq(result1, NULL);
// }
// END_TEST

Suite *strstr_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strstr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_substring_present);
  tcase_add_test(tc_core, test_s21_strstr_substring_not_present);
  tcase_add_test(tc_core, test_s21_strstr_empty_haystack);
  tcase_add_test(tc_core, test_s21_strstr_empty_needle);
  //  tcase_add_test(tc_core, test_s21_strstr_null_haystack);
  //  tcase_add_test(tc_core, test_s21_strstr_null_needle);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strstr_test() {
  Suite *s = strstr_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strstr_test(); }
