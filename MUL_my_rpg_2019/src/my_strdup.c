/*
** EPITECH PROJECT, 2019
** nothing
** File description:
** nothing
*/

#include "../include/all_includes.h"

char *my_strdup(char *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(dest, src);
    dest[my_strlen(src)] = '\0';
    return (dest);
}
