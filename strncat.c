#include <stdio.h>
#include <string.h>

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (*(str + len))
    len++;
  return len;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t destLength = s21_strlen(dest);
  s21_size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[destLength + i] = src[i];
  }
  dest[destLength + i] = '\0';

  return dest;
}

int main() {
  char dest1[100] = "Hello";
  char dest2[100] = "Hello";
  const char* src = " World!";
  s21_size_t n = 5;

  // Просто использование s21_strncat
  s21_strncat(dest1, src, n);
  printf("s21_strncat: %s\n", dest1);

  // Просто использование strncat
  strncat(dest2, src, n);
  printf("strncat: %s\n", dest2);

  // Тест 1: n больше длины src
  s21_strncat(dest1, src, 20);
  printf("s21_strncat (n > src length): %s\n", dest1);

  strncat(dest2, src, 20);
  printf("strncat (n > src length): %s\n", dest2);

  // Тест 2: n = 0
  s21_strncat(dest1, src, 0);
  printf("s21_strncat (n = 0): %s\n", dest1);

  strncat(dest2, src, 0);
  printf("strncat (n = 0): %s\n", dest2);

  // Тест 3: n равно длине src
  s21_strncat(dest1, src, strlen(src));
  printf("s21_strncat (n = src length): %s\n", dest1);

  strncat(dest2, src, strlen(src));
  printf("strncat (n = src length): %s\n", dest2);

  // Тест 4: src пустая строка
  const char* empty = "";
  s21_strncat(dest1, empty, n);
  printf("s21_strncat (src is empty): %s\n", dest1);

  strncat(dest2, empty, n);
  printf("strncat (src is empty): %s\n", dest2);

  // Тест 5: n отрицательное
  s21_strncat(dest1, src, -1);
  printf("s21_strncat (n is negative): %s\n", dest1);

  strncat(dest2, src, -1);
  printf("strncat (n is negative): %s\n", dest2);

  return 0;
}
