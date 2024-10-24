#include "math_suites.h"

START_TEST(cos_1) {
  double num = 0.55;
  long double orig_res = s21_cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_2) {
  double num = -0.999999;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_3) {
  double num = 628;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_4) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(cos_5) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(cos_6) {
  double num = NAN;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_7) {
  double num = INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_8) {
  double num = -INFINITY;
  long double orig_res = cos(num), our_res = s21_cos(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_9) {
  double x = 0;
  ck_assert_double_eq_tol(s21_cos(x), cos(x), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_10) {
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
  ck_assert_ldouble_nan(cos(-INFINITY));
}
END_TEST

START_TEST(cos_11) {
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(cos(INFINITY));
}
END_TEST

START_TEST(cos_12) {
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(cos(NAN));
}
END_TEST

START_TEST(cos_13) {
  ck_assert_double_eq_tol(s21_cos(0.0), cos(0.0), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_14) {
  ck_assert_double_eq_tol(s21_cos(S21_PI / 4), cos(S21_PI / 4), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_15) {
  ck_assert_double_eq_tol(s21_cos(S21_PI / 6), cos(S21_PI / 6), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_16) {
  ck_assert_double_eq_tol(s21_cos(S21_PI / 3), cos(S21_PI / 3), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_17) {
  ck_assert_double_eq_tol(s21_cos(S21_PI / 2), cos(S21_PI / 2), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_18) {
  ck_assert_double_eq_tol(s21_cos(3 * S21_PI / 2), cos(3 * S21_PI / 2),
                          S21_EPS_TEST);
}
END_TEST

START_TEST(cos_19) {
  ck_assert_double_eq_tol(s21_cos(2 * S21_PI), cos(2 * S21_PI), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_20) {
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cos(174.532925199433),
                          S21_EPS_TEST);
}
END_TEST

START_TEST(cos_21) {
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cos(-174.532925199433),
                          S21_EPS_TEST);
}
END_TEST

START_TEST(cos_22) {
  ck_assert_double_eq_tol(s21_cos(99999999), cos(99999999), S21_EPS_TEST);
}
END_TEST

START_TEST(cos_23) {
  ck_assert_double_eq_tol(s21_cos(-99999999), cos(-99999999), S21_EPS_TEST);
}
END_TEST

Suite *s21_cos_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_cos");
  tc = tcase_create("case_cos");

  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_2);
  tcase_add_test(tc, cos_3);
  tcase_add_test(tc, cos_4);
  tcase_add_test(tc, cos_5);
  tcase_add_test(tc, cos_6);
  tcase_add_test(tc, cos_7);
  tcase_add_test(tc, cos_8);
  tcase_add_test(tc, cos_9);
  tcase_add_test(tc, cos_10);
  tcase_add_test(tc, cos_11);
  tcase_add_test(tc, cos_12);
  tcase_add_test(tc, cos_13);
  tcase_add_test(tc, cos_14);
  tcase_add_test(tc, cos_15);
  tcase_add_test(tc, cos_16);
  tcase_add_test(tc, cos_17);
  tcase_add_test(tc, cos_18);
  tcase_add_test(tc, cos_19);
  tcase_add_test(tc, cos_20);
  tcase_add_test(tc, cos_21);
  tcase_add_test(tc, cos_22);
  tcase_add_test(tc, cos_23);

  suite_add_tcase(s, tc);
  return s;
}