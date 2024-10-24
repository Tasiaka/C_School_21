#ifndef MATRIX
#define MATRIX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Все операции (кроме сравнения матриц) должны возвращать результирующий код:
// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)
#define CALC_MISTAKE 2
#define WRONG_MATR 1
#define OK 0
// для сравнения
#define SUCCESS 1
#define FAILURE 0
#define TEN_IN_SEVEN 10000000

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int check_value_in_matrix(const matrix_t *A);

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void remove_column_row(matrix_t *A, matrix_t *small, int row, int column);

#endif