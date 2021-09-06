/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_collisions.c
*/

#include <dirent.h>
#include <zconf.h>
#include "../include/all_includes.h"

void get_string_cols(FILE *file, int ***const *col, int x, int y)
{
    int len = 0;
    char **tmp_array = NULL;
    size_t buf;
    char *line = NULL;
    for (int i = 0; (len = getline(&line, &buf, file)) != -1; i++) {
        col[y][x][i] = malloc(sizeof(int) * (29));
        if (line[len - 1] == ' ')
            line[len - 1] = 0;
        tmp_array = my_str_to_word_array2(line, " ");
        for (int j = 0; tmp_array[j]; j++) {
            col[y][x][i][j] = my_getnbr(tmp_array[j]);
            col[y][x][i][j + 1] = INT_MAX;
        }
        col[y][x][i + 1] = NULL;
    }
    free(line);
}

int ****get_for_one_map(FILE *file, int ****col)
{
    char *line = NULL;
    size_t buf;
    int x = 0;
    int y = 0;
    if (getline(&line, &buf, file) != -1)
        y = my_getnbr(line);
    if (getline(&line, &buf, file) != -1)
        x = my_getnbr(line);
    col[y][x] = malloc(sizeof(int *) * (17));
    get_string_cols(file, col, x, y);
    if (line) free(line);
    return (col);
}

int ****loop_collisions(int ****col, struct dirent *file_dir, FILE *file,
    DIR *directory)
{
    char *path = NULL;
    while ((file_dir = readdir(directory)) != NULL) {
        path = mal_cat("collisions/", file_dir->d_name);
        file = fopen(path, "r");
        if (file == NULL)
            continue;
        col = get_for_one_map(file, col);
        free(path);
    }
    col[5] = NULL;
    return col;
}

int get_cols(objects *obj)
{
    int ****col = malloc(sizeof(int ***) * (6));
    struct dirent *file_dir = NULL;
    FILE *file = NULL;
    DIR *directory = opendir("collisions");
    if (directory == NULL) {
        free(col);
        return (84);
    }
    for (int i = 0; i < 5; i++) {
        col[i] = malloc(sizeof(int **) * (8));
        for (int j = 0; j < 8; j++)
            col[i][j] = NULL;
    }
    col = loop_collisions(col, file_dir, file, directory);
    obj->map_col = col;
    get_links(obj);
    return (0);
}