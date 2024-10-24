#include "testiks.h"

START_TEST(test_1) {
  matrix_t matrix;
  s21_create_matrix(1, 100, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert(matrix.matrix == NULL);
  s21_remove_matrix(NULL);
}
END_TEST

Suite *remove_matrix_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_REMOVE=-\033[0m");

  tc = tcase_create("remove matrix");

  tcase_add_test(tc, test_1);

  suite_add_tcase(s, tc);

  return s;
}