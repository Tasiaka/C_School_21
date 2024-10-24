#include "testiks.h"

START_TEST(test_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t C;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &B);
  s21_create_matrix(1, 1, &C);
  double A1[2][3] = {{2.0, 3.0, 5.0}};
  double B1[3][2] = {{1.0}, {3.0}, {5.0}};
  double C1[1][1] = {{36.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  for (int i = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      C.matrix[i][j] = C1[i][j];
    }
  }
  s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      ck_assert(result.matrix[i][j] == C.matrix[i][i]);
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
  matrix_t result;
  s21_create_matrix(9, 11, &A);
  ck_assert(s21_mult_matrix(NULL, &A, &result) == WRONG_MATR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_3) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(5, 15, &A);
  ck_assert(s21_mult_matrix(&A, NULL, &result) == WRONG_MATR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_4) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(5, 1, &A);
  s21_create_matrix(5, 1, &B);
  ck_assert(s21_mult_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  double A1[2][3] = {{2.0, 3.0, 5.0}, {-9.0, -8.0, -7.0}};
  double B1[3][2] = {{11.0, 22.0}, {33.0, 44.0}, {55.0, 66.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  A.matrix[1][1] = INFINITY;
  ck_assert(s21_mult_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  double A1[2][3] = {{2.0, 3.0, 5.0}, {-9.0, -8.0, -7.0}};
  double B1[3][2] = {{11.0, 22.0}, {33.0, 44.0}, {55.0, 66.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  A.matrix[0][0] = NAN;
  ck_assert(s21_mult_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_7) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  double A1[2][3] = {{2.0, 3.0, 5.0}, {-9.0, -8.0, -7.0}};
  double B1[3][2] = {{11.0, 22.0}, {33.0, 44.0}, {55.0, 66.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  B.matrix[0][0] = INFINITY;
  ck_assert(s21_mult_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_8) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  double A1[2][3] = {{2.0, 3.0, 5.0}, {-9.0, -8.0, -7.0}};
  double B1[3][2] = {{NAN, 22.0}, {33.0, 44.0}, {55.0, 66.0}};
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A1[i][j];
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = B1[i][j];
    }
  }
  B.matrix[0][0] = NAN;
  ck_assert(s21_mult_matrix(&A, &B, &result) == CALC_MISTAKE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *mult_matrix_t(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("\033[45m-=S21_MULT_MATRIX=-\033[0m");

  tc = tcase_create("mult matrix");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  suite_add_tcase(s, tc);

  return s;
}