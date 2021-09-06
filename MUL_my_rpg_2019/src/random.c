/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int random_seed(void)
{
    int fd = open("seed", O_RDONLY);
    char buffer[5] = "";
    int size = 0;

    if (fd == -1)
        return (-1);
    size = read(fd, buffer, 500);
    if (size == -1)
        return (-1);
    buffer[size] = '\0';
    return (my_getnbr(buffer));
}