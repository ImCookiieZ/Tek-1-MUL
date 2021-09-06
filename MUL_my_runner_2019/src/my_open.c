/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_open.c
*/

#include "../include/all_includes.h"

int my_open(char *file)
{
    char **buffer = malloc(sizeof(char *) * 20);
    int fd = 0;
    int ret = 0;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        write(2, "Sorry but that is not a map. Dont try to crash me!\n", 51);
        return (84);
    } else {
        buffer[0] = get_next_line(fd);
        ret = my_error_checker(buffer[0]);
        my_printf("%i", ret);
        for (int i = 0; buffer[i] && ret == 0; i++) {
            buffer[i + 1] = get_next_line(fd);
            ret = my_error_checker(buffer[i + 1]);
        }
        if (ret == 0)
            ret = run_function(buffer);
    }
    close(fd);
    return (ret);
}