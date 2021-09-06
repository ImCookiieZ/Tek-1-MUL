/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void pop_all_enemys(objects *obj)
{
    enemy_t *tmp = NULL;

    while (obj->enemy != NULL) {
        tmp = obj->enemy;
        obj->enemy = obj->enemy->next;
        destroy_enemy(tmp);
    }
    obj->enemy = NULL;
}

sfVector2f get_random_pos(objects *obj)
{
    float x = (float) (rand() % 1700 + 100);
    float y = (float) (rand() % 800 + 100);
    sfVector2f pos = {x, y};

    if (obj->map_col[obj->map_y][obj->map_x][(int) (y / 4.3 / 16)][(int) ((x +
    15 * 4) / 4.3 / 16)] != 0) return (get_random_pos(obj));
    if (obj->map_col[obj->map_y][obj->map_x][(int) (y / 4.3 / 16)][(int) ((x -
    15 * 4) / 4.3 / 16)] != 0) return (get_random_pos(obj));
    if (obj->map_col[obj->map_y][obj->map_x][(int) (y / 4.3 / 16)][(int)
        (x / 4.3 / 16)] != 0) return (get_random_pos(obj));
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((y + 15 * 4) / 4.3 / 16)][
        (int) ((x + 15 * 4) / 4.3 / 16)] != 0) return (get_random_pos(obj));
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((y + 15 * 4) / 4.3 / 16)][
        (int) ((x - 15 * 4) / 4.3 / 16)] != 0) return (get_random_pos(obj));
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((y + 15 * 4) / 4.3 / 16)][
        (int) (x / 4.3 / 16)] != 0) return (get_random_pos(obj));
    return (pos);
}

void spawn_enemys(objects *obj)
{
    for (int i = 0; i < 6; i += 1)
        obj->enemy = add_enemy(obj);
}