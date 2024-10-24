#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strtok_basic) {
  char str[] = "Hello, World! How are you?";
  char delim[] = " ,!?";
  char *token;

  char str1[] = "Hello, World! How are you?";
  char delim1[] = " ,!?";
  char *token1;

  // Первый вызов
  token = s21_strtok(str, delim);
  token1 = strtok(str1, delim1);
  ck_assert_str_eq(str, str1);
  ck_assert_str_eq(token, token1);

  // Последующие вызовы
  token = s21_strtok(NULL, delim);
  token1 = strtok(NULL, delim1);
  ck_assert_str_eq(str, str1);
  ck_assert_str_eq(token, token1);

  token = s21_strtok(NULL, delim);
  token1 = strtok(NULL, delim1);
  ck_assert_str_eq(str, str1);
  ck_assert_str_eq(token, token1);

  token = s21_strtok(NULL, delim);
  token1 = strtok(NULL, delim1);
  ck_assert_str_eq(str, str1);
  ck_assert_str_eq(token, token1);

  token = s21_strtok(NULL, delim);
  token1 = strtok(NULL, delim1);
  ck_assert_str_eq(str, str1);
  ck_assert_str_eq(token, token1);
}
END_TEST

START_TEST(test_s21_strtok_empty_string) {
  char *str = "";
  char *delim = " ,!?";

  char *str1 = "";
  char *delim1 = " ,!?";

  char *token = s21_strtok(str, delim);
  char *token1 = strtok(str1, delim1);

  ck_assert_str_eq(str, str1);
  ck_assert_ptr_eq(token, NULL);
  ck_assert_ptr_eq(token1, NULL);
}
END_TEST

START_TEST(test_s21_strtok_end_string) {
  char str[20] = "This is simple text";
  char *delim = " ";

  char str1[20] = "This is simple text";
  char *delim1 = " ";

  s21_strtok(str, delim);
  s21_strtok(NULL, delim);
  s21_strtok(NULL, delim);
  s21_strtok(NULL, delim);
  char *token1 = s21_strtok(NULL, delim);

  strtok(str1, delim1);
  strtok(NULL, delim1);
  strtok(NULL, delim1);
  strtok(NULL, delim1);
  char *token = strtok(NULL, delim1);

  ck_assert_ptr_eq(token1, NULL);
  ck_assert_ptr_eq(token, NULL);
}
END_TEST

// START_TEST(test_s21_strtok_null_string) {
//   char *delim = " ,!?";
//   char *delim1 = " ,!?";
//
//   char *token = s21_strtok(NULL, delim);
//
//   char *token1 = strtok(NULL, delim1);
//
//   ck_assert_ptr_eq(token, NULL);
//   ck_assert_ptr_eq(token1, NULL);
// }
// END_TEST

Suite *strtok_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strtok");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strtok_basic);
  tcase_add_test(tc_core, test_s21_strtok_empty_string);
  //  tcase_add_test(tc_core, test_s21_strtok_null_string);
  //  tcase_add_test(tc_core, test_s21_strtok_null_delim);
  tcase_add_test(tc_core, test_s21_strtok_end_string);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strtok_test() {
  Suite *s = strtok_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strtok_test(); }
