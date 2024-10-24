#include "math_suites.h"

START_TEST(fabs_test_1) {
  ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001));
}
END_TEST

START_TEST(fabs_test_2) {
  ck_assert_ldouble_eq(s21_fabs(-21.000345), fabs(-21.000345));
}
END_TEST

START_TEST(fabs_test_3) {
  ck_assert_ldouble_eq(s21_fabs(-2147483600.543), fabs(-2147483600.543));
}
END_TEST

START_TEST(fabs_test_4) {
  ck_assert_ldouble_eq(s21_fabs(2147483600.4857), fabs(2147483600.4857));
}
END_TEST

START_TEST(fabs_test_5) {
  double a = -5.53151413431;
  ck_assert_ldouble_eq(s21_fabs(a), fabs(a));
}
END_TEST

START_TEST(fabs_test_6) {
  double a = NAN;
  ck_assert_ldouble_nan(s21_fabs(a));
  ck_assert_ldouble_nan(fabs(a));
}
END_TEST

START_TEST(fabs_test_7) {
  double a = INFINITY;
  ck_assert_ldouble_infinite(s21_fabs(a));
  ck_assert_ldouble_infinite(fabs(a));
}
END_TEST

START_TEST(fabs_test_8) {
  double a = -9519359135915.53151413431;
  ck_assert_ldouble_eq_tol(s21_fabs(a), fabs(a), S21_EPS_TEST);
}
END_TEST

START_TEST(fabs_test_10) {
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_nan(fabs(NAN));
}
END_TEST

START_TEST(fabs_test_11) {
  ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
}
END_TEST

START_TEST(fabs_test_12) { ck_assert_ldouble_eq(s21_fabs(15.01), fabs(15.01)); }
END_TEST

START_TEST(fabs_test_13) {
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(fabs_test_14) {
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(fabs_test_15) {
  double num = NAN;
  long double orig_res = fabs(num), our_res = s21_fabs(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

Suite *s21_fabs_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_fabs");

  tc = tcase_create("case_fabs");

  tcase_add_test(tc, fabs_test_1);
  tcase_add_test(tc, fabs_test_2);
  tcase_add_test(tc, fabs_test_3);
  tcase_add_test(tc, fabs_test_4);
  tcase_add_test(tc, fabs_test_5);
  tcase_add_test(tc, fabs_test_6);
  tcase_add_test(tc, fabs_test_7);
  tcase_add_test(tc, fabs_test_8);
  tcase_add_test(tc, fabs_test_10);
  tcase_add_test(tc, fabs_test_11);
  tcase_add_test(tc, fabs_test_12);
  tcase_add_test(tc, fabs_test_13);
  tcase_add_test(tc, fabs_test_14);
  tcase_add_test(tc, fabs_test_15);

  suite_add_tcase(s, tc);
  return s;
}