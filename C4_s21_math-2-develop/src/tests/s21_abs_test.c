#include <stdlib.h>

#include "math_suites.h"

START_TEST(abs_test_1) {
  int x = 1;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_2) {
  int x = -1;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_3) {
  int x = 0;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_4) {
  int x = 99999999;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_5) {
  int x = -99999999;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_6) {
  int x = INT32_MAX;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(abs_test_7) {
  int x = -INT32_MAX;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

// START_TEST(abs_test_8) {
//     int x = 1e-9;
//     ck_assert_int_eq(s21_abs(x), abs(x));
// }
// END_TEST

// START_TEST(abs_test_9) {
//     int x = -1e-9;
//     ck_assert_int_eq(s21_abs(x), abs(x));
// }
// END_TEST

START_TEST(abs_test_10) { ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN)); }
END_TEST

START_TEST(abs_test_11) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}
END_TEST

START_TEST(abs_test_12) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

Suite *s21_abs_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_abs");

  tc = tcase_create("s21_abs_case");
  tcase_add_test(tc, abs_test_1);
  tcase_add_test(tc, abs_test_2);
  tcase_add_test(tc, abs_test_3);
  tcase_add_test(tc, abs_test_4);
  tcase_add_test(tc, abs_test_5);
  tcase_add_test(tc, abs_test_6);
  tcase_add_test(tc, abs_test_7);
  // tcase_add_test(tc, abs_test_8);
  // tcase_add_test(tc, abs_test_9);
  tcase_add_test(tc, abs_test_10);
  tcase_add_test(tc, abs_test_11);
  tcase_add_test(tc, abs_test_12);

  suite_add_tcase(s, tc);

  return s;
}