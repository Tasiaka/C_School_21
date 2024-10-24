#include "math_suites.h"

START_TEST(atan_test_1) {
  ck_assert_ldouble_eq_tol(s21_atan(-15.01), atan(-15.01), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_2) {
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_test_3) {
  ck_assert_ldouble_eq_tol(-9999999999, -9999999999, S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_4) {
  ck_assert_ldouble_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_ldouble_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

START_TEST(atan_test_5) {
  double num = NAN;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_test_6) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), (S21_PI / 2.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(INFINITY), (S21_PI / 2.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan((-INFINITY)), ((S21_PI) / -2.0),
                           S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), ((S21_PI) / -2.0), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_7) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(atan_test_8) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-1.1), atan(-1.1), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_9) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_10) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_11) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_12) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_13) {
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_14) {
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_15) {
  ck_assert_ldouble_eq_tol(s21_atan(2 / 2), atan(2 / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_16) {
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_17) {
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_18) {
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_19) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_20) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_21) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_22) { ck_assert_float_nan(s21_atan(S21_NAN)); }
END_TEST

START_TEST(atan_test_23) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_PI / 2), atan(S21_PI / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(atan_test_24) {
  ck_assert_ldouble_eq_tol(s21_atan(-S21_PI / 2), atan(-S21_PI / 2),
                           S21_EPS_TEST);
}
END_TEST

Suite *s21_atan_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_atan");
  tc = tcase_create("s21_atan_case");

  tcase_add_test(tc, atan_test_1);
  tcase_add_test(tc, atan_test_2);
  tcase_add_test(tc, atan_test_3);
  tcase_add_test(tc, atan_test_4);
  tcase_add_test(tc, atan_test_5);
  tcase_add_test(tc, atan_test_6);
  tcase_add_test(tc, atan_test_7);
  tcase_add_test(tc, atan_test_8);
  tcase_add_test(tc, atan_test_9);
  tcase_add_test(tc, atan_test_10);
  tcase_add_test(tc, atan_test_11);
  tcase_add_test(tc, atan_test_12);
  tcase_add_test(tc, atan_test_13);
  tcase_add_test(tc, atan_test_14);
  tcase_add_test(tc, atan_test_15);
  tcase_add_test(tc, atan_test_16);
  tcase_add_test(tc, atan_test_17);
  tcase_add_test(tc, atan_test_18);
  tcase_add_test(tc, atan_test_19);
  tcase_add_test(tc, atan_test_20);
  tcase_add_test(tc, atan_test_21);
  tcase_add_test(tc, atan_test_22);
  tcase_add_test(tc, atan_test_23);
  tcase_add_test(tc, atan_test_24);

  suite_add_tcase(s, tc);
  return s;
}