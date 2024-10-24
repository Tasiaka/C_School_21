#include <check.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_s21_strcspn_no_common_chars) {
  const char *str1 = "abcdef";
  const char *str2 = "123456";

  size_t result = s21_strcspn(str1, str2);
  size_t res = strcspn(str1, str2);

  ck_assert_int_eq(result, res);  // Все символы из str1 отсутствуют в str2
}
END_TEST

START_TEST(test_s21_strcspn_some_common_chars) {
  const char *str1 = "abcdef";
  const char *str2 = "def456";

  size_t result = s21_strcspn(str1, str2);
  size_t result1 = strcspn(str1, str2);

  ck_assert_int_eq(result,
                   result1);  // Начальный сегмент без общих символов - "abc"
}
END_TEST

START_TEST(test_s21_strcspn_all_common_chars) {
  const char *str1 = "abcdef";
  const char *str2 = "abcdef";

  size_t result = s21_strcspn(str1, str2);
  size_t result1 = strcspn(str1, str2);

  ck_assert_int_eq(
      result,
      result1);  // Начальный сегмент полностью общий - пустая строка
}
END_TEST

START_TEST(test_s21_strcspn_empty_str2) {
  const char *str1 = "abcdef";
  const char *str2 = "";

  size_t result = s21_strcspn(str1, str2);
  size_t result1 = strcspn(str1, str2);

  ck_assert_int_eq(result,
                   result1);  // Все символы из str1 отсутствуют в пустой str2
}

Suite *strcspn_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strcspn");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strcspn_no_common_chars);
  tcase_add_test(tc_core, test_s21_strcspn_some_common_chars);
  tcase_add_test(tc_core, test_s21_strcspn_all_common_chars);
  tcase_add_test(tc_core, test_s21_strcspn_empty_str2);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int run_strcspn_test() {
  Suite *s = strcspn_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strcspn_test(); }
