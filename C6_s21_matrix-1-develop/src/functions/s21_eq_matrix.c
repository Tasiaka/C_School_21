#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (!(A != NULL && B != NULL && A->rows == B->rows && A->rows > 0 &&
        A->columns > 0 && A->columns == B->columns))
    error = FAILURE;
  if (error == SUCCESS) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double different = (int)(A->matrix[i][j] * TEN_IN_SEVEN) -
                           (int)(B->matrix[i][j] * TEN_IN_SEVEN);
        if (different != 0) error = FAILURE;
      }
    }
  }
  return error;
}

// int main()
// {
//       matrix_t A;
//   matrix_t B;
//   int rows = 3, columns = 3;
//   s21_create_matrix(-4, 4, &A);
//   s21_create_matrix(-4, 4, &B);
//   printf("%d",s21_eq_matrix(&A, &B) );
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&B);
// }
// // int main()
// {
//     matrix_t *A;
//     s21_create_matrix(2,2, A);
//     A->matrix[0][0] = 5.0;
//     A->matrix[0][1] = 9.0;
//     A->matrix[0][1] = 33.3;
//     A->matrix[1][1] = 16.5;
//     matrix_t *B;
//     s21_create_matrix(2,2, B);
//     B->matrix[0][0] = 5.0;
//     B->matrix[0][1] = 9.0;
//     B->matrix[0][1] = 33.3;
//     B->matrix[1][1] = 16.5;
//     int k = s21_eq_matrix(A,B);
//     printf("%d", k);
//     return 0;
// }