/*
** EPITECH PROJECT, 2019
** intro_get_input.c
** File description:
** input
*/

#include "../include/all_includes.h"

intro_t *set_node(intro_t *tmp, const char *line, size_t len, int i)
{
    tmp = (intro_t *)malloc(sizeof(intro_t));
    if (!(tmp->s = malloc(sizeof(char) * len + 1)))
        return NULL;
    tmp->s = my_strcpy(tmp->s, line);
    tmp->x = -1350 - 100;
    tmp->y = 900 + i * 50;
    tmp->size = 2;
    tmp->next = NULL;
    return tmp;
}

intro_t *intro_connect_node(intro_t *intro, intro_t *tmp, intro_t *ptr)
{
    if (intro == NULL) {
        intro = tmp;
    } else {
        ptr = intro;
        while (ptr->next != NULL) ptr = ptr->next;
        ptr->next = tmp;
    }
    return intro;
}

intro_t *get_input(intro_t *intro, int choice)
{
    FILE *fd = NULL;
    intro_t *tmp = NULL;
    intro_t *ptr = NULL;
    char *line = NULL;
    size_t len = 0;
    int i = 0;

    if (choice == 1)
        if (!(fd = fopen(".intro_eng.txt", "r"))) return NULL;
    if (choice == 2)
        if (!(fd = fopen(".intro_fr.txt", "r"))) return NULL;
    if (choice == 3)
        if (!(fd = fopen(".intro_de.txt", "r"))) return NULL;
    if (choice != 1 && choice != 2 && choice != 3)
        return NULL;
    while (getline(&line, &len, fd) != -1) {
        tmp = set_node(tmp, line, len, i);
        i++;
        intro = intro_connect_node(intro, tmp, ptr);
    }
    fclose(fd);
    return intro;
}