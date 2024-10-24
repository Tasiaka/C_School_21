#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (A == NULL)
    error = WRONG_MATR;
  else if (check_value_in_matrix(A) || isinf(number) || isnan(number))
    error = CALC_MISTAKE;
  if (error == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}
