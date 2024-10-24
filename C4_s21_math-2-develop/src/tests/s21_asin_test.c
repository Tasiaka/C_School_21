#include "math_suites.h"

START_TEST(asin_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_4) {
  double x = 999999999999;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_5) {
  double x = -999999999999;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_6) {
  double x = DBL_MAX;
  ck_assert_ldouble_nan(s21_asin(x));
  ck_assert_ldouble_nan(asin(x));
}
END_TEST

START_TEST(asin_test_7) {
  ck_assert_ldouble_nan(s21_asin(-DBL_MAX));
  ck_assert_ldouble_nan(asin(-DBL_MAX));
}
END_TEST

START_TEST(asin_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_10) {
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(asin(NAN));
}
END_TEST

START_TEST(asin_test_11) {
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(asin(INFINITY));
}
END_TEST

START_TEST(asin_test_12) {
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
  ck_assert_ldouble_nan(asin(-INFINITY));
}
END_TEST

START_TEST(asin_test_13) {
  double x = -0.9999;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_14) {
  double x = -0.7559;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_15) {
  double x = -0.45987;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_16) {
  double x = -0.11111;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_17) {
  double x = 0.11111;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_18) {
  double x = 0.56789;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

START_TEST(asin_test_19) {
  double x = 0.12345567;
  ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), S21_EPS_TEST);
}
END_TEST

Suite *s21_asin_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_asin");

  tc = tcase_create("s21_asin_case");
  tcase_add_test(tc, asin_test_1);
  tcase_add_test(tc, asin_test_2);
  tcase_add_test(tc, asin_test_3);
  tcase_add_test(tc, asin_test_4);
  tcase_add_test(tc, asin_test_5);
  tcase_add_test(tc, asin_test_6);
  tcase_add_test(tc, asin_test_7);
  tcase_add_test(tc, asin_test_8);
  tcase_add_test(tc, asin_test_9);
  tcase_add_test(tc, asin_test_10);
  tcase_add_test(tc, asin_test_11);
  tcase_add_test(tc, asin_test_12);
  tcase_add_test(tc, asin_test_13);
  tcase_add_test(tc, asin_test_14);
  tcase_add_test(tc, asin_test_15);
  tcase_add_test(tc, asin_test_16);
  tcase_add_test(tc, asin_test_17);
  tcase_add_test(tc, asin_test_18);
  tcase_add_test(tc, asin_test_19);

  suite_add_tcase(s, tc);

  return s;
}