char *s21_strcpy(char *dest, const char *src) {
    char *s = dest;
    while ((*s++ = *src++) != 0)
        ;
    return dest;
}
