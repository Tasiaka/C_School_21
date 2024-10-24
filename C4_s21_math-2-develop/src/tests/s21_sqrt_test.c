#include "math_suites.h"

START_TEST(sqrt_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sqrt_test_2) {
  double x = -1;
  ck_assert_ldouble_nan(s21_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(sqrt_test_3) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sqrt_test_4) {
  double x = 999999999999;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sqrt_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_nan(s21_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(sqrt_test_7) {
  double x = -DBL_MAX;
  ck_assert_ldouble_nan(s21_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(sqrt_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sqrt_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_nan(s21_sqrt(x));
  ck_assert_ldouble_nan(sqrt(x));
}
END_TEST

START_TEST(sqrt_test_10) {
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_nan(sqrt(NAN));
}
END_TEST

START_TEST(sqrt_test_11) {
  ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
  ck_assert_ldouble_infinite(sqrt(INFINITY));
}
END_TEST

START_TEST(sqrt_test_12) {
  ck_assert_ldouble_nan(s21_sqrt(-INFINITY));
  ck_assert_ldouble_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(sqrt_test_13) {
  double x = 10e+16;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sqrt_test_14) {
  double x = 100;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sqrt_test_15) {
  double x = 98765432.123;
  ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS_TEST);
}
END_TEST

Suite *s21_sqrt_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sqrt");

  tc = tcase_create("s21_sqrt_case");
  tcase_add_test(tc, sqrt_test_1);
  tcase_add_test(tc, sqrt_test_2);
  tcase_add_test(tc, sqrt_test_3);
  tcase_add_test(tc, sqrt_test_4);
  tcase_add_test(tc, sqrt_test_5);
  tcase_add_test(tc, sqrt_test_7);
  tcase_add_test(tc, sqrt_test_8);
  tcase_add_test(tc, sqrt_test_9);
  tcase_add_test(tc, sqrt_test_10);
  tcase_add_test(tc, sqrt_test_11);
  tcase_add_test(tc, sqrt_test_12);
  tcase_add_test(tc, sqrt_test_13);
  tcase_add_test(tc, sqrt_test_14);
  tcase_add_test(tc, sqrt_test_15);

  suite_add_tcase(s, tc);

  return s;
}