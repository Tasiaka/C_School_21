#include <check.h>

#include "../s21_string.h"  // Замените на имя вашего заголовочного файла
#include "check.h"
#include "stdio.h"
#include "string.h"

START_TEST(test_s21_sprintf_letter_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "Letter: %c, %c, %3c, %-5c, %-*c, %*c.\n", 'a',
                       70, 'f', 90, 5, 'A', 4, 'H');
  int l2 = sprintf(buf1, "Letter: %c, %c, %3c, %-5c, %-*c, %*c.\n", 'a', 70,
                   'f', 90, 5, 'A', 4, 'H');
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_letter_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "Letter: %lc, %lc, %-lc, %3lc, %-4lc, %*lc.\n",
                       'j', L'a', 'd', 71, 'Q', 5, 'w');
  int l2 = sprintf(buf1, "Letter: %lc, %lc, %-lc, %3lc, %-4lc, %*lc.\n", 'j',
                   L'a', 'd', 71, 'Q', 5, 'w');
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

// integer - d

START_TEST(test_s21_sprintf_integer_format_1) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer1, "Integer: %d, %+d, %10d, %-5d, %+3d, %-.2d, %+.2d.",
                  42, -5, -123, 789, 6, -54, -5);
  int l2 = sprintf(buf1, "Integer: %d, %+d, %10d, %-5d, %+3d, %-.2d, %+.2d.",
                   42, -5, -123, 789, 6, -54, -5);
  ck_assert_str_eq(buffer1, buf1);
  //        printf("\n\n\n%s\n\n\n",buffer);
  //        ck_assert_int_eq(res1, res2);  // Ожидаемая длина строки
  ck_assert_int_eq(l1, l2);
  // Ожидаемая строка
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_integer_format_2) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer1, "Integer: %06d, %0*d, %.*d, % d, % 4d.", 7368,
                       4, 30, 4, 29, 9384, -67);
  int l2 = sprintf(buf1, "Integer: %06d, %0*d, %.*d, % d, % 4d.", 7368, 4, 30,
                   4, 29, 9384, -67);
  //  sprintf(buf1, "Integer: %06d, %  d, %+   d.", 7368, 9384, -67);
  //  error: flag ' ' is ignored when flag '+' is present
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_integer_format_3) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1, "Integer: %+-5d, %+-5d, %-5ld,\n %+5hd, %-.5ld, %+.5hd.\n", -3,
      3, 45l, 65, 44l, 23);
  int l2 =
      sprintf(buf1, "Integer: %+-5d, %+-5d, %-5ld,\n %+5hd, %-.5ld, %+.5hd.\n",
              -3, 3, 45l, 65, 44l, 23);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_integer_format_4) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer1, "Integer: %.*d, %*d, %.*hd,\n %*hd, %.*ld, %*ld.\n",
                  5, 45, 5, 9349, 5, 25, 5, 99, 5, 10l, 5, 93l);
  int l2 = sprintf(buf1, "Integer: %.*d, %*d, %.*hd,\n %*hd, %.*ld, %*ld.\n", 5,
                   45, 5, 9349, 5, 25, 5, 99, 5, 10l, 5, 93l);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_integer_format_5) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1, "Integer: % .*d, % *d, % .*hd,\n % *hd, % .*ld, % *ld.\n", 3, 45,
      3, 9349, 4, 25, 4, 99, 5, 10l, 5, 93l);
  int l2 =
      sprintf(buf1, "Integer: % .*d, % *d, % .*hd,\n % *hd, % .*ld, % *ld.\n",
              3, 45, 3, 9349, 4, 25, 4, 99, 5, 10l, 5, 93l);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

// float - f

START_TEST(test_s21_sprintf_float_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Float: %f, %10f, %-5f,\n %+3f, %-.2f, %+.2f.\n",
                  42.5345, -123.4136, -789.9876543, 6.24643, 54.4362, -5.24646);
  int l2 =
      sprintf(buf1, "Float: %f, %10f, %-5f,\n %+3f, %-.2f, %+.2f.\n", 42.5345,
              -123.4136, -789.9876543, 6.24643, 54.4362, -5.24646);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_float_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Float: %.5f, % f, % -.2f,\n %+-.2f, %+-5f, %+-5f.\n",
                  7345.345256, 9384.235, 56.3453, -5.3457, -3.2355345, 3.23455);
  int l2 =
      sprintf(buf1, "Float: %.5f, % f, % -.2f,\n %+-.2f, %+-5f, %+-5f.\n",
              7345.345256, 9384.235, 56.3453, -5.3457, -3.2355345, 3.23455);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_float_format_3) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "Float: %Lf, %*Lf, %0.*Lf,\n %+Lf, %+-Lf.\n",
                       45.28947824l, 3, 9349.98970l, 10, 6793.1029841090199998l,
                       -123.4532l, -123.4532l);
  int l2 = sprintf(buf1, "Float: %Lf, %*Lf, %0.*Lf,\n %+Lf, %+-Lf.\n",
                   45.28947824l, 3, 9349.98970l, 10, 6793.1029841090199998l,
                   -123.4532l, -123.4532l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_float_format_4) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer, "Float: %.*f, %*f, %+#.9f,\n %-+#.9f, %06f, %+06f.\n", 5,
      45.876543, 5, 99.2464568, 10., 93., -435.94065, -435.94065);
  int l2 =
      sprintf(buf1, "Float: %.*f, %*f, %+#.9f,\n %-+#.9f, %06f, %+06f.\n", 5,
              45.876543, 5, 99.2464568, 10., 93., -435.94065, -435.94065);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_float_format_5) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "Float: % .*f, % *f,\n %0#.*f, %0+#.9Lf.\n", 3,
                       45.28947824, 3, 9349.98970, 10, 6793., -123.l);
  int l2 = sprintf(buf1, "Float: % .*f, % *f,\n %0#.*f, %0+#.9Lf.\n", 3,
                   45.28947824, 3, 9349.98970, 10, 6793., -123.l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

// line - s

START_TEST(test_s21_sprintf_string_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer, "Line: %s, %3s, %5s, %-5s, %.4s, %-.5s, %s, %-s, %-5s, %-.5s.\n",
      "sd43HG#$@!)(*&?><cbk", "cscf", "asx", "dfg", "egh84yt72yh8y3",
      "@#$$C56yrt", "@#$$C56yrt", "@svsvsv56yrt", "JHBJHBS D",
      "sdfsvs   EWF763");
  int l2 = sprintf(
      buf1, "Line: %s, %3s, %5s, %-5s, %.4s, %-.5s, %s, %-s, %-5s, %-.5s.\n",
      "sd43HG#$@!)(*&?><cbk", "cscf", "asx", "dfg", "egh84yt72yh8y3",
      "@#$$C56yrt", "@#$$C56yrt", "@svsvsv56yrt", "JHBJHBS D",
      "sdfsvs   EWF763");
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_string_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer, "Line: %-.25s,\n %.13s,\t %.7s, %35s,\n %.28s.\n",
      "How are you today? Actually.. Good", "Let's get wasted!!!",
      "We're - winners", "Not bad, but not good", "I guess, we're fucked up");
  int l2 = sprintf(buf1, "Line: %-.25s,\n %.13s,\t %.7s, %35s,\n %.28s.\n",
                   "How are you today? Actually.. Good", "Let's get wasted!!!",
                   "We're - winners", "Not bad, but not good",
                   "I guess, we're fucked up");
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_string_format_3) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));

  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "Line: %*s,\t %.*s, %-*s,\n %*s,\n %.*s.\n", 22,
                       "Shell we dance?", 15, "Comming back for more", 30,
                       "I'm breaking your bones", 15, "Not bad, but not good",
                       23, "I guess, we're fucked up");
  int l2 = sprintf(buf1, "Line: %*s,\t %.*s, %-*s,\n %*s,\n %.*s.\n", 22,
                   "Shell we dance?", 15, "Comming back for more", 30,
                   "I'm breaking your bones", 15, "Not bad, but not good", 23,
                   "I guess, we're fucked up");
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
  ///(Segmentation fault: 11)
}

END_TEST

// unsigned char - u

START_TEST(test_s21_sprintf_unsigned_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer, "Unsigned decimal integer: %u, %9u, %.3u, %-5u, %-.8u,%-5.7u.\n",
      345, 855, 76, 90, 012, 239);
  int l2 = sprintf(
      buf1, "Unsigned decimal integer: %u, %9u, %.3u, %-5u, %-.8u,%-5.7u.\n",
      345, 855, 76, 90, 012, 239);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_unsigned_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Unsigned decimal integer: %*u, %.*u, %-*u, %-.*u,\n",
                  6, 34, 6, 34, 7, 345, 7, 01012);
  int l2 = sprintf(buf1, "Unsigned decimal integer: %*u, %.*u, %-*u, %-.*u,\n",
                   6, 34, 6, 34, 7, 345, 7, 01012);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_unsigned_format_3) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer,
      "Unsigned decimal integer: %5hu, %6lu, %3.5hu, %2.4lu, %-7hu, "
      "%-.7hu, %-9lu, %-.9lu.\n",
      01023, 653l, 89, 374l, 0101, 129, 0127l, 720l);
  int l2 =
      sprintf(buf1,
              "Unsigned decimal integer: %5hu, %6lu, %3.5hu, %2.4lu, %-7hu, "
              "%-.7hu, %-9lu, %-.9lu.\n",
              01023, 653l, 89, 374l, 0101, 129, 0127l, 720l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

START_TEST(test_s21_sprintf_unsigned_format_4) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer,
      "Unsigned decimal integer: %*hu, %*lu, %3.*hu, %2.*lu, %-*hu, "
      "%-.*hu, %-*lu, %-.*lu.\n",
      10, 0104523, 7, 03253l, 9, 893, 7, 34l, 11, 01111, 13, 1493, 14, 012327l,
      8, 7039l);
  int l2 =
      sprintf(buf1,
              "Unsigned decimal integer: %*hu, %*lu, %3.*hu, %2.*lu, %-*hu, "
              "%-.*hu, %-*lu, %-.*lu.\n",
              10, 0104523, 7, 03253l, 9, 893, 7, 34l, 11, 01111, 13, 1493, 14,
              012327l, 8, 7039l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

// exp - e

START_TEST(test_s21_sprintf_exp_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Exponent: %e, %9e, %.5e, %-7e, %-.8e, %+5.7e.\n",
                  34.4435, 855.2093, -76e5, 45e-5, 0.72368, 239e-3);
  int l2 = sprintf(buf1, "Exponent: %e, %9e, %.5e, %-7e, %-.8e, %+5.7e.\n",
                   34.4435, 855.2093, -76e5, 45e-5, 0.72368, 239e-3);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_exp_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer, "Exponent: %06e, %0*e, %0.*e,\n % e, % 4e, %06e, %+06e.\n", 736.8,
      15, 423e5, 8, -435.235, 9384e-2, -67.2535, -89e4, 3489e-4);
  int l2 =
      sprintf(buf1, "Exponent: %06e, %0*e, %0.*e,\n % e, % 4e, %06e, %+06e.\n",
              736.8, 15, 423e5, 8, -435.235, 9384e-2, -67.2535, -89e4, 3489e-4);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
  /// (after this point) Received signal 4 (Illegal instruction: 4) --
  /// segmentation fault
}

END_TEST

START_TEST(test_s21_sprintf_exp_format_3) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer,
      "Exponent: %+-15e, %+-15e, % -10e, %+-.9e ,%-15Le, %-.9Le, % -15Le\n",
      -33453.435, 33453.345, -124., 343e-2, 4543e-3l, 32.45044l, -354e-3l);
  int l2 = sprintf(
      buf1,
      "Exponent: %+-15e, %+-15e, % -10e, %+-.9e ,%-15Le, %-.9Le, % -15Le\n",
      -33453.435, 33453.345, -124., 343e-2, 4543e-3l, 32.45044l, -354e-3l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_exp_format_4) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Exponent: %.*e, %*e, %.*Le, %*Le.\n", 15, -452e3, 15,
                  9349346.364, 8, -253412e-5l, 14, 993452.325l);
  int l2 = sprintf(buf1, "Exponent: %.*e, %*e, %.*Le, %*Le.\n", 15, -452e3, 15,
                   9349346.364, 8, -253412e-5l, 14, 993452.325l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_exp_format_5) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Exponent: % .*e, % *e, % .*Le, % *Le.\n", 15, -452e3,
                  15, 9349346.364, 8, -253412e-5l, 14, 993452.325l);
  int l2 = sprintf(buf1, "Exponent: % .*e, % *e, % .*Le, % *Le.\n", 15, -452e3,
                   15, 9349346.364, 8, -253412e-5l, 14, 993452.325l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_exp_format_6) {
  char buffer[200];
  char buf1[200];
  //    memset(buffer,0,200);
  //    memset(buf1,0,200);
  int l1 = s21_sprintf(
      buffer,
      "Exponent: % #e, % 0#15e, %+-#15e, %+-#.14e, %0+#15.3e, % 0#.8e, "
      "%0+#10.2Le.\n",
      4e0, 3e0, 855.65, -76.343, 9076887e-3, 1253643.8, 239.l);
  int l2 =
      sprintf(buf1,
              "Exponent: % #e, % 0#15e, %+-#15e, %+-#.14e, %0+#15.3e, % 0#.8e, "
              "%0+#10.2Le.\n",
              4e0, 3e0, 855.65, -76.343, 9076887e-3, 1253643.8, 239.l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

// EXP - E

START_TEST(test_s21_sprintf_Exp_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "ExponEnt: %E, %9E, %.5E, %-7E, %-.8E, %+5.7E.\n",
                  34.4435, 855.2093, -76E5, 45E-5, 0.72368, 239E-3);
  int l2 = sprintf(buf1, "ExponEnt: %E, %9E, %.5E, %-7E, %-.8E, %+5.7E.\n",
                   34.4435, 855.2093, -76E5, 45E-5, 0.72368, 239E-3);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_Exp_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer, "ExponEnt: %06E, %0*E, %0.*E,\n % E, % 4E, % 06E, %+06E.\n",
      736.8, 15, 423E5, 8, -435.235, 9384E-2, -67.2535, -89E4, 3489E-4);
  int l2 =
      sprintf(buf1, "ExponEnt: %06E, %0*E, %0.*E,\n % E, % 4E, % 06E, %+06E.\n",
              736.8, 15, 423E5, 8, -435.235, 9384E-2, -67.2535, -89E4, 3489E-4);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
  //(after this point) Received signal 4 (Illegal instruction: 4)
}

END_TEST

START_TEST(test_s21_sprintf_Exp_format_3) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer,
      "ExponEnt: %+-15E, %+-15E, % -10E, %+-.9E ,%-15LE, %-.9LE, % -15LE\n",
      -33453.435, 33453.345, -124., 343E-2, 4543E-3l, 32.45044l, -354E-3l);
  int l2 = sprintf(
      buf1,
      "ExponEnt: %+-15E, %+-15E, % -10E, %+-.9E ,%-15LE, %-.9LE, % -15LE\n",
      -33453.435, 33453.345, -124., 343E-2, 4543E-3l, 32.45044l, -354E-3l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  //    free(buffer);
  //    free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_Exp_format_4) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "ExponEnt: %.*E, %*E, %.*LE, %*LE.\n", 15, -452E3, 15,
                  9349346.364, 8, -253412E-5l, 14, 993452.325l);
  int l2 = sprintf(buf1, "ExponEnt: %.*E, %*E, %.*LE, %*LE.\n", 15, -452E3, 15,
                   9349346.364, 8, -253412E-5l, 14, 993452.325l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_Exp_format_5) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "ExponEnt: % .*E, % *E, % .*LE, % *LE.\n", 15, -452E3,
                  15, 9349346.364, 8, -253412E-5l, 14, 993452.325l);
  int l2 = sprintf(buf1, "ExponEnt: % .*E, % *E, % .*LE, % *LE.\n", 15, -452E3,
                   15, 9349346.364, 8, -253412E-5l, 14, 993452.325l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_Exp_format_6) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer,
                       "ExponEnt: % #E, % 0#15E, %+-#10E, %+-#.10E, %0+#15.3E, "
                       "% 0#.8E, %0+#10.2LE.\n",
                       4E0, 3E0, 855.65, -76.343, 9076887E-3, 1253643.8, 239.l);
  int l2 = sprintf(buf1,
                   "ExponEnt: % #E, % 0#15E, %+-#10E, %+-#.10E, %0+#15.3E, "
                   "% 0#.8E, %0+#10.2LE.\n",
                   4E0, 3E0, 855.65, -76.343, 9076887E-3, 1253643.8, 239.l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

// short - g

START_TEST(test_s21_sprintf_gexp_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "gexponent: %g, %9g,  %-7g, %-.8g, %+5.7g.\n",
                       34.4435, -76e5, 45e-5, 0.72368, 239e-3);
  int l2 = sprintf(buf1, "gexponent: %g, %9g,  %-7g, %-.8g, %+5.7g.\n", 34.4435,
                   -76e5, 45e-5, 0.72368, 239e-3);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_gexp_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "gexponent: %06g, %0*g, %0.*g,% g, % 4g, %+06g.",
                  736.8, 15, 423e5, 8, -435.235, 9384e-2, -67.2535, 3489e-4);
  int l2 = sprintf(buf1, "gexponent: %06g, %0*g, %0.*g,% g, % 4g, %+06g.",
                   736.8, 15, 423e5, 8, -435.235, 9384e-2, -67.2535, 3489e-4);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
  //(after this point) Received signal 4 (Illegal instruction: 4)
}

END_TEST

START_TEST(test_s21_sprintf_gexp_format_3) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer,
                       "gexponent: % -10g, %+-.9g ,%-15Lg, %-.9Lg, % -15Lg.\n",
                       -124., 343e-2, 4543e-3l, 32.45044l, -354e-3l);
  int l2 =
      sprintf(buf1, "gexponent: % -10g, %+-.9g ,%-15Lg, %-.9Lg, % -15Lg.\n",
              -124., 343e-2, 4543e-3l, 32.45044l, -354e-3l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_gexp_format_4) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "gexponent: %*g, %.*Lg.\n", 15, 9349346.364, 8,
                       -253412e-5l);
  int l2 = sprintf(buf1, "gexponent: %*g, %.*Lg.\n", 15, 9349346.364, 8,
                   -253412e-5l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_gexp_format_5) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "gexponent: % *g, % .*Lg\n", 15, 9349346.364, 8,
                       -253412e-5l);
  int l2 = sprintf(buf1, "gexponent: % *g, % .*Lg\n", 15, 9349346.364, 8,
                   -253412e-5l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

// SHORT - G

START_TEST(test_s21_sprintf_Gexp_format_1) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "gexponent: %G, %9G,  %-7G, %-.8G, %+5.7G.\n",
                       34.4435, -76e5, 45e-5, 0.72368, 239e-3);
  int l2 = sprintf(buf1, "gexponent: %G, %9G,  %-7G, %-.8G, %+5.7G.\n", 34.4435,
                   -76e5, 45e-5, 0.72368, 239e-3);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  //    free(buffer);
  //    free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_Gexp_format_2) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "gexponent: %06G, %0*G, %0.*G,% G, % 4G, %+06G.",
                  736.8, 15, 423e5, 8, -435.235, 9384e-2, -67.2535, 3489e-4);
  int l2 = sprintf(buf1, "gexponent: %06G, %0*G, %0.*G,% G, % 4G, %+06G.",
                   736.8, 15, 423e5, 8, -435.235, 9384e-2, -67.2535, 3489e-4);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  //    free(buffer);
  //    free(buf1);
  ///(after this point) Received signal 4 (Illegal instruction: 4)
}

END_TEST

START_TEST(test_s21_sprintf_Gexp_format_3) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer,
                       "gexponent: % -10G, %+-.9G ,%-15LG, %-.9LG, % -15LG.\n",
                       -124., 343e-2, 4543e-3l, 32.45044l, -354e-3l);
  int l2 =
      sprintf(buf1, "gexponent: % -10G, %+-.9G ,%-15LG, %-.9LG, % -15LG.\n",
              -124., 343e-2, 4543e-3l, 32.45044l, -354e-3l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

START_TEST(test_s21_sprintf_Gexp_format_4) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "gexponent: %*G, %.*LG.\n", 15, 9349346.364, 8,
                       -253412e-5l);
  int l2 = sprintf(buf1, "gexponent: %*G, %.*LG.\n", 15, 9349346.364, 8,
                   -253412e-5l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  // (after this point) Received signal 11 (Segmentation fault: 11)
}

END_TEST

START_TEST(test_s21_sprintf_Gexp_format_5) {
  char buffer[200];
  char buf1[200];
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer, "gexponent: % *G, % .*LG\n", 15, 9349346.364, 8,
                       -253412e-5l);
  int l2 = sprintf(buf1, "gexponent: % *G, % .*LG\n", 15, 9349346.364, 8,
                   -253412e-5l);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

// octal numbers - o

START_TEST(test_s21_sprintf_octal_format_1) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer1, "Octal: %o, %10o, %-5o\n, %.3o, %-.4o.\n", 42,
                       0123456, 07123, 789, 0366543);
  int l2 = sprintf(buf1, "Octal: %o, %10o, %-5o\n, %.3o, %-.4o.\n", 42, 0123456,
                   07123, 789, 0366543);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_octal_format_2) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1, "Octal: %-5lo,\n %5ho, %-.5lo, %-.5ho, %5o, %5.8lo, %5.6ho.\n",
      45l, 65, 44l, 23, 43, 0234l, 234);
  int l2 = sprintf(
      buf1, "Octal: %-5lo,\n %5ho, %-.5lo, %-.5ho, %5o, %5.8lo, %5.6ho.\n", 45l,
      65, 44l, 23, 43, 0234l, 234);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_octal_format_3) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1,
      "Octal: %#o, %#15o, %-#10o, %-#.10o, %-#15.3o, %#10.2lo, %#10.2ho.\n", 42,
      0123456, 07123, 789, 0366543, 2344l, 0214);
  int l2 = sprintf(
      buf1,
      "Octal: %#o, %#15o, %-#10o, %-#.10o, %-#15.3o, %#10.2lo, %#10.2ho.\n", 42,
      0123456, 07123, 789, 0366543, 2344l, 0214);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_octal_format_4) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer1, "Octal:%-.*o, %*o, %-.*ho,\n %*ho, %.*lo, %-*lo.\n",
                  5, 45, 7, 9349, 5, 25, 9, 7899, 8, 0456710l, 6, 93l);
  int l2 = sprintf(buf1, "Octal:%-.*o, %*o, %-.*ho,\n %*ho, %.*lo, %-*lo.\n", 5,
                   45, 7, 9349, 5, 25, 9, 7899, 8, 0456710l, 6, 93l);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

// hexadecimal numbers - x

START_TEST(test_s21_sprintf_hex_format_1) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer1, "hexadecimal: %x, %10x, %-5x\n, %.3x, %-.4x.\n",
                       0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3);
  int l2 = sprintf(buf1, "hexadecimal: %x, %10x, %-5x\n, %.3x, %-.4x.\n",
                   0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_hex_format_3) {
  char buffer1[200];
  char buf1[200];
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer1,
                  "hexadecimal:  %#x, %#15x, %-#10x, %-#.10x, %-#15.3x, "
                  "%#10.2lx, %#10.2hx.\n",
                  0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3, 0x238cdl, 034523);
  int l2 = sprintf(buf1,
                   "hexadecimal:  %#x, %#15x, %-#10x, %-#.10x, %-#15.3x, "
                   "%#10.2lx, %#10.2hx.\n",
                   0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3, 0x238cdl, 034523);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

START_TEST(test_s21_sprintf_hex_format_4) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1, "hexadecimal: %-.*x, %*x, %-.*hx,\n %*hx, %.*lx, %-*lx.\n", 5,
      03235, 7, 0x4983fa, 5, 283424, 9, 0xacb3294, 8, 0456710l, 6, 0x32d93l);
  int l2 = sprintf(
      buf1, "hexadecimal: %-.*x, %*x, %-.*hx,\n %*hx, %.*lx, %-*lx.\n", 5,
      03235, 7, 0x4983fa, 5, 283424, 9, 0xacb3294, 8, 0456710l, 6, 0x32d93l);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_hex_format_5) {
  char buffer1[200];
  char buf1[200];
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer1,
                  "hexadecimal: %#*x, %#*x, %-#*x, %-#.*x, %-#*.9x, %#10.*lx, "
                  "%-#*.6hx.\n",
                  10, 03235, 11, 0x4983fa, 15, 283424, 9, 0xacb3294, 8, 0456710,
                  13, 0x32d93l, 10, 893485);
  int l2 = sprintf(buf1,
                   "hexadecimal: %#*x, %#*x, %-#*x, %-#.*x, %-#*.9x, %#10.*lx, "
                   "%-#*.6hx.\n",
                   10, 03235, 11, 0x4983fa, 15, 283424, 9, 0xacb3294, 8,
                   0456710, 13, 0x32d93l, 10, 893485);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

// HEXadecimal numbers - X

START_TEST(test_s21_sprintf_HEX_format_1) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(buffer1, "HEXadecimal:%X, %10X, %-5X\n, %.3X, %-.4X.\n",
                       0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3);
  int l2 = sprintf(buf1, "HEXadecimal:%X, %10X, %-5X\n, %.3X, %-.4X.\n",
                   0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

// START_TEST(test_s21_sprintf_HEX_format_2) {
//     char buffer1[200];
//     char buf1[200];
//     s21_sprintf(
//             buffer1,
//             "HEXadecimal: %-5lX, %5hX, %-.5lX, %-.5hX, %5X, %5.8lX,
//             %5.6hX.\n", 0x3249A5l, 0x459ACB5, 07123l, 789, 0x3654F3,
//             0x238cdl, 034523);
//     sprintf(buf1,
//             "HEXadecimal: %-5lX, %5hX, %-.5lX, %-.5hX, %5X, %5.8lX,
//             %5.6hX.\n", 0x3249A5l, 0x459ACB5, 07123l, 789, 0x3654F3,
//             0x238cdl, 034523);
//     ck_assert_str_eq(buffer1, buf1);
//
// }
// END_TEST

START_TEST(test_s21_sprintf_HEX_format_3) {
  char buffer1[200];
  char buf1[200];
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer1,
                  "HEXadecimal: %#X, %#15X, %-#10X, %-#.10X, %-#15.3X, "
                  "%#10.2lX, %#10.2hX.\n",
                  0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3, 0x238cdl, 034523);
  int l2 = sprintf(buf1,
                   "HEXadecimal: %#X, %#15X, %-#10X, %-#.10X, %-#15.3X, "
                   "%#10.2lX, %#10.2hX.\n",
                   0x3249A5, 0x459ACB5, 07123, 789, 0x3654F3, 0x238cdl, 034523);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

START_TEST(test_s21_sprintf_HEX_format_4) {
  char *buffer1 = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1, "HEXadecimal: %-.*X, %*X, %-.*hX,\n %*hX, %.*lX, %-*lX.\n", 5,
      03235, 7, 0x4983fa, 5, 283424, 9, 0xacb3294, 8, 0456710l, 6, 0x32d93l);
  int l2 = sprintf(
      buf1, "HEXadecimal: %-.*X, %*X, %-.*hX,\n %*hX, %.*lX, %-*lX.\n", 5,
      03235, 7, 0x4983fa, 5, 283424, 9, 0xacb3294, 8, 0456710l, 6, 0x32d93l);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer1);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_HEX_format_5) {
  char buffer1[200];
  char buf1[200];
  memset(buffer1, 0, 200);
  memset(buf1, 0, 200);
  int l1 = s21_sprintf(
      buffer1,
      "HEXadecimal:  %#*X, %0#*X, %-#*X, %-#.*X, %-#*.9X, %0#10.*lX, "
      "%-#*.6hX.\n",
      10, 03235, 11, 0x4983fa, 15, 283424, 9, 0xacb3294, 8, 0456710, 13,
      0x32d93l, 10, 893485);
  int l2 =
      sprintf(buf1,
              "HEXadecimal:  %#*X, %0#*X, %-#*X, %-#.*X, %-#*.9X, %#10.*lX, "
              "%-#*.6hX.\n",
              10, 03235, 11, 0x4983fa, 15, 283424, 9, 0xacb3294, 8, 0456710, 13,
              0x32d93l, 10, 893485);
  ck_assert_str_eq(buffer1, buf1);
  ck_assert_int_eq(l1, l2);
}

END_TEST

// address of the pointer - p

START_TEST(test_s21_sprintf_point_format_1) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Pointer: %p, %-p, %10p, %-15p, %-*p, %*p.\n",
                  (void *)0X7a43c1, (void *)5478, (void *)0xab7d4f,
                  (void *)0x7fa654321, 8, (void *)04321, 9, (void *)0xb321c);
  int l2 = sprintf(buf1, "Pointer: %p, %-p, %10p, %-15p, %-*p, %*p.\n",
                   (void *)0X7a43c1, (void *)5478, (void *)0xab7d4f,
                   (void *)0x7fa654321, 8, (void *)04321, 9, (void *)0xb321c);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

START_TEST(test_s21_sprintf_point_format_2) {
  char *buffer = malloc((sizeof(char) * 200));
  char *buf1 = malloc((sizeof(char) * 200));
  memset(buffer, 0, 200);
  memset(buf1, 0, 200);
  int l1 =
      s21_sprintf(buffer, "Pointer: %12p, %-11p, %-*p, %*p.\n", (void *)7812,
                  (void *)012547, 13, (void *)321, 14, (void *)93424);
  int l2 = sprintf(buf1, "Pointer: %12p, %-11p, %-*p, %*p.\n", (void *)7812,
                   (void *)012547, 13, (void *)321, 14, (void *)93424);
  ck_assert_str_eq(buffer, buf1);
  ck_assert_int_eq(l1, l2);
  free(buffer);
  free(buf1);
}

END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *suite = suite_create("s21_sprintf");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_sprintf_integer_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_integer_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_integer_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_integer_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_integer_format_5);

  tcase_add_test(tc_core, test_s21_sprintf_float_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_float_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_float_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_float_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_float_format_5);

  tcase_add_test(tc_core, test_s21_sprintf_letter_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_letter_format_2);

  tcase_add_test(tc_core, test_s21_sprintf_string_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_string_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_string_format_3);

  tcase_add_test(tc_core, test_s21_sprintf_unsigned_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_unsigned_format_4);
  //
  tcase_add_test(tc_core, test_s21_sprintf_exp_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_exp_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_exp_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_exp_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_exp_format_5);
  tcase_add_test(tc_core, test_s21_sprintf_exp_format_6);
  //
  tcase_add_test(tc_core, test_s21_sprintf_Exp_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_Exp_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_Exp_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_Exp_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_Exp_format_5);
  tcase_add_test(tc_core, test_s21_sprintf_Exp_format_6);
  //
  tcase_add_test(tc_core, test_s21_sprintf_gexp_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_gexp_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_gexp_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_gexp_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_gexp_format_5);

  tcase_add_test(tc_core, test_s21_sprintf_Gexp_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_Gexp_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_Gexp_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_Gexp_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_Gexp_format_5);

  tcase_add_test(tc_core, test_s21_sprintf_octal_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_octal_format_2);
  tcase_add_test(tc_core, test_s21_sprintf_octal_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_octal_format_4);

  //
  tcase_add_test(tc_core, test_s21_sprintf_hex_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_hex_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_hex_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_hex_format_5);
  //
  tcase_add_test(tc_core, test_s21_sprintf_HEX_format_1);

  tcase_add_test(tc_core, test_s21_sprintf_HEX_format_3);
  tcase_add_test(tc_core, test_s21_sprintf_HEX_format_4);
  tcase_add_test(tc_core, test_s21_sprintf_HEX_format_5);

  tcase_add_test(tc_core, test_s21_sprintf_point_format_1);
  tcase_add_test(tc_core, test_s21_sprintf_point_format_2);
  //
  // Добавьте другие тесты в этот блок

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_sprintf_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
