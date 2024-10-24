#include "math_suites.h"

START_TEST(tan_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_4) {
  double x = 99999999;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_5) {
  double x = -99999999;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_8) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_9) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_10) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tan(NAN));
}
END_TEST

START_TEST(tan_test_11) {
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tan(INFINITY));
}
END_TEST

START_TEST(tan_test_12) {
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tan(-INFINITY));
}
END_TEST

START_TEST(tan_test_13) {
  double x = S21_PI_2;
  ck_assert_ldouble_infinite(s21_tan(x));
}
END_TEST

START_TEST(tan_test_14) {
  double x = S21_PI_2 / 2;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_15) {
  double x = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_16) {
  double x = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_17) {
  double x = 4456.6534564567;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_18) {
  double x = -3456.6534564567;
  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS_TEST);
}
END_TEST

START_TEST(tan_test_19) {
  double x = -S21_PI_2;
  ck_assert_ldouble_infinite(s21_tan(x));
}
END_TEST

Suite *s21_tan_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_tan");

  tc = tcase_create("s21_tan_case");
  tcase_add_test(tc, tan_test_1);
  tcase_add_test(tc, tan_test_2);
  tcase_add_test(tc, tan_test_3);
  tcase_add_test(tc, tan_test_4);
  tcase_add_test(tc, tan_test_5);
  tcase_add_test(tc, tan_test_8);
  tcase_add_test(tc, tan_test_9);
  tcase_add_test(tc, tan_test_10);
  tcase_add_test(tc, tan_test_11);
  tcase_add_test(tc, tan_test_13);
  tcase_add_test(tc, tan_test_14);
  tcase_add_test(tc, tan_test_15);
  tcase_add_test(tc, tan_test_16);
  tcase_add_test(tc, tan_test_17);
  tcase_add_test(tc, tan_test_18);
  tcase_add_test(tc, tan_test_19);
  tcase_add_test(tc, tan_test_12);

  suite_add_tcase(s, tc);

  return s;
}