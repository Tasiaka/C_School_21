#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t C;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double A1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  s21_create_matrix(rows, columns, &B);
  double B1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_create_matrix(rows, columns, &C);
  double C1[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
  for (int i = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      C.matrix[i][j] = C1[i][j];
    }
  }

  s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert(result.matrix[i][j] == C.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert(s21_sub_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(5, 1, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert(s21_sub_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = INFINITY;
  ck_assert(s21_sub_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = INFINITY;
  ck_assert(s21_sub_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = NAN;
  ck_assert(s21_sub_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_7) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.matrix[0][0] = NAN;
  ck_assert(s21_sub_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_8) {
  matrix_t A;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  ck_assert(s21_sub_matrix(&A, NULL, &result) == WRONG_MATR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_9) {
  matrix_t B;
  matrix_t result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &B);
  ck_assert(s21_sub_matrix(NULL, &B, &result) == WRONG_MATR);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_10) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t C;
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
  double B1[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  s21_create_matrix(rows, columns, &C);
  double C1[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
  for (int i = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      C.matrix[i][j] = C1[i][j];
    }
  }

  s21_sub_matrix(&C, &B, &result);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert(result.matrix[i][j] == A.matrix[i][j]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&C);
}
END_TEST

Suite *sub_matrix_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_SUB=-\033[0m");

  tc = tcase_create("sub matrix");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  suite_add_tcase(s, tc);

  return s;
}