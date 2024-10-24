//
// Created by lifefire1 on 16.12.23.
//

char *s21_strcpy(char *dest, const char *src) {
  char *result = dest;  // Сохраняем указатель на начало dest

  // Копируем содержимое src в dest
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }

  *dest = '\0';  // Устанавливаем нулевой символ в конце dest

  return result;  // Возвращаем указатель на начало dest
}