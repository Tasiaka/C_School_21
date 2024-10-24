#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strrchr_char_present) {
  const char *str = "hello, world!";
  char c = 'o';

  char *result = s21_strrchr(str, c);
  char *result1 = strrchr(str, c);

  ck_assert_ptr_ne(result, NULL);
  ck_assert_ptr_ne(result1, NULL);
  ck_assert_int_eq(*result, *result1);
}
END_TEST

START_TEST(test_s21_strrchr_char_not_present) {
  const char *str = "hello, world!";
  char c = 'z';

  char *result = s21_strrchr(str, c);
  char *result1 = strrchr(str, c);

  ck_assert_ptr_eq(result, NULL);
  ck_assert_ptr_eq(result, result1);
}
END_TEST

START_TEST(test_s21_strrchr_empty_str) {
  const char *str = "";
  char c = 'o';

  char *result = s21_strrchr(str, c);
  char *result1 = strrchr(str, c);

  ck_assert_ptr_eq(result, NULL);
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

// START_TEST(test_s21_strrchr_null_str) {
//   const char *str = NULL;
//   char c = 'o';
//
//   char *result = s21_strrchr(str, c);
//   char *result1 = strrchr(str, c);
//
//   ck_assert_ptr_eq(result, NULL);
//   ck_assert_ptr_eq(result1, NULL);
// }
// END_TEST

Suite *strrchr_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strrchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strrchr_char_present);
  tcase_add_test(tc_core, test_s21_strrchr_char_not_present);
  tcase_add_test(tc_core, test_s21_strrchr_empty_str);
  //  tcase_add_test(tc_core, test_s21_strrchr_null_str);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strrchr_test() {
  Suite *s = strrchr_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strrchr_test(); }
