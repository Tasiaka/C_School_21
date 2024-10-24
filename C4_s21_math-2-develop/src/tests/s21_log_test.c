#include "math_suites.h"

START_TEST(log_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), S21_EPS_TEST);
}
END_TEST

START_TEST(log_test_2) {
  double x = -1;
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
  // ck_assert_ldouble_eq_tol(s21_log(x), log(x), S21_EPS_TEST);
}
END_TEST

START_TEST(log_test_3) {
  double x = 0;
  ck_assert_ldouble_infinite(log(x));
  ck_assert_ldouble_infinite(s21_log(x));
}
END_TEST

START_TEST(log_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS_TEST);
  //   ck_assert_ldouble_infinite(s21_log(x));
  //   ck_assert_ldouble_infinite(log(x));
}
END_TEST

START_TEST(log_test_5) {
  double x = -999999999999;
  // ck_assert_ldouble_eq_tol(s21_log(x), log(x), S21_EPS_TEST);
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(log_test_6) {
  double x = S21_DBL_MAX;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS_TEST);
  // ck_assert_ldouble_infinite(s21_log(x));
  // ck_assert_ldouble_infinite(log(x));
}
END_TEST

START_TEST(log_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST

START_TEST(log_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_log(x), log(x), S21_EPS_TEST);
}
END_TEST

START_TEST(log_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
  // ck_assert_ldouble_eq_tol(s21_log(x), log(x), S21_EPS_TEST);
}
END_TEST

START_TEST(log_test_10) {
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_test_11) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));
}
END_TEST

START_TEST(log_test_12) {
  double x = -INFINITY;
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
  // ck_assert_ldouble_eq_tol(s21_log(-INFINITY), log(-INFINITY), S21_EPS_TEST);
}
END_TEST

Suite *s21_log_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_log");

  tc = tcase_create("s21_log_case");
  tcase_add_test(tc, log_test_1);
  tcase_add_test(tc, log_test_2);
  tcase_add_test(tc, log_test_3);
  tcase_add_test(tc, log_test_4);
  tcase_add_test(tc, log_test_5);
  tcase_add_test(tc, log_test_6);
  tcase_add_test(tc, log_test_7);
  tcase_add_test(tc, log_test_8);
  tcase_add_test(tc, log_test_9);
  tcase_add_test(tc, log_test_10);
  tcase_add_test(tc, log_test_11);
  tcase_add_test(tc, log_test_12);

  suite_add_tcase(s, tc);

  return s;
}