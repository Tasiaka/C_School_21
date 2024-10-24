#include "../s21_string.h"
#include "check.h"
#include "string.h"

// Тест на успешное заполнение блока памяти
START_TEST(test_s21_memset_success) {
  char dest[20];
  char dest1[20];

  s21_memset(dest, 'A', 10);
  memset(dest1, 'A', 10);

  ck_assert_mem_eq(dest, dest1, 10);
}
END_TEST

// Тест на успешное заполнение блока памяти нулевым символом
START_TEST(test_s21_memset_null_character) {
  char dest[20];
  char dest1[20];
  s21_memset(dest, '\0', 10);
  memset(dest1, '\0', 10);
  ck_assert_mem_eq(dest, dest1,
                   10);  // Проверка, что блок заполнен правильно
}
END_TEST

// Тест на успешное заполнение блока памяти отрицательным значением
START_TEST(test_s21_memset_negative_value) {
  char dest[20];
  char dest1[20];
  s21_memset(dest, -1, 10);
  memset(dest1, -1, 10);

  //  ck_assert_ptr_eq(result, dest);
  ck_assert_mem_eq(dest, dest1,
                   10);  // Проверка, что блок заполнен правильно
}
END_TEST

// Тест на успешное заполнение блока памяти нулем
START_TEST(test_s21_memset_zero_value) {
  int dest[10];
  int dest1[10];

  s21_memset(dest, 0, 10 * sizeof(int));
  memset(dest1, 0, 10 * sizeof(int));

  //  ck_assert_ptr_eq(result, dest);
  for (size_t i = 0; i < 10; ++i) {
    ck_assert_int_eq(dest[i],
                     dest1[i]);  // Проверка, что блок заполнен правильно
  }
}
END_TEST

// Функция для создания и запуска тестовой сьюиты
Suite *s21_memset_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_memset");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memset_success);
  tcase_add_test(tc_core, test_s21_memset_null_character);
  tcase_add_test(tc_core, test_s21_memset_negative_value);
  tcase_add_test(tc_core, test_s21_memset_zero_value);
  //  tcase_add_test(tc_core, test_s21_memset_null_pointer);

  suite_add_tcase(suite, tc_core);

  return suite;
}

// Функция для запуска тестов
int run_s21_memset_test() {
  Suite *s = s21_memset_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_s21_memset_test(); }
