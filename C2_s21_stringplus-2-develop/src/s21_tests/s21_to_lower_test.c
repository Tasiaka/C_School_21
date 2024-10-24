// void *to_lower(const char *str)
// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL

#include <check.h>

#include "../s21_string.h"  // Замените на имя вашего заголовочного файла
#include "string.h"

START_TEST(to_lower_test1) {
  char str[] = "ShLePa V TaZ1Ke?";
  char expected[] = "shlepa v taz1ke?";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test3) {
  char str[] = "SPACE created";
  char expected[] = "space created";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *s21_to_loser_suite(void) {
  Suite *suite = suite_create("s21_to_loser");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, to_lower_test1);
  tcase_add_test(tc_core, to_lower_test2);
  tcase_add_test(tc_core, to_lower_test3);
  tcase_add_test(tc_core, to_lower_test4);
  tcase_add_test(tc_core, to_lower_test5);
  suite_add_tcase(suite, tc_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_to_loser_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}