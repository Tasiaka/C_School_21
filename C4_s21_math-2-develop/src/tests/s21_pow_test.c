#include "math_suites.h"

START_TEST(pow_test_1) {
  double base = 1;
  double exp = 1.5;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS_TEST);
}
END_TEST

START_TEST(pow_test_2) {
  double base = INFINITY;
  double exp = 1.1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_3) {
  double base = NAN;
  double exp = 1.1;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  ck_assert_ldouble_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_test_4) {
  double base = NAN;
  double exp = NAN;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  ck_assert_ldouble_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_test_5) {
  double base = 0.001;
  double exp = NAN;
  ck_assert_ldouble_nan(s21_pow(base, exp));
  ck_assert_ldouble_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_test_6) {
  double base = INFINITY;
  double exp = INFINITY;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_7) {
  double base = INFINITY;
  double exp = INFINITY;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_8) {
  long double base = -16.1614;
  long double exp = 7.;
  ck_assert_double_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_9) {
  long double base = -10.1261;
  long double exp = -0.72;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_test_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_13) {
  long double base = -0;
  long double exp = S21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_test_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_16) {
  long double base = -0;
  long double exp = S21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_17) {
  long double base = -1;
  long double exp = S21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_18) {
  long double base = -1;
  long double exp = S21_NAN;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_19) {
  long double base = S21_NAN;
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_20) {
  long double base = -123;
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_test_21) {
  long double base = 0.5591951;
  long double exp = S21_NEG_INF;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test_22) {
  long double base = 1.5591951;
  long double exp = S21_NEG_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_23) {
  long double base = 0.5591951;
  long double exp = S21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_24) {
  long double base = 1.5591951;
  long double exp = S21_POS_INF;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_25) {
  long double base = S21_NEG_INF;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_26) {
  long double base = S21_NEG_INF;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_27) {
  long double base = S21_NEG_INF;
  long double exp = 141;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_28) {
  long double base = S21_NEG_INF;
  long double exp = 142;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_29) {
  long double base = S21_POS_INF;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_30) {
  long double base = S21_POS_INF;
  long double exp = 1;
  ck_assert_ldouble_infinite(s21_pow(base, exp));
  ck_assert_ldouble_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_test_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

START_TEST(pow_test_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-6);
}
END_TEST

START_TEST(pow_test_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-6);
}
END_TEST

START_TEST(pow_test_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-6);
}
END_TEST

START_TEST(pow_test_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           1e-6);
}
END_TEST

START_TEST(pow_test_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_test_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_test_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-6);
}
END_TEST

START_TEST(pow_test_40) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_test_41) {
  long double exp = -12;
  ck_assert_ldouble_infinite(s21_pow(-0, exp));
  ck_assert_ldouble_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_test_42) {
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_43) {
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(+0, exp));
  ck_assert_double_nan(pow(+0, exp));
}
END_TEST

START_TEST(pow_test_44) {
  long double exp = 2.456;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_45) {
  long double exp = S21_NEG_INF;
  ck_assert_ldouble_infinite(s21_pow(+0, exp));
  ck_assert_ldouble_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_test_46) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_47) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_48) {
  long double exp = 56.345;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_49) {
  long double exp = S21_POS_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_50) {
  long double exp = S21_NEG_INF;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_51) {
  long double exp = S21_NAN;
  ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_52) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_53) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_54) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_55) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, exp), pow(S21_NAN, exp), 1e-6);
}
END_TEST

START_TEST(pow_test_56) {
  long double exp = S21_NAN;
  ck_assert_double_nan(s21_pow(S21_NAN, exp));
  ck_assert_double_nan(pow(S21_NAN, exp));
}
END_TEST

START_TEST(pow_test_57) {
  long double exp = S21_POS_INF;
  ck_assert_ldouble_infinite(s21_pow(S21_POS_INF, exp));
  ck_assert_ldouble_infinite(pow(S21_POS_INF, exp));
}
END_TEST

START_TEST(pow_test_58) {
  long double exp = S21_NEG_INF;
  ck_assert_ldouble_eq_tol(s21_pow(S21_NEG_INF, exp), pow(S21_NEG_INF, exp),
                           1e-6);
}
END_TEST

START_TEST(pow_test_59) {
  double exp = S21_POS_INF;
  ck_assert_ldouble_infinite(s21_pow(S21_NEG_INF, exp));
  ck_assert_ldouble_infinite(pow(S21_NEG_INF, exp));
}
END_TEST

Suite *s21_pow_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_pow");

  tc = tcase_create("s21_pow_test_case");
  tcase_add_test(tc, pow_test_1);
  tcase_add_test(tc, pow_test_2);
  tcase_add_test(tc, pow_test_3);
  tcase_add_test(tc, pow_test_4);
  tcase_add_test(tc, pow_test_5);
  tcase_add_test(tc, pow_test_6);
  tcase_add_test(tc, pow_test_7);
  tcase_add_test(tc, pow_test_8);
  tcase_add_test(tc, pow_test_9);
  tcase_add_test(tc, pow_test_10);
  tcase_add_test(tc, pow_test_12);
  tcase_add_test(tc, pow_test_13);
  tcase_add_test(tc, pow_test_14);
  tcase_add_test(tc, pow_test_15);
  tcase_add_test(tc, pow_test_16);
  tcase_add_test(tc, pow_test_17);
  tcase_add_test(tc, pow_test_18);
  tcase_add_test(tc, pow_test_19);
  tcase_add_test(tc, pow_test_20);
  tcase_add_test(tc, pow_test_21);
  tcase_add_test(tc, pow_test_22);
  tcase_add_test(tc, pow_test_23);
  tcase_add_test(tc, pow_test_24);
  tcase_add_test(tc, pow_test_25);
  tcase_add_test(tc, pow_test_26);
  tcase_add_test(tc, pow_test_27);
  tcase_add_test(tc, pow_test_28);
  tcase_add_test(tc, pow_test_29);
  tcase_add_test(tc, pow_test_30);
  tcase_add_test(tc, pow_test_31);
  tcase_add_test(tc, pow_test_32);
  tcase_add_test(tc, pow_test_33);
  tcase_add_test(tc, pow_test_34);
  tcase_add_test(tc, pow_test_35);
  tcase_add_test(tc, pow_test_36);
  tcase_add_test(tc, pow_test_37);
  tcase_add_test(tc, pow_test_39);
  tcase_add_test(tc, pow_test_40);
  tcase_add_test(tc, pow_test_41);
  tcase_add_test(tc, pow_test_42);
  tcase_add_test(tc, pow_test_43);
  tcase_add_test(tc, pow_test_44);
  tcase_add_test(tc, pow_test_45);
  tcase_add_test(tc, pow_test_46);
  tcase_add_test(tc, pow_test_47);
  tcase_add_test(tc, pow_test_48);
  tcase_add_test(tc, pow_test_49);
  tcase_add_test(tc, pow_test_50);
  tcase_add_test(tc, pow_test_51);
  tcase_add_test(tc, pow_test_52);
  tcase_add_test(tc, pow_test_53);
  tcase_add_test(tc, pow_test_54);
  tcase_add_test(tc, pow_test_55);
  tcase_add_test(tc, pow_test_56);
  tcase_add_test(tc, pow_test_57);
  tcase_add_test(tc, pow_test_58);
  tcase_add_test(tc, pow_test_59);

  suite_add_tcase(s, tc);

  return s;
}