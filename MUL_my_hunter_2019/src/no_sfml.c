/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/functions.h"

void print_h(void)
{
    my_putstr("Description by \'-h\':\n" \
    "Duck Hunt.\n" \
    "While running you can add an argument:\n" \
    "-h hor help\n" \
    "\'A number from 1 to 3\' to get different levels\n"
    "After that you can shoot " \
    "the ducks by pressing one mouse button." \
    "\nYou loose if more then seven ducks are in the air \n" \
    "or you have no bullets left\n" \
    "If you hit a duck, you get 2 bullets back.\n" \
    "Every shoot costs one bullet\n");
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

int my_putstr(char const *str)
{
    int i = my_strlen(str);

    write(1, str, i);
    return (0);
}

int count_digits(int nb)
{
    int counter = 0;

    while (nb > 9 || nb % 10 != 0) {
        nb /= 10;
        counter++;
    }
    return (counter);
}

int my_strcmp(char const *s1, char const *s2)
{
    int len_s2 = my_strlen(s2);
    int len_s1 = my_strlen(s1);

    if (len_s1 < len_s2) {
        return (1);
    }
    else if (len_s2 < len_s1) {
        return (-1);
    }
    for (int i = 0; i < len_s1; i++) {
        if (s1[i] != s2[i] ) {
            if (s1[i] > s2[i] )
                return (-1);
            return (1);
        }
    }
    return (0);
}