char *s21_strcat(char *dest, const char *src) {
    char *end = dest + s21_strlen(dest);
    while (*src != '\0') {
        *end++ = *src++;
    }
    *end = '\0';
    return dest;
}
