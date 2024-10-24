// void *insert(const char *src, const char *str, size_t start_index)
// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL

#include <check.h>

#include "../s21_string.h"  // Замените на имя вашего заголовочного файла
#include "stdlib.h"
#include "string.h"

START_TEST(insert_test1) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test2) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test3) {
  char str[] = "";
  char src[] = "";
  size_t index = 100;
  //  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test4) {
  char *src = NULL;
  char *str = NULL;
  size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test5) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_str_null) {
  char *str = NULL;
  char src[] = "Space  ";
  size_t index = 6;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_null(got);
  if (got) free(got);
}
END_TEST

Suite *suite_insert(void) {
  Suite *suite = suite_create("suite_insert");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, insert_test1);
  tcase_add_test(tc_core, insert_test2);
  tcase_add_test(tc_core, insert_test3);
  tcase_add_test(tc_core, insert_test4);
  tcase_add_test(tc_core, insert_test5);
  tcase_add_test(tc_core, insert_str_null);

  suite_add_tcase(suite, tc_core);
  return suite;
}

int main(void) {
  Suite *suite = suite_insert();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
