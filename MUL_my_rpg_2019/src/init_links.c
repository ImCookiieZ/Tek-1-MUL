/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_links.c
*/

#include <dirent.h>
#include <zconf.h>
#include "../include/all_includes.h"

void get_string_links(FILE *file, int ***const *link, int x, int y)
{
    int len = 0;
    char **tmp_array = NULL;
    size_t buf;
    char *line = NULL;
    for (int i = 0; (len = getline(&line, &buf, file)) != -1; i++) {
        link[y][x][i] = malloc(sizeof(int) * (29));
        if (line[len - 1] == ' ')
            line[len - 1] = 0;
        tmp_array = my_str_to_word_array2(line, " ");
        for (int j = 0; tmp_array[j]; j++) {
            link[y][x][i][j] = my_getnbr(tmp_array[j]);
            link[y][x][i][j + 1] = INT_MAX;
        }
        link[y][x][i + 1] = NULL;
    }
    free(line);
}

int ****get_for_one_map_link(FILE *file, int ****link)
{
    char *line = NULL;
    size_t buf;
    int x = 0;
    int y = 0;
    if (getline(&line, &buf, file) != -1)
        y = my_getnbr(line);
    if (getline(&line, &buf, file) != -1)
        x = my_getnbr(line);
    link[y][x] = malloc(sizeof(int *) * (17));
    get_string_links(file, link, x, y);
    if (line) free(line);
    return (link);
}

int ****loop_links(int ****link, struct dirent *file_dir, FILE *file,
    DIR *directory)
{
    char *path = NULL;
    while ((file_dir = readdir(directory)) != NULL) {
        path = mal_cat("links/", file_dir->d_name);
        file = fopen(path, "r");
        if (file == NULL)
            continue;
        link = get_for_one_map(file, link);
        free(path);
    }
    link[5] = NULL;
    return link;
}

int get_links(objects *obj)
{
    int ****link = malloc(sizeof(int ***) * (6));
    struct dirent *file_dir = NULL;
    FILE *file = NULL;
    DIR *directory = opendir("links");
    if (directory == NULL) {
        free(link);
        return (84);
    }
    for (int i = 0; i < 5; i++) {
        link[i] = malloc(sizeof(int **) * (8));
        for (int j = 0; j < 8; j++)
            link[i][j] = NULL;
    }
    link = loop_links(link, file_dir, file, directory);
    obj->map_link = link;
    return (0);
}