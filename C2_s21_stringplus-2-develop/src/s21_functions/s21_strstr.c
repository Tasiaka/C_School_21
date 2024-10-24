#include <stddef.h>

char *s21_strstr(const char *haystack, const char *needle) {
  while (*haystack != '\0') {
    const char *haystack_ptr = haystack;
    const char *needle_ptr = needle;

    while (*needle_ptr != '\0' && *haystack_ptr == *needle_ptr) {
      haystack_ptr++;
      needle_ptr++;
    }

    if (*needle_ptr == '\0') {
      return (char *)haystack;  // Подстрока найдена
    }

    haystack++;
  }

  return NULL;  // Подстрока не найдена
}
