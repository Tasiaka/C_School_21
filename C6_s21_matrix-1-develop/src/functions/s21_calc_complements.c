
#include "./../s21_matrix.h"

// Minor of matrix and matrix of algebraic complements
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A == NULL) return WRONG_MATR;
  if (A->rows != A->columns || check_value_in_matrix(A) == 1)
    return CALC_MISTAKE;
  s21_create_matrix(A->rows, A->columns, result);
  matrix_t A_small;
  s21_create_matrix(A->rows - 1, A->columns - 1, &A_small);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      remove_column_row(A, &A_small, i, j);
      double small_det = 0.0;
      s21_determinant(&A_small, &small_det);
      result->matrix[i][j] = pow(-1, i + j) * small_det;
    }
  }
  s21_remove_matrix(&A_small);
  return OK;
}