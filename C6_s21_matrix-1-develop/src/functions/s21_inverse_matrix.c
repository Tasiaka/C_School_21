#include "../s21_matrix.h"

// Inverse of the matrix
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL) return WRONG_MATR;
  if (A->rows != A->columns || check_value_in_matrix(A) == 1)
    return CALC_MISTAKE;
  int error = OK;
  double det = 0.0;
  s21_determinant(A, &det);
  if (det == 0) error = CALC_MISTAKE;

  if (error == OK) {
    matrix_t A_small;
    matrix_t A_transp;
    s21_create_matrix(A->rows, A->columns, result);
    s21_calc_complements(A, &A_small);
    s21_transpose(&A_small, &A_transp);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A_transp.matrix[i][j] / det;
      }
    }
    s21_remove_matrix(&A_small);
    s21_remove_matrix(&A_transp);
  }
  return error;
}
