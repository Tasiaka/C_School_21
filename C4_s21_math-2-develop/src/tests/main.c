#include "math_suites.h"

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  // failed = srunner_ntests_failed(sr);
  srunner_free(sr);
}

void run_tests() {
  Suite *test_cases[] = {
      s21_exp_suite(),   s21_abs_suite(),  s21_acos_suite(), s21_asin_suite(),
      s21_atan_suite(),  s21_ceil_suite(), s21_cos_suite(),  s21_fabs_suite(),
      s21_floor_suite(), s21_fmod_suite(), s21_log_suite(),  s21_pow_suite(),
      s21_sin_suite(),   s21_sqrt_suite(), s21_tan_suite(),  NULL};
  for (Suite **current_testcase = test_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}

int main() {
  run_tests();
  return 0;
}