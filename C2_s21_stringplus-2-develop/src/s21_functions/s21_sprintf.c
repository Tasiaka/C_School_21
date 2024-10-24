//
// Created by lifefire1 on 11/15/23.
//

#include <stdarg.h>
#include <stdio.h>

#include "../s21_string.h"

typedef struct {
  int type;       // Тип данных: 'c', 'd', 'f', 's', 'u', '%'
  int width;      // Ширина (если указана, иначе -1)
  int precision;  // Точность (если указана, иначе -1)
  int length;     // Длина: 'h', 'l' или отсутствует
  int right;
  int space_exist;
  int sign;
  int global_neg;
  int second_sign;
  int hashtag;
  int asterisk_prefix;
  int asterisk_postfix;
  int zero;
  int exp;
  int def;

} FormatInfo;

int doubleToStrHelper(double num, char str[], int precision, FormatInfo *info);
int intToStr(long long num, char str[], FormatInfo *info);
int custom_atoi(const char *str);
int doubleToStr(double num, char str[], int precision, FormatInfo *info);
void intToHexString(int number, char *hexString, int flag);
int find_space(const char *pattern);
int find_sign(const char *pattern, FormatInfo *info);
int find_width(const char *pattern);
int find_type(const char *pattern);
int find_precision(const char *pattern);
int find_length(const char *pattern, int length);
FormatInfo *parse_str(const char *tmp_buffer, int length, va_list *args);
char *add_space(int i, char *result, int convString);
void reverse(char str[], int length);
void del_zer(char *result, int index);

int doubleToStrHelper(double num, char str[], int precision, FormatInfo *info) {
  int i = 0;
  long intPart = (long)num;
  if (intPart != 0) {
    i += intToStr(intPart, str, info);
  } else {
    str[i++] = '0';
  }
  reverse(str, i);
  str[i++] = '.';

  size_t integer;
  if (intPart < 0) {
    intPart *= -1;
  }

  integer = intPart;
  double fracPart = num - (long)integer;
  int count = 0;
  while (count < precision) {
    fracPart *= 10;
    int digit = (int)fracPart;
    str[i++] = (char)(digit + '0');
    fracPart -= digit;
    count++;
  }

  char t = (char)(round((double)(str[i - 1] - '0') + fracPart) + '0');

  if (t > '9') {
    // Обработка переноса разряда
    // Например, установка последнего символа в '0' и увеличение предыдущего
    // разряда
    t = '0';
    int index = 1;  // Начинаем с предыдущего разряда
    while (t == '0' || str[i - index] == '.') {
      // Пропускаем символ точки
      if (str[i - index] == '.') {
        index++;
        continue;
      }

      // Продолжаем двигаться к предыдущим разрядам
      //            if (i - index <= 0) {
      //                // В случае, если дошли до начала строки, добавляем
      //                новый символ впереди i++; for (int j = i; j >= 0; j--) {
      //                    str[j + 1] = str[j];
      //                }
      //                str[0] = '1';
      //                break;
      //            }

      // Увеличиваем предыдущий разряд
      str[i - index]++;
      // Проверяем, произошло ли переполнение
      if (str[i - index] > '9') {
        str[i - index] =
            '0';  // Если переполнилось, устанавливаем в '0' и продолжаем цикл
        index++;
      } else {
        t = str[i - index];  // Если не переполнилось, выходим из цикла
      }
    }
  } else {
    str[i - 1] = t;
  }

  return i;
}

void intToHexString(int number, char *hexString, int flag) {
  // Битовая маска для получения каждого байта числа
  unsigned int mask = 0xF;

  // Индекс для заполнения символов в строке
  int index = 0;  // Начинаем с третьего символа для "0x"

  // Флаг, который показывает, начались ли значащие символы
  int started = 0;

  // Цикл обработки каждого байта числа
  for (int i = sizeof(int) * 2 - 1; i >= 0; --i) {
    // Получаем значение очередного байта
    int value = (number >> (i * 4)) & mask;

    // Пропускаем лидирующие нули
    if (!started && value == 0) {
      continue;
    }

    // Устанавливаем флаг, что начались значащие символы
    started = 1;

    // Преобразуем значение в символ шестнадцатеричной цифры и добавляем к
    // строке
    if (flag == 'X') {
      hexString[index++] = (value < 10) ? ('0' + value) : ('A' + value - 10);
    } else {
      hexString[index++] = (value < 10) ? ('0' + value) : ('a' + value - 10);
    }
  }

  // Если число равно нулю, добавляем один ноль
  if (!started) {
    hexString[index++] = '0';
  }

  hexString[index] = '\0';  // Завершаем строку нулевым символом

  //    return hexString;
}

int doubleToStr(double num, char str[], int precision, FormatInfo *info) {
  int i;
  if ((num < 0 || num == -0) && num != 0) {
    info->global_neg = 1;
    num = -num;
  }

  // Convert double to string
  i = doubleToStrHelper(num, str, precision, info);

  reverse(str, i);
  if (info->sign == 1 && info->exp != 1) {
    str[i++] = info->global_neg ? '-' : '+';
  } else if (info->space_exist && !info->exp) {
    str[i++] = info->global_neg ? '-' : ' ';
  } else if (info->global_neg && !info->exp) {
    str[i++] = '-';
  }
  reverse(str, i);
  str[i] = '\0';
  return i;
}

int custom_atoi(const char *str) {
  int result = 0;
  int sign = 1;
  int i = 0;

  // Обработка знака
  if (str[0] == '-') {
    sign = -1;
    i = 1;
  }

  // Преобразование символов в целочисленное значение
  while (str[i] != '\0') {
    result = result * 10 + (str[i] - '0');
    i++;
  }

  return sign * result;
}

int intToStr(long long num, char str[], FormatInfo *info) {
  int i = 0;

  // Handle negative numbers
  if (num < 0) {
    info->global_neg = 1;
    num = -num;
  }
  if (num == 0) {
    if (info->global_neg) {
      str[i++] = '-';
    }
    str[i++] = '0';
  }

  // Process individual digits
  while (num != 0) {
    long int rem = num % 10l;
    str[i++] = (char)(rem + '0');
    num = num / 10;
  }

  return i;
}

int find_space(const char *pattern) {
  int temp = 0;
  temp++;
  while (pattern[temp] != 'd' && pattern[temp] != 'f' && pattern[temp] != '.' &&
         pattern[temp] != 'c' && pattern[temp] != 'u' && pattern[temp] != 's' &&
         pattern[temp] != 'e' && pattern[temp] != 'E' && pattern[temp] != 'x' &&
         pattern[temp] != 'X' && pattern[temp] != 'g' && pattern[temp] != 'G' &&
         pattern[temp] != 'o' && pattern[temp] != 'p') {
    if (pattern[temp] == ' ') {
      return 1;
    }
    temp++;
  }
  return 0;
}

int find_sign(const char *pattern, FormatInfo *info) {
  int temp = 0;
  temp++;
  info->sign = 0;
  info->second_sign = 0;
  while (pattern[temp] != 'd' && pattern[temp] != 'f' && pattern[temp] != '.' &&
         pattern[temp] != 'c' && pattern[temp] != 'u' && pattern[temp] != 's' &&
         pattern[temp] != 'e' && pattern[temp] != 'E' && pattern[temp] != 'x' &&
         pattern[temp] != 'X' && pattern[temp] != 'g' && pattern[temp] != 'G' &&
         pattern[temp] != 'o' && pattern[temp] != 'p') {
    if (pattern[temp] == '+') {
      info->sign = 1;
    } else if (pattern[temp] == '-') {
      info->second_sign = 1;
    }
    temp++;
  }
  return 0;
}

int find_hs(const char *pattern) {
  int temp = 0;
  temp++;
  while (pattern[temp] != 'd' && pattern[temp] != 'f' && pattern[temp] != '.' &&
         pattern[temp] != 'c' && pattern[temp] != 'u' && pattern[temp] != 's' &&
         pattern[temp] != 'e' && pattern[temp] != 'E' && pattern[temp] != 'x' &&
         pattern[temp] != 'X' && pattern[temp] != 'g' && pattern[temp] != 'G' &&
         pattern[temp] != 'o' && pattern[temp] != 'p') {
    if (pattern[temp] == '#') {
      return 1;
    }
    temp++;
  }
  return 0;
}

int find_width(const char *pattern) {
  char buffer[100] = "";
  int temp = 0;
  temp++;
  int i = 0;
  while (pattern[temp] != 'd' && pattern[temp] != 'f' && pattern[temp] != '.' &&
         pattern[temp] != 'c' && pattern[temp] != 'u' && pattern[temp] != 's' &&
         pattern[temp] != 'e' && pattern[temp] != 'E' && pattern[temp] != 'x' &&
         pattern[temp] != 'X' && pattern[temp] != 'g' && pattern[temp] != 'G' &&
         pattern[temp] != 'o' && pattern[temp] != 'p') {
    if (pattern[temp] >= '0' && pattern[temp] <= '9') {
      buffer[i++] = pattern[temp];
    }
    temp++;
  }
  return custom_atoi(buffer);
}

int find_zero(const char *pattern) {
  //    return pattern[1] == '0'?1:0;
  int temp = 0;
  temp++;
  while (pattern[temp] != '\0') {
    if (pattern[temp] > '0' && pattern[temp] < '9') {
      return 0;
    }

    if (pattern[temp] == 'd' || pattern[temp] == 'f' || pattern[temp] == '.' ||
        pattern[temp] == 'c' || pattern[temp] == 'u' || pattern[temp] == 's' ||
        pattern[temp] == 'e' || pattern[temp] == 'E' || pattern[temp] == 'x' ||
        pattern[temp] == 'X' || pattern[temp] == 'g' || pattern[temp] == 'G' ||
        pattern[temp] == 'o' || pattern[temp] == 'p') {
      return 0;
    }
    if (pattern[temp] == '0') {
      return 1;
    }
    temp++;
  }
  return 0;
}

int find_type(const char *pattern) {
  int temp = 0;
  temp++;
  while (1) {
    // Тип данных: 'c', 'd', 'f', 's', 'u', '%'
    switch (pattern[temp]) {
      case 'd':
        return 'd';
      case 'c':
        return 'c';
      case 's':
        return 's';
      case 'f':
        return 'f';
      case 'u':
        return 'u';
      case 'e':
        return 'e';
      case 'E':
        return 'E';
      case 'X':
        return 'X';
      case 'x':
        return 'x';
      case 'g':
        return 'g';
      case 'G':
        return 'G';
      case 'o':
        return 'o';
      case 'p':
        return 'p';
      default:
        break;
    }
    temp++;
  }
}

int find_precision(const char *pattern) {
  size_t dot_index = s21_strcspn(pattern, ".");
  int temp = 0;
  int len = (int)s21_strlen(pattern);
  size_t pr_len = 0;
  size_t tmp = dot_index + 1;
  if ((int)dot_index == len) {
    return temp;
  }

  while (pattern[tmp] >= '0' && pattern[tmp] <= '9') {
    pr_len++;
    tmp++;
  }

  char *str_precision = (char *)calloc(pr_len + 1, sizeof(char));
  // +1 for null terminator
  if (str_precision == NULL) {
    // Handle memory allocation failure
    return temp;
  }

  s21_strncpy(str_precision, pattern + dot_index + 1, pr_len);
  str_precision[pr_len] = '\0';

  int index = 0;
  while (str_precision[index] >= '0' && str_precision[index] <= '9') {
    index++;
  }

  str_precision[index] = '\0';
  temp = custom_atoi(str_precision);

  free(str_precision);  // Don't forget to free the allocated memory
  return temp;
}

int find_length(const char *pattern, int length) {
  for (int i = 0; i < length; ++i) {
    if (pattern[i] == 'h') {
      return 'h';
    }
    if (pattern[i] == 'L') {
      return 'L';
    }
    if (pattern[i] == 'l') {
      return 'l';
    }
  }
  return '\0';
}

int find_prefix_asterisk(const char *pattern) {
  int tmp = 0;
  while (pattern[tmp] != 'd' && pattern[tmp] != 'c' && pattern[tmp] != 'f' &&
         pattern[tmp] != 's' && pattern[tmp] != 'u' && pattern[tmp] != 'x' &&
         pattern[tmp] != 'X' && pattern[tmp] != 'e' && pattern[tmp] != 'E' &&
         pattern[tmp] != 'g' && pattern[tmp] != 'G' && pattern[tmp] != 'o' &&
         pattern[tmp] != 'p' && pattern[tmp] != '.') {
    if (pattern[tmp] == '*') {
      return 1;
    }
    tmp++;
  }

  return 0;
}

int find_postfix_asterisk(const char *pattern) {
  int tmp = 0;
  size_t dot_index = s21_strcspn(pattern, ".");
  if (dot_index == s21_strlen(pattern)) {
    return 0;
  }
  tmp += (int)dot_index;
  while (pattern[tmp] != 'd' && pattern[tmp] != 'c' && pattern[tmp] != 'f' &&
         pattern[tmp] != 's' && pattern[tmp] != 'u' && pattern[tmp] != 'x' &&
         pattern[tmp] != 'X' && pattern[tmp] != 'e' && pattern[tmp] != 'E' &&
         pattern[tmp] != 'g' && pattern[tmp] != 'G' && pattern[tmp] != 'o' &&
         pattern[tmp] != 'p') {
    if (pattern[tmp] == '*') {
      return 1;
    }
    tmp++;
  }

  return 0;
}

void init_def(FormatInfo *info) {
  info->width = 0;
  info->type = 0;
  info->precision = 0;
  info->sign = 0;
  info->second_sign = 0;
  info->length = 0;
  info->global_neg = 0;
  info->space_exist = 0;
  info->right = 1;
}

FormatInfo *parse_str(const char *tmp_buffer, int length, va_list *args) {
  int prec_width = 0;
  FormatInfo *info = (FormatInfo *)malloc(sizeof(FormatInfo));
  s21_memset(info, 0, sizeof(FormatInfo));
  init_def(info);
  info->hashtag = find_hs(tmp_buffer);
  info->type = find_type(tmp_buffer);
  info->asterisk_prefix = find_prefix_asterisk(tmp_buffer);
  info->zero = find_zero(tmp_buffer);
  if (info->asterisk_prefix) {
    info->width = va_arg(*args, int);
  } else {
    if (tmp_buffer[1] == '0' && (info->type == 'u' || info->type == 'd')) {
      info->precision = find_width(tmp_buffer);
      prec_width = 1;
    } else {
      info->width = find_width(tmp_buffer);
    }
  }

  if (!prec_width) {
    info->asterisk_postfix = find_postfix_asterisk(tmp_buffer);
    if (info->asterisk_postfix) {
      info->precision = va_arg(*args, int);
    } else {
      info->precision = find_precision(tmp_buffer);
    }
  }
  info->space_exist = find_space(tmp_buffer);
  find_sign(tmp_buffer, info);
  if (info->sign == -1) {
    info->right = 0;
  }
  if (info->precision == 0 && info->type != 'd' && info->type != 'u' &&
      info->type != 'x' && info->type != 'X' && info->type != 'o' &&
      info->type != 'p' && info->type != 's') {
    info->precision = 6;
    info->def = 1;
  }
  info->length = find_length(tmp_buffer, length);
  return info;
}

void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

char *add_space(int i, char *result, int convString) {
  char *ret_str = (char *)calloc(convString + i + 3, sizeof(char));
  if (ret_str == NULL) {
    free(result);
    return NULL;
  }
  reverse(result, convString);
  s21_strcpy(ret_str, result);

  free(result);

  while (i > 0) {
    ret_str[convString++] = ' ';
    i--;
  }
  ret_str[convString] = '\0';
  int re = (int)s21_strlen(ret_str);
  reverse(ret_str, re);
  return ret_str;
}

void del_zer(char *result, int index) {
  if (result == NULL) {
    return;
  }
  int len = (int)s21_strlen(result);
  // Проверяем, если символ в индексе - точка
  if (result[index] == '.') {
    // Итерируемся от конца строки и удаляем '0' в конце дробной части
    for (int i = len - 1; i > index && result[i] == '0'; i--) {
      result[i] = '\0';
    }
    // Если после удаления '0' мы оказались на точке, удаляем ее тоже
    if (result[len - 1] == '.') {
      result[len - 1] = '\0';
    }
  } else {
    return;
  }
}

void add_zero(char *result, int quantity_zero) {
  size_t index = s21_strlen(result);
  for (int i = 0; i < quantity_zero; ++i) {
    result[index++] = '0';
  }
}

void round_number(char *result, int precision) {
  int len = (int)s21_strlen(result);
  // Ищем позицию точки
  char *dot = s21_strchr(result, '.');
  if (dot == NULL) {
    return;  // Если точка не найдена, выходим
  }
  // Вычисляем позицию первой цифры после точки
  int firstDigitAfterDot = dot - result + 1;
  // Индекс последней цифры, которая влияет на округление
  int lastSignificantDigitIndex = firstDigitAfterDot + precision;
  // Проверяем, если последние цифры меньше 5 и не влияют на округление
  if (lastSignificantDigitIndex > 0 && lastSignificantDigitIndex < len &&
      result[lastSignificantDigitIndex] < '5') {
    // Отбрасываем последние цифры
    result[lastSignificantDigitIndex] = '\0';
  }
}

void pointerToString(void *ptr, char *buffer, size_t bufferSize) {
  // Проверяем, что буфер не является NULL и его размер достаточен
  if (buffer == NULL || bufferSize == 0) {
    return;
  }
  // Приводим указатель к беззнаковому целому
  // типу для корректного отображения адреса
  uintptr_t uintptr = (uintptr_t)ptr;
  // Используем буфер для записи символов шестнадцатеричной записи указателя
  size_t index = 0;
  // Добавляем префикс "0x"
  if (index < bufferSize - 1) {
    buffer[index++] = '0';
    buffer[index++] = 'x';
  }
  // Записываем шестнадцатеричное представление указателя
  while (uintptr != 0 && index < bufferSize - 1) {
    // Получаем значение текущего разряда
    int digit = uintptr % 16;
    // Преобразуем значение в символ
    // шестнадцатеричной цифры и добавляем к буферу
    buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    // Сдвигаем указатель вправо на 4 бита
    uintptr /= 16;
  }
  // Если указатель равен нулю, добавляем один ноль
  if (uintptr == 0) {
    buffer[index++] = '0';
  }
  // Завершаем строку нулевым символом
  buffer[index] = '\0';
  // Инвертируем строку, так как мы записывали символы с конца
  size_t start = 2;
  size_t end = index - 2;
  while (start < end) {
    char temp = buffer[start];
    buffer[start] = buffer[end];
    buffer[end] = temp;
    start++;
    end--;
  }
  buffer[index - 1] = '\0';
}

int intToOctalString(int number, char *res) {
  // Определяем максимальную длину строки для
  // хранения 32-битного числа в восьмеричной системе
  int maxStringLength =
      sizeof(int) * (3 + 2);  // 3 символа на каждый байт + 1 символ на знак + 1
                              // символ на префикс "0"
  // Выделяем память под строку
  char *octalString = (char *)malloc(maxStringLength);
  s21_memset(octalString, 0, maxStringLength);
  if (octalString == NULL) {
    // Обработка ошибки выделения памяти
    return -1;
  }
  // Заполняем строку вручную
  octalString[0] = '0';  // Префикс для восьмеричной системы
  int index = maxStringLength - 1;  // Индекс для заполнения символов в строке
  // Цикл обработки каждого байта числа
  while (number != 0 && index > 1) {
    // Получаем значение очередного байта
    int value =
        number & 7;  // 7 в бинарном виде: 111 (маска для восьмеричной системы)
    // Преобразуем значение в символ восьмеричной цифры и добавляем к строке
    octalString[--index] = '0' + value;
    // Сдвигаем число вправо на 3 бита для обработки следующего байта
    number >>= 3;
  }
  // Если число равно нулю, добавляем один ноль
  if (index == maxStringLength - 1) {
    octalString[--index] = '0';
  }
  s21_strcpy(res, octalString + index);
  free(octalString);
  return 0;
}

int apr_len(const char *pattern) {
  int l = 1;
  int index = 0;
  while (pattern[index] != '\0') {
    if (pattern[index] >= '0' && pattern[index] <= '9') {
      l += pattern[index] - '0';
    } else if (pattern[index] == 'x' || pattern[index] == 'X')
      l += 5;

    else {
      l++;
    }
    index++;
  }
  return l;
}

int indexOf(char *str, char target) {
  // Ищем первое вхождение символа в строке
  char *ptr = s21_strchr(str, target);
  // Если символ не найден, возвращаем -1
  if (ptr == NULL) {
    return -1;
  }
  // Вычисляем индекс, вычитая указатель на начало строки
  return ptr - str;
}

void processArgument(va_list args, FormatInfo *info, char *flag, double *f,
                     long double *t, long int *d, char **str, void **ptr,
                     char *c) {
  switch (info->type) {
    case 'p': {
      *ptr = (void *)va_arg(args, void *);
      *flag = 'p';
      break;
    }
    case 'o': {
      *d = (int)va_arg(args, int);
      *flag = 'o';
      break;
    }
    case 'g':
      if (info->length == 'L') {
        *t = va_arg(args, long double);
        *f = (double)*t;
      } else {
        *f = (double)va_arg(args, double);
      }
      *flag = 'g';
      break;
    case 'G':
      if (info->length == 'L') {
        *t = va_arg(args, long double);
        *f = (double)*t;
      } else {
        *f = (double)va_arg(args, double);
      }
      *flag = 'G';
      break;
    case 'e': {
      if (info->length == 'L') {
        *t = va_arg(args, long double);
        *f = (double)*t;
      } else {
        *f = (double)va_arg(args, double);
      }
      *flag = 'e';
      break;
    }
    case 'E': {
      if (info->length == 'L') {
        *t = va_arg(args, long double);
        *f = (double)*t;
      } else {
        *f = (double)va_arg(args, double);
      }
      *flag = 'E';
      break;
    }
    case 'f':
      if (info->length == 'L') {
        *t = va_arg(args, long double);
        *f = (double)*t;
      } else {
        *f = (double)va_arg(args, double);
      }
      *flag = 'f';
      break;
    case 'c':
      *c = (char)va_arg(args, int);
      *flag = 'c';
      break;
    case 'd':
      if (info->length == '\0') {
        *d = (int)va_arg(args, int);
      } else if (info->length == 'l') {
        *d = (long int)va_arg(args, long);
      } else {
        *d = (short int)va_arg(args, int);
      }
      *flag = 'd';
      break;
    case 'x':
      if (info->length == 'l') {
        *d = (long int)va_arg(args, long int);
      } else if (info->length == 'h') {
        *d = (unsigned short)va_arg(args, int);
      } else {
        *d = (int)va_arg(args, int);
      }
      *flag = 'x';
      break;
    case 'X':
      if (info->length == 'l') {
        *d = (long int)va_arg(args, long int);
      } else if (info->length == 'h') {
        *d = (unsigned short)va_arg(args, int);
      } else {
        *d = (int)va_arg(args, int);
      }
      *flag = 'X';
      break;
    case 'u':
      if (info->length == '\0') {
        *d = (unsigned int)va_arg(args, unsigned int);
      } else if (info->length == 'l') {
        *d = (unsigned long)va_arg(args, long);
      } else if (info->length == 'h') {
        *d = (unsigned short)va_arg(args, long);
      }
      *flag = 'u';
      break;
    case 's':
      *str = (char *)va_arg(args, char *);
      *flag = 's';
      break;
    default:
      break;
  }
}

char *get_pattern(const char *pattern, int index_pattern, int *size) {
  int tmp_index = index_pattern;
  while (pattern[tmp_index] != 'd' && pattern[tmp_index] != 'c' &&
         pattern[tmp_index] != 'f' && pattern[tmp_index] != 's' &&
         pattern[tmp_index] != 'u' &&
         pattern[tmp_index] !=
             'e'  // если найден один из флагов, то нужно распарсить строку
         && pattern[tmp_index] != 'E' && pattern[tmp_index] != 'X' &&
         pattern[tmp_index] != 'x' && pattern[tmp_index] != 'g' &&
         pattern[tmp_index] != 'G' && pattern[tmp_index] != 'o' &&
         pattern[tmp_index] != 'p') {
    tmp_index++;
    (*size)++;
  }
  char *tmp_buffer = malloc(sizeof(char) * ((*size) + 1));
  s21_memset(tmp_buffer, 0, (*size) + 1);
  s21_strncpy(tmp_buffer, (pattern + index_pattern), (*size));
  tmp_buffer[*size] = '\0';
  return tmp_buffer;
}

int s21_sprintf(char *buffer, const char *pattern, ...) {
  int apr = apr_len(pattern);
  s21_memset(buffer, 0, (apr * 2) - apr / 2);
  int index_pattern = 0;
  int index_buffer = 0;
  va_list args;
  va_start(args, pattern);

  while (pattern[index_pattern] != '\0') {
    if (pattern[index_pattern] == '%' && pattern[index_pattern + 1] != '%') {
      int size = 1;
      char *tmp_buffer = get_pattern(pattern, index_pattern, &size);
      FormatInfo *info = parse_str(tmp_buffer, size, &args);
      info->global_neg = 0;
      double f;
      long double t;
      char c = 0;
      long int d;
      char *str = NULL;
      void *ptr = NULL;
      char flag = 0;
      processArgument(args, info, &flag, &f, &t, &d, &str, &ptr, &c);
      char *result = NULL;
      int str_len = 1;
      if (flag == 's') {
        size_t length = s21_strlen(str);
        size_t res_len = (int)length < info->width ? info->width : (int)length;
        result = (char *)calloc(res_len + 10, sizeof(char));
        s21_strcpy(result, str);
        if (info->precision != 0) {
          result[info->precision] = '\0';
        }
        if (info->width - (int)length > 0) {
          if (info->second_sign) {
            reverse(result, (int)s21_strlen(result));
          }
          result = add_space(info->width - length, result, (int)length);
          if (info->second_sign) {
            reverse(result, (int)s21_strlen(result));
          }
        }

      } else if (flag == 'p') {
        result = (char *)malloc(sizeof(char) * 20);
        pointerToString(ptr, result, 20);
        int length = (int)s21_strlen(result);
        if (info->width - length > 0) {
          if (info->second_sign) {
            reverse(result, length);
          }
          result = add_space(info->width - length, result, length);

          if (info->second_sign) {
            reverse(result, info->width);
          }
        }
      } else if (flag == 'o') {
        int maxStringLength = sizeof(char) * (6 + 2 + 2 + 10);
        result = (char *)malloc(maxStringLength);
        s21_memset(result, 0, maxStringLength);
        intToOctalString(d, result);
        //                printf("%s\n",result);
        if (info->precision - (int)s21_strlen(result) > 0) {
          reverse(result, (int)s21_strlen(result));
          add_zero(result, info->precision - (int)s21_strlen(result));
          reverse(result, (int)s21_strlen(result));
        }
        if (info->hashtag && info->precision - (int)s21_strlen(result) < 0) {
          int l = (int)s21_strlen(result);
          reverse(result, l);
          //                    result[l++] = 'x';
          result[l++] = '0';
          reverse(result, l);
        }

        if (info->width - (int)s21_strlen(result) > 0) {
          if (info->second_sign == 1) {
            reverse(result, (int)s21_strlen(result));
          }
          result = add_space(info->width - (int)s21_strlen(result), result,
                             (int)s21_strlen(result));
          if (info->second_sign == 1) {
            reverse(result, (int)s21_strlen(result));
          }
        }

      } else if (flag == 'd' || flag == 'u') {
        while (pow(10, str_len) <= (int)d) {
          str_len++;
        }
        str_len++;
        if (d < 0) {
          str_len++;
        }
        result = (char *)calloc(str_len + info->precision + 10, sizeof(char));

        int leng_conv_string = intToStr(d, result, info);
        //                reverse(result, leng_conv_string);
        if (info->precision - (int)s21_strlen(result) > 0) {
          add_zero(result, info->precision - (int)s21_strlen(result));
          leng_conv_string = (int)s21_strlen(result);
        }
        int flag1 = 0;
        if (info->sign != -1 && info->second_sign != 1) {
          reverse(result, leng_conv_string);
          flag1 = 1;
        }
        if (info->space_exist) {
          reverse(result, leng_conv_string);
          result[leng_conv_string++] = d < 0 ? '-' : ' ';
          //                    printf("1\n");
          reverse(result, leng_conv_string);
        } else if (info->sign == 1 && info->second_sign == 0) {
          reverse(result, leng_conv_string);
          result[leng_conv_string++] = d < 0 ? '-' : '+';
          //                    printf("2\n");
          reverse(result, leng_conv_string);
        } else if (info->sign == 1 && info->second_sign == 1) {
          result[leng_conv_string++] = d < 0 ? '-' : '+';
          reverse(result, leng_conv_string);

        } else if (d < 0) {
          if (flag1) {
            reverse(result, (int)s21_strlen(result));
          }
          result[leng_conv_string++] = '-';
          if (flag1) {
            reverse(result, (int)s21_strlen(result));
          }
          //                    reverse(result, (int)s21_strlen(result));
        }
        if (info->width - leng_conv_string > 0) {
          if (info->sign == 1 && info->second_sign == 1) {
            reverse(result, leng_conv_string);
          }
          if (info->zero) {
            reverse(result, leng_conv_string);
            add_zero(result, info->width - (int)s21_strlen(result));
            leng_conv_string += info->width - (int)s21_strlen(result);
            reverse(result, (int)s21_strlen(result));
          } else {
            result = add_space(info->width - leng_conv_string, result,
                               leng_conv_string);
          }
          if (info->sign == 1 && info->second_sign == 1) {
            reverse(result, leng_conv_string + 1);
          }
        } else if (info->sign == 1 && info->second_sign == 1) {
          reverse(result, (int)s21_strlen(result));
        }

        if (info->second_sign == 1) {
          reverse(result, (int)s21_strlen(result));
        }

      } else if (flag == 'g' || flag == 'G') {
        info->exp = 1;
        int power = 0;
        long double t_f = f;
        int small = 0;
        int neg = 0;
        if (f < 0) {
          f *= -1;
          neg = 1;
          t_f *= -1;
        }
        if (f < 1) {  // || f < -1) {
          small = 1;
        }
        if (f >= 1) {
          while (t_f > 1) {
            t_f /= 10.0;
            power++;
          }
          t_f *= 10.0;
          power--;
        } else {
          while (t_f < 1) {
            t_f *= 10.0;
            power++;
          }
        }
        if (power > 4) {
          f = t_f;
        }

        result = (char *)malloc(sizeof(char) *
                                (info->width +
                                 (info->precision == 0 ? 6 : info->precision) +
                                 power + 3));
        s21_memset(result, 0,
                   info->width + (info->precision == 0 ? 6 : info->precision) +
                       power + 3);
        doubleToStr(f, result, info->precision - 1, info);
        del_zer(result, indexOf(result, '.'));  // длина мантисы

        if (result[s21_strlen(result) - 1] == '.') {
          result[s21_strlen(result) - 1] = '\0';
        }
        round_number(
            result,
            (info->precision > (int)s21_strlen(result) - indexOf(result, '.'))
                ? ((int)s21_strlen(result) - indexOf(result, '.') - 1)
                : info->precision);
        //                }
        int le = (int)s21_strlen(result);
        if (power > 4) {
          result[le++] = flag == 'g' ? 'e' : 'E';
          result[le++] = small ? '-' : '+';
          if (power < 10) {
            result[le++] = '0';
            result[le++] = power + '0';
          } else {
            char *pow_int = (char *)calloc(6, 1);

            le = intToStr(power, pow_int, info);
            reverse(pow_int, le);
            s21_strcat(result, pow_int);
          }
        }
        int ex = 0;
        le = s21_strlen(result);
        if (info->sign && !info->zero) {
          ex = 1;
          reverse(result, le);
          result[le++] = neg ? '-' : '+';
          reverse(result, le);
        } else if (info->space_exist && !info->zero) {
          ex = 1;
          reverse(result, le);
          result[le++] = neg ? '-' : ' ';
          reverse(result, le);
        } else if (neg && !info->zero) {
          ex = 1;
          reverse(result, le);
          result[le++] = '-';
          reverse(result, le);
        }

        if (info->width - (int)s21_strlen(result) > 0) {
          if (!info->zero) {
            if (info->second_sign) {
              reverse(result, (int)s21_strlen(result));
            }
            result = add_space(info->width - (int)s21_strlen(result), result,
                               (int)s21_strlen(result));
            if (info->second_sign) {
              reverse(result, (int)s21_strlen(result));
            }
          } else if (info->zero) {
            reverse(result, (int)s21_strlen(result));
            add_zero(result, info->width - (int)s21_strlen(result) -
                                 ((info->sign || info->space_exist) ? 1 : 0));
            le = (int)s21_strlen(result);
            if (info->sign) {
              result[le++] = neg ? '-' : '+';
            } else if (info->space_exist) {
              result[le++] = neg ? '-' : ' ';
            } else if (neg) {
              result[le++] = '-';
            }
            reverse(result, (int)s21_strlen(result));
          }
        } else if (!ex) {
          reverse(result, (int)s21_strlen(result));
          if (info->sign) {
            result[le++] = neg ? '-' : '+';
          } else if (info->space_exist) {
            result[le++] = neg ? '-' : ' ';
          } else if (neg) {
            result[le++] = '-';
          }
          reverse(result, (int)s21_strlen(result));
        }

      } else if (flag == 'x' || flag == 'X') {
        int size_signed = 2;
        int def_size = 10;
        int hz = 1;
        result = (char *)malloc(sizeof(char) * (info->precision + info->width +
                                                size_signed + def_size + hz));
        s21_memset(result, 0,
                   info->precision + info->width + size_signed + def_size + hz);
        intToHexString(d, result, flag);
        int length = (int)s21_strlen(result);
        if (info->precision > 0) {
          reverse(result, (int)length);
          add_zero(result, info->precision - (int)length);
          length += (info->precision - (int)length) > 0
                        ? (info->precision - (int)length)
                        : 0;
          reverse(result, (int)length);
        }

        int flag2 = 0;
        if (info->zero) {
          flag2 = 1;
          reverse(result, (int)s21_strlen(result));
          int quant_zero = info->width - length - 2;
          while (quant_zero > 0) {
            result[length++] = '0';
            quant_zero--;
          }
          reverse(result, (int)s21_strlen(result));
        }

        if (info->hashtag) {
          reverse(result, (int)length);
          result[length++] = (flag == 'x') ? 'x' : 'X';
          result[length++] = '0';
          reverse(result, (int)length);
        }
        if (info->width - length > 0 && flag2 == 0) {
          if (info->second_sign != 1) {
            reverse(result, length);
          }
          int quant_space = info->width - length;
          while (quant_space > 0) {
            result[length++] = ' ';
            quant_space--;
          }
          length += info->width - length;
          if (info->second_sign != 1) {
            reverse(result, length);
          }
        }
      } else if (flag == 'e' || flag == 'E') {
        int power = 0;
        info->exp = 1;
        int btz = 0;
        int neg = 0;
        int len_p;
        long double pomoshnik = f;
        if (pomoshnik > 1 || pomoshnik < -1) {
          len_p = 1;
        } else {
          len_p = 2;
        }
        if (pomoshnik > 1 || pomoshnik < -1) {
          btz = 1;
        }
        if (pomoshnik < 0) {
          pomoshnik *= -1;
          neg = 1;
        }
        //                double temp = 0;
        if (pomoshnik > 1) {
          while (pomoshnik >= 1) {
            pomoshnik /= 10.0;
            power++;
          }
          pomoshnik *= 10.0;
          //                    printf("%f\n",temp);
          power--;
        } else {
          while (pomoshnik <= 1) {
            pomoshnik *= 10.0;
            power++;
          }
        }
        f = (double)pomoshnik;
        result = (char *)malloc(sizeof(char) *
                                (info->precision + info->width + power + 10));
        s21_memset(result, 0, info->precision + info->width + power + 10);
        if (neg) {
          f *= -1;
        }
        doubleToStr(f, result, info->precision, info);
        size_t length = s21_strlen(result);
        result[length++] = flag == 'e' ? 'e' : 'E';
        result[length++] = btz ? '+' : '-';

        int t_pow = power;
        while (t_pow > 0) {
          len_p++;
          t_pow /= 10;
        }
        char *res = (char *)calloc(len_p + 10, sizeof(char));
        if (power < 0 || power == -0) {
          power *= -1;
        }
        info->global_neg = 0;
        int len = intToStr(power, res, info);
        res[len] = '\0';
        //                int correct = power < 10? 1:0;
        add_zero(res, (len_p - len - ((power < 10 && !btz) ? 1 : 0) +
                       ((power == 0) ? 1 : 0)));
        reverse(res, s21_strlen(res));
        res[s21_strlen(res)] = '\0';
        s21_strcat(result, res);
        int l_s = (int)s21_strlen(result);
        if (info->zero && info->width > (int)s21_strlen(result)) {
          reverse(result, s21_strlen(result));
          add_zero(result,
                   info->width -
                       ((int)s21_strspn(tmp_buffer, ".") + info->precision + 1 +
                        1 + 1 + (int)s21_strlen(res)) -
                       1 - ((info->space_exist || info->sign) ? 1 : 0));
          reverse(result, s21_strlen(result));
        }
        len = s21_strlen(result);
        if (info->sign) {
          reverse(result, len);
          result[len++] = neg ? '-' : '+';
          reverse(result, len);
        } else if (neg) {
          reverse(result, len);
          result[len++] = '-';
          reverse(result, len);
        } else if (info->space_exist) {
          reverse(result, len);
          result[len++] = ' ';
          reverse(result, len);
        }
        l_s = s21_strlen(result);
        //&& (int)s21_strlen(result) < info->width - ((info->sign ||
        // info->space_exist)?1:0)
        int quantity_space = info->width - l_s;
        if (quantity_space > 0) {
          if (info->second_sign != 1) {
            reverse(result, len);
          }
          if (info->zero) {
            while (quantity_space > 0) {
              result[len++] = '0';
              quantity_space--;
            }
          } else {
            while (quantity_space > 0) {
              result[len++] = ' ';
              quantity_space--;
            }
          }

          if (info->second_sign != 1) {
            reverse(result, len);
          }
        }

        result[s21_strlen(result)] = '\0';
        free(res);
      } else if (flag == 'f') {
        while (pow(10, str_len) <= fabs((double)f)) {
          str_len++;
        }
        if (f < 0) {
          str_len++;
        }
        result = (char *)calloc(str_len + info->precision + 4, sizeof(char));
        int leng_conv_string = doubleToStr(f, result, info->precision, info);
        if (info->sign == -1) {
          reverse(result, (int)s21_strlen(result));
        }
        if (info->sign == 1 && info->second_sign == 1) {
          reverse(result, (int)s21_strlen(result));
        }
        if (info->width - leng_conv_string > 0) {
          result = add_space(info->width - leng_conv_string, result,
                             leng_conv_string);
        }
        if (info->sign == 1 && info->second_sign == 1) {
          reverse(result, (int)s21_strlen(result));
        }
      } else if (flag == 'c') {
        result = (char *)calloc(info->width + 2, sizeof(char));

        s21_memset(result, 0, info->width + 1);
        result[0] = c;
        result[1] = '\0';
        result = add_space(info->width - 1, result, s21_strlen(result));
        if (info->second_sign == 1) {
          reverse(result, s21_strlen(result));
        }
      }
      s21_strcat(buffer, result);
      index_buffer += (int)s21_strlen(result);
      index_pattern += size - 1;
      free(info);
      free(result);
      free(tmp_buffer);
    } else if (pattern[index_pattern] == '%' &&
               pattern[index_pattern + 1] == '%') {
      buffer[index_buffer++] = pattern[index_pattern];
      index_pattern++;
    } else {
      buffer[index_buffer++] = pattern[index_pattern];
    }
    index_pattern++;
  }

  va_end(args);
  return s21_strlen(buffer);
}