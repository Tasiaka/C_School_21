#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strpbrk_no_common_chars) {
  const char *str1 = "abcdef";
  const char *str2 = "123456";

  char *result = s21_strpbrk(str1, str2);
  char *result1 = strpbrk(str1, str2);

  ck_assert_ptr_eq(result, result1);  // Нет общих символов
}
END_TEST

START_TEST(test_s21_strpbrk_some_common_chars) {
  const char *str1 = "abcdef";
  const char *str2 = "def456";

  char *result = s21_strpbrk(str1, str2);
  char *result1 = strpbrk(str1, str2);

  ck_assert_ptr_ne(result, NULL);  // Есть общие символы
  ck_assert_ptr_ne(result1, NULL);
  ck_assert_int_eq(*result, *result1);  // Первый общий символ - 'd'
}
END_TEST

START_TEST(test_s21_strpbrk_all_common_chars) {
  const char *str1 = "abcdef";
  const char *str2 = "abcdef";

  char *result = s21_strpbrk(str1, str2);
  char *result1 = strpbrk(str1, str2);

  ck_assert_ptr_ne(result, NULL);  // Есть общие символы
  ck_assert_ptr_ne(result1, NULL);
  ck_assert_int_eq(*result, *result1);  // Первый общий символ - 'a'
}
END_TEST

START_TEST(test_s21_strpbrk_empty_str2) {
  const char *str1 = "abcdef";
  const char *str2 = "";

  char *result = s21_strpbrk(str1, str2);
  char *result1 = strpbrk(str1, str2);

  ck_assert_ptr_eq(result, NULL);  // Пустая str2, нет общих символов
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

// START_TEST(test_s21_strpbrk_null_str2) {
//   const char *str1 = "abcdef";
//   const char *str2 = NULL;

//  char *result = s21_strpbrk(str1, str2);
//  char *result1 = strpbrk(str1, str2);

//  ck_assert_ptr_eq(result, NULL);  // Пустая str2, нет общих символов
//  ck_assert_ptr_eq(result1, NULL);
//}
// END_TEST

Suite *strpbrk_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strpbrk");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_no_common_chars);
  tcase_add_test(tc_core, test_s21_strpbrk_some_common_chars);
  tcase_add_test(tc_core, test_s21_strpbrk_all_common_chars);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_str2);
  //  tcase_add_test(tc_core, test_s21_strpbrk_null_str2);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strpbrk_test() {
  Suite *s = strpbrk_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strpbrk_test(); }
