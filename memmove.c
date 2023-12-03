#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *s21_memmove(void *dest, const void *src, size_t n) {
    char *dest_ptr = (char *)dest;
    const char *src_ptr = (const char *)src;

    if (dest_ptr == src_ptr) {
        return dest;
    }

    if (dest_ptr < src_ptr && dest_ptr + n > src_ptr) {
        // Перекрытие: копирование с начала в конец
        for (size_t i = 0; i < n; i++) {
            dest_ptr[n - i - 1] = src_ptr[n - i - 1];
        }
    } else {
        // Без перекрытия или перекрытие с src_ptr > dest_ptr: копирование с начала в конец
        for (size_t i = 0; i < n; i++) {
            dest_ptr[i] = src_ptr[i];
        }
    }

    return dest;
}

int main() {
    // Тестовые данные
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    char dest1[20];
    char dest2[20];

    // Использование s21_memmove для копирования строки
    s21_memmove(dest1, str1, strlen(str1) + 1);
    printf("s21_memmove: %s\n", dest1);

    memmove(dest2, str2, strlen(str2) + 1);
    printf("memmove: %s\n", dest2);

    // Тест для перекрытия частей памяти
    char str3[] = "Hello, World!";
    s21_memmove(str3 + 6, str3, 7);
    printf("s21_memmove with overlap: %s\n", str3);

    memmove(str3 + 6, str3, 7);
    printf("memmove with overlap: %s\n", str3);

    // Тест для копирования пустой строки
    char empty_dest[20] = "Destination";
    char empty_src[1] = "";
    s21_memmove(empty_dest, empty_src, 1);
    printf("s21_memmove with empty source: %s\n", empty_dest);

    memmove(empty_dest, empty_src, 1);
    printf("memmove with empty source: %s\n", empty_dest);

    // Тест для копирования в пустой буфер
    char empty_buffer[20] = "";
    char message[] = "Hello!";
    s21_memmove(empty_buffer, message, strlen(message) + 1);
    printf("s21_memmove to empty buffer: %s\n", empty_buffer);

    memmove(empty_buffer, message, strlen(message) + 1);
    printf("memmove to empty buffer: %s\n", empty_buffer);

    // Тест для копирования из пустого буфера
    char dest_buffer[20] = "Destination";
    char empty_message[1] = "";
    s21_memmove(dest_buffer, empty_message, 1);
    printf("s21_memmove from empty buffer: %s\n", dest_buffer);

    memmove(dest_buffer, empty_message, 1);
    printf("memmove from empty buffer: %s\n", dest_buffer);

    // Тест для копирования при нулевом размере
    char str4[] = "Hello, World!";
    s21_memmove(str4 + 5, str4 + 7, 0);
    printf("s21_memmove with zero size: %s\n", str4);

    memmove(str4 + 5, str4 + 7, 0);
    printf("memmove with zero size: %s\n", str4);

    return 0;
}
