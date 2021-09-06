/*
** EPITECH PROJECT, 2020
** sdf
** File description:
** sdf
*/

#include "../include/all_includes.h"

int digits_of_num(int n)
{
    int count = 0;

    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

char *my_itoa(int num)
{
    char *s = NULL;
    int len = digits_of_num(num);
    int rem;

    s = malloc(sizeof(char) * len + 5);

    if (num <= 0) {
        s = my_strcpy(s, "0");
        return s;
    }
    for (int i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        s[len - (i + 1)] = rem + '0';
    }
    s[len] = '\0';
    return s;
}
