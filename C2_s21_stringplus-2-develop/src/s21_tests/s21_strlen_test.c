#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(s21_strlen_test1) {
  ck_assert_int_eq(s21_strlen("privet"), strlen("privet"));
}
END_TEST

START_TEST(s21_strlen_test2) {
  ck_assert_int_eq(s21_strlen("hello, world"), strlen("hello, world"));
}
END_TEST

START_TEST(s21_strlen_test3) { ck_assert_int_eq(s21_strlen(""), strlen("")); }
END_TEST

START_TEST(s21_strlen_test4) {
  const char *str = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_test5) {
  const char *str = "   spaces before and after   ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_test6) {
  // Testing with a large string
  const char *str =
      "a very long "
      "string..cfgvbhnjkmjhgvfdsfghjklkjhugytfrdgyhujikolp;"
      "lokijuhygtfryguhjikolp;"
      "lpkoijuhygtfryguhjikoplkijuyhtr5yuhijokplokijuhygtfrdyguhijkopllokijuhyg"
      "tfrdtfyguhjioklpokijuhygtfrdtgyhujikol;kjhugyftdfgyhujikolp;"
      "kojiuhygtfrdeftgyuhjik. (1000 characters)";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_test7) {
  // Testing with a null
  const char *str = NULL;
  ck_assert_int_eq(s21_strlen(str), 0);
}
END_TEST

Suite *strlen_suite() {
  Suite *suite;
  TCase *tc_core;
  suite = suite_create("s21_strlen");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strlen_test1);
  tcase_add_test(tc_core, s21_strlen_test2);
  tcase_add_test(tc_core, s21_strlen_test3);
  tcase_add_test(tc_core, s21_strlen_test4);
  tcase_add_test(tc_core, s21_strlen_test5);
  tcase_add_test(tc_core, s21_strlen_test6);
  tcase_add_test(tc_core, s21_strlen_test7);
  suite_add_tcase(suite, tc_core);
  return suite;
}

int run_strlen_test() {
  Suite *s = strlen_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_strlen_test(); }
