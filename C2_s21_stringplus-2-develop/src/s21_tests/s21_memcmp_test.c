#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_memcmp_1) {
  const char *str1 = "abcda";
  const char *str2 = "abcdz";
  size_t n = 5;

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  const char *str1 = "abcdt";
  const char *str2 = "abcde";
  size_t n = 5;

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест на сравнение двух строк, где первая строка меньше второй
START_TEST(test_s21_memcmp_less) {
  const char *str1 = "abcd";
  const char *str2 = "abcde";
  size_t n = 4;

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест на сравнение двух строк, где первая строка равна второй
START_TEST(test_s21_memcmp_equal) {
  const char *str1 = "abcd";
  const char *str2 = "abcd";
  size_t n = 4;

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Тест на сравнение двух строк, где первая строка больше второй
START_TEST(test_s21_memcmp_greater) {
  const char *str1 = "abcde";
  const char *str2 = "abcd";
  size_t n = 4;

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_std = memcmp(str1, str2, n);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

// Функция для создания и запуска тестовой сьюиты
Suite *s21_memcmp_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_memcmp");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcmp_less);
  tcase_add_test(tc_core, test_s21_memcmp_equal);
  tcase_add_test(tc_core, test_s21_memcmp_greater);
  tcase_add_test(tc_core, test_s21_memcmp_1);
  tcase_add_test(tc_core, test_s21_memcmp_2);

  suite_add_tcase(suite, tc_core);

  return suite;
}

// Функция для запуска тестов
int run_s21_memcmp_test() {
  Suite *s = s21_memcmp_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_s21_memcmp_test(); }
