/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** error_check.c
*/

#include "../include/all_includes.h"

int my_error_checker(char const *buffer)
{
    if (buffer == NULL)
        return (0);
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] != ' ' && buffer[i] != 'B' && buffer[i] != 'F' &&
            buffer[i] != '#' && buffer[i] != '+' && buffer[i] != '\n') {
            my_printf("%c\n", buffer[i]);
            my_printf("%s", buffer);
            return (84);
        }
    }
    return (0);
}