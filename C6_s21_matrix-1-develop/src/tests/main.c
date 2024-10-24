#include "testiks.h"

// // Assigning values to matrix elements
// void assigning_values_to_matrix(matrix_t *A, double num) {
//   for (int i = 0; i < A->rows; i++) {
//     for (int j = 0; j < A->columns; j++) {
//       A->matrix[i][j] = num;
//     }
//   }
// }

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests() {
  Suite *list_cases[] = {
      calc_complements_t(), create_matrix_t(),  determinant_t(),
      eq_matrix_t(),        inverse_matrix_t(), mult_matrix_t(),
      mult_number_t(),      remove_matrix_t(),  sub_matrix_t(),
      sum_matrix_t(),       transpose_t(),      NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

int main(void) {
  run_tests();
  return 0;
}