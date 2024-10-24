#include "math_suites.h"

START_TEST(ceil_test_1) {
  ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
}
END_TEST

START_TEST(ceil_test_2) { ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01)); }
END_TEST

START_TEST(ceil_test_3) {
  ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
}
END_TEST

START_TEST(ceil_test_4) {
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(ceil_test_5) { ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12)); }
END_TEST

START_TEST(ceil_test_6) {
  double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(ceil_test_7) {
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(ceil_test_8) {
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(ceil_test_9) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(ceil_test_11) { ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0)); }
END_TEST

START_TEST(ceil_test_12) { ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21)); }
END_TEST

START_TEST(ceil_test_13) { ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91)); }
END_TEST

START_TEST(ceil_test_14) {
  ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21));
}
END_TEST

START_TEST(ceil_test_15) {
  ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91));
}
END_TEST

START_TEST(ceil_test_16) {
  ck_assert_ldouble_eq(s21_ceil(S21_DBL_MAX), ceil(S21_DBL_MAX));
}
END_TEST

START_TEST(ceil_test_17) {
  ck_assert_ldouble_eq(s21_ceil(3457367356754.24524352),
                       ceil(3457367356754.24524352));
}
END_TEST

START_TEST(ceil_test_18) {
  ck_assert_ldouble_eq(s21_ceil(S21_DBL_MAX - 1), ceil(S21_DBL_MAX - 1));
}
END_TEST

START_TEST(ceil_test_19) {
  ck_assert_ldouble_eq(s21_ceil(S21_DBL_MAX - 10), ceil(S21_DBL_MAX - 10));
}
END_TEST

Suite *s21_ceil_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_ceil");
  tc = tcase_create("s21_ceil_test");

  tcase_add_test(tc, ceil_test_1);
  tcase_add_test(tc, ceil_test_2);
  tcase_add_test(tc, ceil_test_3);
  tcase_add_test(tc, ceil_test_4);
  tcase_add_test(tc, ceil_test_5);
  tcase_add_test(tc, ceil_test_6);
  tcase_add_test(tc, ceil_test_7);
  tcase_add_test(tc, ceil_test_8);
  tcase_add_test(tc, ceil_test_9);
  tcase_add_test(tc, ceil_test_11);
  tcase_add_test(tc, ceil_test_12);
  tcase_add_test(tc, ceil_test_13);
  tcase_add_test(tc, ceil_test_14);
  tcase_add_test(tc, ceil_test_15);
  tcase_add_test(tc, ceil_test_16);
  tcase_add_test(tc, ceil_test_17);
  tcase_add_test(tc, ceil_test_18);
  tcase_add_test(tc, ceil_test_19);

  suite_add_tcase(s, tc);
  return s;
}