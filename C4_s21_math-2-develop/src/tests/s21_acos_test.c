#include "math_suites.h"

START_TEST(acos_test_1) {
  double num = 0.55;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_test_2) {
  double num = -0.99;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_test_3) {
  double num = -9;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_test_4) {
  double num = INFINITY;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_test_5) {
  double num = -INFINITY;
  long double orig_res = acos(num), our_res = s21_acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_test_6) {
  double num = NAN;
  long double orig_res = s21_acos(num), our_res = acos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(acos_test_7) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(acos_test_8) {
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(acos(NAN));
}
END_TEST

START_TEST(acos_test_9) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_10) {
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), S21_EPS_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0), acos(-0.0), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_11) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_12) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_13) {
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(3) / 2), acos(-sqrt(3) / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_14) {
  ck_assert_ldouble_eq_tol(s21_acos(-sqrt(2) / 2), acos(-sqrt(2) / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_15) {
  ck_assert_ldouble_eq_tol(s21_acos(-1 / 2), acos(-1 / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_16) {
  ck_assert_ldouble_eq_tol(s21_acos(1 / 2), acos(1 / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_17) {
  ck_assert_ldouble_eq_tol(s21_acos(2 / 2), acos(2 / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_18) {
  ck_assert_ldouble_eq_tol(s21_acos(sqrt(2) / 2), acos(sqrt(2) / 2),
                           S21_EPS_TEST);
}
END_TEST

START_TEST(acos_test_19) {
  ck_assert_ldouble_eq_tol(s21_acos(sqrt(3) / 2), acos(sqrt(3) / 2),
                           S21_EPS_TEST);
}
END_TEST

Suite *s21_acos_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_acos");
  tc = tcase_create("s21_acos_case");

  tcase_add_test(tc, acos_test_1);
  tcase_add_test(tc, acos_test_2);
  tcase_add_test(tc, acos_test_3);
  tcase_add_test(tc, acos_test_4);
  tcase_add_test(tc, acos_test_5);
  tcase_add_test(tc, acos_test_6);
  tcase_add_test(tc, acos_test_7);
  tcase_add_test(tc, acos_test_8);
  tcase_add_test(tc, acos_test_9);
  tcase_add_test(tc, acos_test_10);
  tcase_add_test(tc, acos_test_11);
  tcase_add_test(tc, acos_test_12);
  tcase_add_test(tc, acos_test_13);
  tcase_add_test(tc, acos_test_14);
  tcase_add_test(tc, acos_test_15);
  tcase_add_test(tc, acos_test_16);
  tcase_add_test(tc, acos_test_17);
  tcase_add_test(tc, acos_test_18);
  tcase_add_test(tc, acos_test_19);

  suite_add_tcase(s, tc);
  return s;
}