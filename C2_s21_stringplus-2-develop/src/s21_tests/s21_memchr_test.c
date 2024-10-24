#include "../s21_string.h"
#include "check.h"
#include "string.h"

// Тест на нахождение символа в строке
START_TEST(test_s21_memchr_find) {
  const char *str = "Hello, World!";
  int c = 'o';
  size_t n = strlen(str);

  void *result = s21_memchr(str, c, n);
  void *res1 = memchr(str, c, n);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_ptr_eq(result, res1);
  ck_assert_int_eq(*(char *)result, *(char *)res1);
}
END_TEST

// Тест на ненахождение символа в строке
START_TEST(test_s21_memchr_not_found) {
  const char *str = "Hello, World!";
  int c = 'x';
  size_t n = strlen(str);

  void *result = s21_memchr(str, c, n);
  void *res1 = memchr(str, c, n);
  ck_assert_ptr_eq(result, NULL);
  ck_assert_ptr_eq(result, res1);
}
END_TEST

// Тест на нахождение символа в первых n символах строки
START_TEST(test_s21_memchr_find_in_first_n) {
  const char *str = "Hello, World!";
  int c = 'o';
  size_t n = 5;

  void *result = s21_memchr(str, c, n);
  void *res1 = memchr(str, c, n);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_ptr_eq(result, res1);
  ck_assert_int_eq(*(char *)result, *(char *)res1);
}
END_TEST

// Тест на ненахождение символа в первых n символах строки
START_TEST(test_s21_memchr_not_found_in_first_n) {
  const char *str = "Hello, World!";
  int c = 'x';
  size_t n = 5;

  void *result = s21_memchr(str, c, n);
  void *res1 = memchr(str, c, n);
  ck_assert_ptr_eq(result, NULL);
  ck_assert_ptr_eq(result, res1);
}
END_TEST

// Функция для создания и запуска тестовой сьюиты
Suite *s21_memchr_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_memchr");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memchr_find);
  tcase_add_test(tc_core, test_s21_memchr_not_found);
  tcase_add_test(tc_core, test_s21_memchr_find_in_first_n);
  tcase_add_test(tc_core, test_s21_memchr_not_found_in_first_n);

  suite_add_tcase(suite, tc_core);

  return suite;
}

// Функция для запуска тестов
int run_s21_memchr_test() {
  Suite *s = s21_memchr_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_s21_memchr_test(); }
