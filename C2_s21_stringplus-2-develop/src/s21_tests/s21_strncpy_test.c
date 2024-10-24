#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

// Тест на успешное копирование строки
START_TEST(test_s21_strncpy_success) {
  char dest[10] = "";
  const char *src = "Hello";
  char dest1[10] = "";

  char *result = s21_strncpy(dest, src, 5);
  char *res = strncpy(dest1, src, 5);
  //  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, dest1);  // Проверка, что строка скопирована правильно
  ck_assert_str_eq(res, result);
}
END_TEST

// Тест на копирование строки с нулевым символом
START_TEST(test_s21_strncpy_null_terminated) {
  char dest[10] = "";
  const char *src = "Hi";
  char dest1[10] = "";

  char *result = s21_strncpy(dest, src, 5);
  char *res = strncpy(dest1, src, 5);
  //  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, dest1);  // Проверка, что строка скопирована правильно
  ck_assert_str_eq(res, result);
}
END_TEST

// Тест на копирование строки, длина которой меньше n
START_TEST(test_s21_strncpy_short_string) {
  char dest[10] = "";
  const char *src = "Hello";
  char dest1[10] = "";

  char *result = s21_strncpy(dest, src, 10);
  char *res = strncpy(dest1, src, 10);
  //  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, dest1);  // Проверка, что строка скопирована правильно
  ck_assert_str_eq(result, res);
}
END_TEST

// Тест на копирование пустой строки
START_TEST(test_s21_strncpy_empty_string) {
  char dest[10] = "";
  char dest1[10] = "";
  const char *src = "";

  char *result = s21_strncpy(dest, src, 5);
  char *res = strncpy(dest1, src, 5);
  //  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, dest1);  // Проверка, что строка скопирована правильно
  ck_assert_str_eq(result, res);
}
END_TEST

//// Тест на копирование строки с NULL-указателем
// START_TEST(test_s21_strncpy_null_pointer) {
//   char dest[10] = "";
//   char dest1[10] = "";
//   const char *src = NULL;
//
//   char *result = s21_strncpy(dest, src, 5);
//   char *res = strncpy(dest1,src,5);
//   ck_assert_ptr_eq(result, res);  // Проверка, что возвращается NULL
// }
// END_TEST

Suite *strncpy_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strncpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_success);
  tcase_add_test(tc_core, test_s21_strncpy_null_terminated);
  tcase_add_test(tc_core, test_s21_strncpy_short_string);
  tcase_add_test(tc_core, test_s21_strncpy_empty_string);
  //  tcase_add_test(tc_core, test_s21_strncpy_null_pointer);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strncpy_test() {
  Suite *s = strncpy_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strncpy_test(); }
