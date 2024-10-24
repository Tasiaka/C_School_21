#include "../s21_string.h"
#include "check.h"
#include "string.h"

// Тест на успешное копирование блока памяти
START_TEST(test_s21_memcpy_success) {
  const char *src = "Hello, World!";
  char dest[20] = "";

  const char *src1 = "Hello, World!";
  char dest1[20] = "";

  void *result = s21_memcpy(dest, src, strlen(src) + 1);
  void *res1 = memcpy(dest1, src1, strlen(src1) + 1);

  ck_assert_str_eq(src, src1);
  ck_assert_str_eq(result, res1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

// Тест на копирование 0 байт
START_TEST(test_s21_memcpy_zero_bytes) {
  const char *src = "Hello, World!";
  char dest[20] = "";

  const char *src1 = "Hello, World!";
  char dest1[20] = "";

  void *result = s21_memcpy(dest, src, 0);
  void *result1 = memcpy(dest1, src1, 0);

  ck_assert_str_eq(src, src1);
  ck_assert_str_eq(result, result1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

// Тест на попытку копирования из NULL
START_TEST(test_s21_memcpy_copy_from_null) {
  char dest[20] = "";
  char dest1[20] = "";

  void *result = s21_memcpy(dest, dest + 5, 10);
  void *res1 = memcpy(dest1, dest1 + 5, 10);
  ck_assert_str_eq(result, res1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

// // Тест на успешное копирование пересекающихся блоков (одна и та же память)
// START_TEST(test_s21_memcpy_overlapping_blocks_same_memory) {
//   char dest[20] = "hello, world";
//   char dest1[20] = "hello, world";

//   void *result = s21_memcpy(dest + 5, dest, 10);
//   void *res1 = memcpy(dest1 + 5, dest1, 10);
//   //  ck_assert_ptr_eq(result, dest + 5);
//   ck_assert_str_eq(dest, dest1);
//   ck_assert_str_eq(result, res1);  // Пересекающиеся блоки
// }
// END_TEST

// Тест на успешное копирование пересекающихся блоков (разная память)
START_TEST(test_s21_memcpy_overlapping_blocks_different_memory) {
  const char *src = "Hello, World!";
  char dest[20] = "";

  const char *src1 = "Hello, World!";
  char dest1[20] = "";

  void *result = s21_memcpy(dest + 5, src, 10);
  void *res1 = memcpy(dest1 + 5, src1, 10);

  ck_assert_ptr_eq(result, dest + 5);
  ck_assert_str_eq(result, res1);  // Пересекающиеся блоки
  ck_assert_str_eq(src, src1);
  ck_assert_str_eq(dest, dest1);
}
END_TEST

// Функция для создания и запуска тестовой сьюиты
Suite *s21_memcpy_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_memcpy");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_memcpy_success);
  tcase_add_test(tc_core, test_s21_memcpy_zero_bytes);
  tcase_add_test(tc_core, test_s21_memcpy_copy_from_null);

  // tcase_add_test(tc_core, test_s21_memcpy_overlapping_blocks_same_memory);
  tcase_add_test(tc_core, test_s21_memcpy_overlapping_blocks_different_memory);

  suite_add_tcase(suite, tc_core);

  return suite;
}

// Функция для запуска тестов
int run_s21_memcpy_test() {
  Suite *s = s21_memcpy_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? 0 : 1;
}

int main() { return run_s21_memcpy_test(); }
