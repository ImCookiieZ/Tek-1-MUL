/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** lib_func.c
*/

#include "../include/all_includes.h"

char *my_strcat(char *dest, char const *src)
{
    int sl1 = 0;
    int sl2 = 0;
    int i = 0;

    while (dest[sl1] != '\0') {
        sl1 = sl1 + 1;
    }
    while (src[sl2] != '\0') {
        sl2 = sl2 + 1;
    }
    while (i < sl2) {
        dest[sl1] = src[i];
        sl1 = sl1 + 1;
        i = i + 1;
    }
    dest[sl1] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *mal_cat(char *src1, char *src2)
{
    int len1 = my_strlen(src1);
    int len2 = my_strlen(src2);
    char *dest = malloc(len1 + len2 + 1);

    dest = my_strcpy(dest, src1);
    dest = my_strcat(dest, src2);
    return (dest);
}

void my_putchar_f(FILE* ptr, char c)
{
    fwrite(&c, 1, 1, ptr);
}