#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A == NULL) error = WRONG_MATR;
  if (error == OK) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return error;
}
