#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_create_matrix(rows, columns, &B);
  double B1[3][3] = {{1.0, 4.0, 7.0}, {2.0, 5.0, 8.0}, {3.0, 6.0, 9.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_transpose(&A, &result);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert(result.matrix[i][j] == B.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_2) {
  matrix_t result;
  ck_assert(s21_transpose(NULL, &result) == WRONG_MATR);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {
      {-1.0, -2.0, -3.0}, {-4.0, -5.0, -6.0}, {-7.0, -8.0, -9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_create_matrix(rows, columns, &B);
  double B1[3][3] = {
      {-1.0, -4.0, -7.0}, {-2.0, -5.0, -8.0}, {-3.0, -6.0, -9.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_transpose(&A, &result);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert(result.matrix[i][j] == B.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(2, columns, &A);
  double A1[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_create_matrix(rows, 2, &B);
  double B1[3][3] = {{1.0, 4.0}, {2.0, 5.0}, {3.0, 6.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_transpose(&A, &result);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert(result.matrix[i][j] == B.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(1, 4, &A);
  double A1[1][4] = {{1.0, 2.0, 3.0, 4.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_create_matrix(4, 1, &B);
  double B1[4][1] = {{1.0}, {2.0}, {3.0}, {4.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_transpose(&A, &result);
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      ck_assert(result.matrix[i][j] == B.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *transpose_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_TRANSPOSE=-\033[0m");

  tc = tcase_create("transpose");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  suite_add_tcase(s, tc);

  return s;
}