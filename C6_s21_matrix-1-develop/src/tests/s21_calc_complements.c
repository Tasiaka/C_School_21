#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t result;
  matrix_t B;
  int rows = 2, columns = 2;
  double A1[3][3] = {{9.0, -12.0}, {223.0, -11.0}};

  double B1[3][3] = {{-11.0, -223.0}, {12.0, 9.0}};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_calc_complements(&A, &result);
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
  matrix_t B;
  int rows = 3;
  int columns = 3;
  double matrix_A_values[3][3] = {
      {1.0, 2.0, 3.0}, {0.0, 4.0, 2.0}, {5.0, 2.0, 1.0}};
  double matrix_B1[3][3] = {
      {0.0, 10.0, -20.0}, {4.0, -14.0, 8.0}, {-8.0, -2.0, 4.0}};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = matrix_A_values[i][j];
      B.matrix[i][j] = matrix_B1[i][j];
    }
  }
  s21_calc_complements(&A, &result);
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

START_TEST(test_3) {
  matrix_t A;
  matrix_t result;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[1][1] = NAN;
  ck_assert(s21_calc_complements(&A, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t result;
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  A.matrix[1][1] = INFINITY;
  ck_assert(s21_calc_complements(&A, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_5) {
  matrix_t A;
  matrix_t result;
  int rows = 7;
  int columns = 2;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_calc_complements(&A, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_6) {
  matrix_t result;
  ck_assert(s21_calc_complements(NULL, &result) == WRONG_MATR);
}
END_TEST

Suite *calc_complements_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");

  tc = tcase_create("calc complements");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  suite_add_tcase(s, tc);

  return s;
}