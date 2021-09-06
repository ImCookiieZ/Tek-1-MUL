/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** change.c
*/

#include "../include/all_includes.h"

sfIntRect get_player_image(player_t *p)
{
    sfIntRect arr[8] = {
        {(2 * 30 * p->level), (30 * p->move), 30, 30},
        {30 + (2 * 30 * p->level), 60 + (30 * p->move), 30, 30},
        {(2 * 30 * p->level), 60 + (30 * p->move), 30, 30},
        {30 + (2 * 30 * p->level), (30 * p->move), 30, 30},
        {(2 * 30 * p->level), (30), 30, 30},
        {30 + (2 * 30 * p->level), 60 + (30), 30, 30},
        {(2 * 30 * p->level), 60 + (30), 30, 30},
        {30 + (2 * 30 * p->level), (30), 30, 30},
    };
    return arr[p->dir - 1];
}

void change_player(objects *obj)
{
    if (get_seconds(sfClock_getElapsedTime(obj->player->clock)) > 0.1) {
        if (++obj->player->move == 2)
            obj->player->move = 0;
        sfSprite_setTextureRect(obj->player->sprite,
            get_player_image(obj->player));
        sfClock_restart(obj->player->clock);
    }
}

int change_music_to_map(objects *obj, int x)
{
    if ((x == 0 || x == 1) && obj->map_names[obj->map_y][obj->map_x - 1]) {
        obj->map_x == 3 && obj->map_y == 1 ? play_music(obj, CAVE_MUSIC), \
        obj->map_type = CAVE_MUSIC : 0;
        obj->map_x == 4 && obj->map_y == 1 ? play_music(obj, MAIN_MUSIC), \
        obj->map_type = MAIN_MUSIC : 0;
        change_map(obj, -1, 0, 0);
        return (1);
    }
    if ((x == 27 || x == 26) && obj->map_names[obj->map_y][obj->map_x + 1]) {
        obj->map_x == 3 && obj->map_y == 1 ? play_music(obj, GRASS_MUSIC), \
        obj->map_type = GRASS_MUSIC : 0;
        obj->map_x == 2 && obj->map_y == 1 ? play_music(obj, MAIN_MUSIC), \
        obj->map_type = MAIN_MUSIC : 0;
        change_map(obj, 1, 0, 0);
        return (1);
    }
    return (0);
}

void do_the_change(objects *obj)
{
    int x = (int) ((sfSprite_getPosition(obj->player->sprite).x / 4.3) / 16);
    int y = (int) ((sfSprite_getPosition(obj->player->sprite).y / 4.3) / 16);
    if ((y == 1 || y == 0) && obj->map_names[obj->map_y + 1][obj->map_x]) {
        obj->map_x == 3 && obj->map_y == 1 ? play_music(obj, BEACH_MUSIC), \
        obj->map_type = BEACH_MUSIC : 0;
        obj->map_x == 3 && obj->map_y == 0 ? play_music(obj, MAIN_MUSIC), \
        obj->map_type = MAIN_MUSIC : 0;
        change_map(obj, 0, 1, 0);
        return;
    }
    if (change_music_to_map(obj, x))
        return;
    if ((y == 14 || y == 13) && obj->map_names[obj->map_y - 1][obj->map_x]) {
        obj->map_x == 3 && obj->map_y == 2 ? play_music(obj, MAIN_MUSIC), \
        obj->map_type = MAIN_MUSIC : 0;
        obj->map_x == 3 && obj->map_y == 1 ? play_music(obj, BOSS_MUSIC), \
        obj->map_type = BOSS_MUSIC : 0;
        change_map(obj, 0, -1, 0);
        return;
    }
}
