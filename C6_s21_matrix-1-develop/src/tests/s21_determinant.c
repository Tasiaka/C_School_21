#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  double det = 0.0;
  double expected_det = 18.0;
  int rows = 4, columns = 4;
  double A1[4][4] = {{3.0, -3.0, -5.0, 8.0},
                     {-3.0, 2.0, 4.0, -6},
                     {2.0, -5.0, -7.0, 5.0},
                     {-4.0, 3.0, 5.0, -6.0}};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_determinant(&A, &det);
  ck_assert(det == expected_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_2) {
  matrix_t A;
  double det = 0.0;
  double expected_det = -75.0;
  int rows = 2, columns = 2;
  double A1[2][2] = {{19.0, -123.0}, {-2.0, 9.0}};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_determinant(&A, &det);
  ck_assert(det == expected_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  double det = 0.0;
  double expected_det = 199.0;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 199.0;
  s21_determinant(&A, &det);
  ck_assert(det == expected_det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_5) {
  double det;
  ck_assert(s21_determinant(NULL, &det) == WRONG_MATR);
}
END_TEST

START_TEST(test_6) {
  matrix_t A;
  double det;
  int rows = 9, columns = 5;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_determinant(&A, &det) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_7) {
  matrix_t A;
  double det = 0.0;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[0][0] = INFINITY;
  ck_assert(s21_determinant(&A, &det) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_8) {
  matrix_t A;
  double det = 0.0;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[0][0] = NAN;
  ck_assert(s21_determinant(&A, &det) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_t(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[45m-=S21_DETERMINANT=-\033[0m");

  tc = tcase_create("determinant");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  suite_add_tcase(s, tc);

  return s;
}