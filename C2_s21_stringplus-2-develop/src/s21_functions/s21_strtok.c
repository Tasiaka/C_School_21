#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = NULL;  // Сохранение состояния между вызовами
  char *token;

  if (str != NULL) {
    last_token = str;
  } else {
    if (last_token == NULL || delim == NULL) {
      return NULL;  // Входная строка не была установлена или разделитель не
                    // указан
    }
  }

  // Пропуск начальных разделителей
  while (*last_token != '\0' && s21_strchr(delim, *last_token) != NULL) {
    last_token++;
  }

  if (*last_token == '\0') {
    last_token = NULL;  // Достигнут конец строки
    return NULL;
  }

  token = last_token;

  // Поиск конца токена
  while (*last_token != '\0' && s21_strchr(delim, *last_token) == NULL) {
    last_token++;
  }

  if (*last_token != '\0') {
    *last_token = '\0';  // Разделение токена нулевым символом
    last_token++;
  } else {
    last_token = NULL;  // Достигнут конец строки
  }

  return token;
}
