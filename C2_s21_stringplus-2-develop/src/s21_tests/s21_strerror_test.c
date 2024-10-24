#include <check.h>
#include <string.h>

#include "../s21_string.h"
#include "check.h"
#include "string.h"

START_TEST(test_strerror) {
#ifdef __APPLE__
  for (int i = 0; i < 109; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
#elif __linux__
  for (int i = 0; i < 135; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
#endif
}
END_TEST

Suite *s21_strerror_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_strerror");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strerror);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int number_failed;
  Suite *s = s21_strerror_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
