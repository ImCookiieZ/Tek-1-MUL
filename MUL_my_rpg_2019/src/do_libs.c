/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** do_libs.c
*/

#include <zconf.h>
#include "../include/all_includes.h"

int pre_loop(char const *str, int i)
{
    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
        i++;
    return (i);
}

int my_getnbr(char const *str)
{
    long nb = 0;
    int i = pre_loop(str, 0);
    int begin = i;
    int counter = 2;
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        if (nb > 2147483647)
            return (INT_MAX);
        if (nb < -2147483647)
            return (INT_MIN);
        i++;
    }
    while (begin != 0 && str[begin - 1] == '-') {
        counter++;
        begin--;
    }
    if (counter % 2 == 1)
        nb = nb * -1;
    return (nb);
}

int my_put_nbr_f(FILE* ptr, int nb)
{
    int mod;

    if (nb < 0) {
        my_putchar_f(ptr, '-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_nbr_f(ptr, nb);
            my_putchar_f(ptr, (char) (mod + 48));
        }
        else
            my_putchar_f(ptr, (char) (nb % 10 + 48));
    }
    return (0);
}