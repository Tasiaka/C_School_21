#include "math_suites.h"

START_TEST(sin_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_4) {
  double x = 99999999;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_5) {
  double x = -99999999;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_6) {
  double x = -0.9999999999;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_7) {
  double x = 0.9999999999;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_10) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_11) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(sin_test_12) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sin(NAN));
}
END_TEST

START_TEST(sin_test_13) {
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sin(INFINITY));
}
END_TEST

START_TEST(sin_test_14) {
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sin(-INFINITY));
  // ck_assert_ldouble_eq_tol(s21_sin(-INFINITY), sin(-INFINITY), S21_EPS_TEST);
}
END_TEST

Suite *s21_sin_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_sin");

  tc = tcase_create("s21_sin_case");
  tcase_add_test(tc, sin_test_1);
  tcase_add_test(tc, sin_test_2);
  tcase_add_test(tc, sin_test_3);
  tcase_add_test(tc, sin_test_4);
  tcase_add_test(tc, sin_test_5);
  tcase_add_test(tc, sin_test_6);
  tcase_add_test(tc, sin_test_7);
  tcase_add_test(tc, sin_test_10);
  tcase_add_test(tc, sin_test_11);
  tcase_add_test(tc, sin_test_12);
  tcase_add_test(tc, sin_test_13);
  tcase_add_test(tc, sin_test_14);

  suite_add_tcase(s, tc);

  return s;
}