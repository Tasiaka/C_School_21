#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  double num = -2.0;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_create_matrix(rows, columns, &B);
  double B1[3][3] = {
      {-2.0, -4.0, -6.0}, {-8.0, -10.0, -12.0}, {-14.0, -16.0, -18.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  ck_assert(s21_mult_number(&A, num, &result) == OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert(B.matrix[i][j] == result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_2) {
  matrix_t result;
  double num = 2.0;
  ck_assert(s21_mult_number(NULL, num, &result) == WRONG_MATR);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  double num = 12345678.0;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[0][0] = INFINITY;
  ck_assert(s21_mult_number(&A, num, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  double num = 12345678.0;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[0][0] = NAN;
  ck_assert(s21_mult_number(&A, num, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_5) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  double num = INFINITY;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  ck_assert(s21_mult_number(&A, num, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_6) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  double num = NAN;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  ck_assert(s21_mult_number(&A, num, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

Suite *mult_number_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_MULT_NUMBER=-\033[0m");

  tc = tcase_create("mult number");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  suite_add_tcase(s, tc);

  return s;
}