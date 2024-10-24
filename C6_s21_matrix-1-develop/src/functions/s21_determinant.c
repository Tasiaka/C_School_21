#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (A == NULL) return WRONG_MATR;
  if ((A->rows != A->columns || check_value_in_matrix(A) == 1))
    error = CALC_MISTAKE;
  if (A->rows == 1)
    *result = A->matrix[0][0];
  else if (A->rows == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  else if (A->rows > 2) {
    *result = 0.0;
    for (int k = 0; k < A->rows; k++) {
      matrix_t A_small;
      s21_create_matrix(A->rows - 1, A->columns, &A_small);
      remove_column_row(A, &A_small, 0, k);
      double deter_A_small = 0.0;
      s21_determinant(&A_small, &deter_A_small);
      *result += pow(-1, k) * A->matrix[0][k] * deter_A_small;
      s21_remove_matrix(&A_small);
    }
  }
  return error;
}

// int main()
// {
//   matrix_t A;
//   double det = 0.0;
// double expected_det = -1.0;
//   int rows = 3, columns = 3;

//   double matrix_values[3][3] = {
//       {2.0, 5.0, 7.0}, {6.0, 3.0, 4.0}, {5.0, -2.0, -3.0}};

//   s21_create_matrix(rows, columns, &A);

//   for (int i = 0; i < A.rows; i++) {
//     for (int j = 0; j < A.columns; j++) {
//       A.matrix[i][j] = matrix_values[i][j];
//     }
//   }
//   s21_determinant(&A, &det);
//     printf("%f", det);
//   s21_remove_matrix(&A);
// // }
// int main()
// {
//     matrix_t *A;
//     s21_create_matrix(4,4, A);
//     A->matrix[0][0] = 3;     A->matrix[0][1] = -3;       A->matrix[0][2] =
//     -5;       A->matrix[0][3] = 8; A->matrix[1][0] = -3;    A->matrix[1][1] =
//     2;        A->matrix[1][2] = 4;        A->matrix[1][3] = -6;
//     A->matrix[2][0] = 2;     A->matrix[2][1] = -5;       A->matrix[2][2] =
//     -7;       A->matrix[2][3] = 5; A->matrix[3][0] = -4;    A->matrix[3][1] =
//     3;        A->matrix[3][2] = 5;        A->matrix[3][3] = -6;

//     double k = 1.0;
//     s21_determinant(A, &k);
//     printf("%f\n", k);
//     matrix_t A_small;
//     s21_create_matrix(A->rows-1,A->columns,&A_small);
//     remove_column_row(A, &A_small, 1);
//     return 0;
// }