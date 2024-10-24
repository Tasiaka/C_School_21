#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  double B1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
      B.matrix[i][j] = B1[i][j];
    }
  }
  ck_assert(s21_eq_matrix(&A, &B) == SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_2) {
  matrix_t A;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 9.0}, {7.0, 8.0, 9.0}};
  double B1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
      B.matrix[i][j] = B1[i][j];
    }
  }
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 4, &B);
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  ck_assert(s21_eq_matrix(&A, &B) == SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_5) {
  matrix_t A;
  s21_create_matrix(1, 1, &A);
  ck_assert(s21_eq_matrix(&A, NULL) == FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_6) {
  matrix_t B;
  s21_create_matrix(1, 1, &B);
  ck_assert(s21_eq_matrix(NULL, &B) == FAILURE);
  s21_remove_matrix(&B);
}
END_TEST

Suite *eq_matrix_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_EQUAL=-\033[0m");

  tc = tcase_create("eq matrix");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  suite_add_tcase(s, tc);

  return s;
}