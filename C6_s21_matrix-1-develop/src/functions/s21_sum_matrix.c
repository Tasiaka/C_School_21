#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (A == NULL || B == NULL)
    error = WRONG_MATR;
  else if (!(A->rows == B->rows && A->columns == B->columns) ||
           check_value_in_matrix(A) || check_value_in_matrix(B))
    error = CALC_MISTAKE;
  if (error == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return error;
}