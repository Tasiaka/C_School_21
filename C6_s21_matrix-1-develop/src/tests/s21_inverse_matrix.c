#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t result;
  matrix_t B;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  double A1[3][3] = {{7.0, 2.0, 5.0}, {4.0, 6.0, 3.0}, {-3.0, 5.0, -2.0}};
  double B2[3][3] = {
      {27.0, -29.0, 24.0}, {1.0, -1.0, 1.0}, {-38.0, 41.0, -34.0}};

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
      B.matrix[i][j] = B2[i][j];
    }
  }
  s21_inverse_matrix(&A, &result);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      ck_assert(B.matrix[i][j] == result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_2) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{7, 2, 5}, {4, 6, 3}, {-3, 5, -2}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  ck_assert(s21_inverse_matrix(&A, &result) == OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{7.0, 2.0, 5.0}, {4.0, 6.0, 3.0}, {-3.0, 5.0, -2.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[0][0] = INFINITY;
  ck_assert(s21_inverse_matrix(&A, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{7.0, 2.0, 5.0}, {4.0, 6.0, 3.0}, {-3.0, 5.0, -2.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[0][0] = NAN;
  ck_assert(s21_inverse_matrix(&A, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}

START_TEST(test_5) {
  matrix_t result;
  ck_assert(s21_inverse_matrix(NULL, &result) == WRONG_MATR);
}
END_TEST

START_TEST(test_6) {
  matrix_t A;
  matrix_t result;
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_inverse_matrix(&A, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

Suite *inverse_matrix_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_INVERSE=-\033[0m");

  tc = tcase_create("inverse matrix");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  suite_add_tcase(s, tc);

  return s;
}