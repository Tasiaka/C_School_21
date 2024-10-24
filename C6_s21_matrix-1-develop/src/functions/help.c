// #include <stdio.h>
#include "../s21_matrix.h"

// 1 - есть ошибка, 0 - ошибки нет
int check_value_in_matrix(const matrix_t *A) {
  int error = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        error = 1;
      }
    }
  }
  return error;
}

void remove_column_row(matrix_t *A, matrix_t *small, int rows, int column) {
  int row = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == rows) continue;
    int col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      // {
      small->matrix[row][col] = A->matrix[i][j];
      col++;
      // }
    }
    row++;
  }
}

// int main()
// {
//     matrix_t *A;
//     s21_create_matrix(2,2, A);
//     A->matrix[0][0] = INFINITY;
//     A->matrix[0][1] = 9.0;
//     A->matrix[0][1] = 33.3;
//     A->matrix[1][1] = 16.5;
//     int k = correct_matrix(A);
//     printf("%d", k);
//     return 0;
// }
