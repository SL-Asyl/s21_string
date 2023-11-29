#include <stdio.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;
#define s21_NULL ((void *)0)

s21_size_t s21_strlen(const char *str);
char *s21_strrchr(const char *str, int c);
void test();

int main()
{
    test();
    
    return 0;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (*(str + len)) len++;
  return len;
}

char *s21_strrchr(const char *str, int c) {
  int str_length = s21_strlen(str);
  const char *result = s21_NULL;

  for (int x = str_length; result == s21_NULL && x >= 0; x -= 1) {
    if (str[x] == c) result = (str + x);
  }

  return (char *)result;
}

void test() {
  const char *str = "Hello World";
  int c = 'o';

  char *result = s21_strrchr(str, c);

  if (result != NULL) {
    printf("%c %ld\n", c, result - str);
  } else {
    printf("%c", c);
  }
}
