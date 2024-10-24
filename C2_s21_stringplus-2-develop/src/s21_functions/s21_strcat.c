//
// Created by lifefire1 on 16.12.23.
//

char *s21_strcat(char *dest, const char *src) {
  char *result = dest;  // Сохраняем указатель на начало dest

  // Находим конец dest
  while (*dest) {
    dest++;
  }

  // Копируем содержимое src в dest
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }

  *dest = '\0';  // Устанавливаем нулевой символ в конце объединенной строки

  return result;  // Возвращаем указатель на начало dest
}
