#include <stdio.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;

void *s21_memset(void *str, int c, s21_size_t n);
void print_array(const void *arr, s21_size_t n);

int main()
{
    int arr[10];

    s21_memset(arr, 0, sizeof(arr));

    print_array(arr, sizeof(arr));

    return 0;
}

void *s21_memset(void *str, int c, s21_size_t n)
{
    for (int x = 0; x < n; x += 1) {
        ((char *)str)[x] = c;
    }
    return str;
}

void print_array(const void *arr, s21_size_t n)
{
    const char *arr_ptr = arr;

    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr_ptr[i]);
    }
    printf("\n");
}
