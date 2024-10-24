#include "testiks.h"

START_TEST(test_1) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(10, 10, &matrix) == OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_2) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(-10, 10, &matrix) == WRONG_MATR);
}
END_TEST

START_TEST(test_3) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(10, -10, &matrix) == WRONG_MATR);
}
END_TEST

START_TEST(test_4) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(-10, -10, &matrix) == WRONG_MATR);
}
END_TEST

START_TEST(test_5) {
  matrix_t matrix;
  ck_assert(s21_create_matrix(0, 10, &matrix) == WRONG_MATR);
}
END_TEST

START_TEST(test_6) { ck_assert(s21_create_matrix(10, 10, NULL) == WRONG_MATR); }
END_TEST

Suite *create_matrix_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_CREATE=-\033[0m");

  tc = tcase_create("create matrix");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  suite_add_tcase(s, tc);

  return s;
}