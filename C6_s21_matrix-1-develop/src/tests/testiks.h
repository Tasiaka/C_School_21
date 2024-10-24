// Проверяемая точность дробной части - максимум 6 знаков после запятой.
#ifndef MATRIX_T
#define MATRIX_T

#include <check.h>

#include "../s21_matrix.h"

Suite *calc_complements_t(void);
Suite *create_matrix_t(void);
Suite *determinant_t(void);
Suite *eq_matrix_t(void);
Suite *inverse_matrix_t(void);
Suite *mult_number_t(void);
Suite *mult_matrix_t(void);
Suite *remove_matrix_t(void);
Suite *sub_matrix_t(void);
Suite *sum_matrix_t(void);
Suite *transpose_t(void);

#endif