/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** change_map.c
*/

#include "../include/all_includes.h"

void move_map(objects *obj2, objects *obj, float x, float y)
{
    sfVector2f mover = {x * -16.2, y * 16};
    sfVector2f mover2 = {x * -15, y * 14};
    sfVector2f start = {(1926.4 - 16 * 4.3) * x, (1032 - 16 * 4) * -y};
    sfVector2f nule = {0, 0};

    sfSprite_setPosition(obj->foreground_sprite, start);
    sfSprite_setPosition(obj->map_sprite, start);
    while (sfSprite_getPosition(obj->map_sprite).x * x >= 0 &&
    sfSprite_getPosition(obj->map_sprite).y * y <= 0) {
        create_scroller(obj2, obj, &mover, &mover2);
    }
    sfSprite_setPosition(obj->foreground_sprite, nule);
    sfSprite_setPosition(obj->map_sprite, nule);
    if (obj2->map_texture) sfTexture_destroy(obj2->map_texture);
    if (obj2->foreground_texture) sfTexture_destroy(obj2->foreground_texture);
    if (obj2->map_sprite) sfSprite_destroy(obj2->map_sprite);
    if (obj2->foreground_sprite) sfSprite_destroy(obj2->foreground_sprite);
}

void change_player_for_fcol(const objects *obj, int y)
{
    sfIntRect waler =  {(2 * 30 * obj->player->level), (30 * obj->player->move),
                    30, 30};
    if (y > 0)
        sfSprite_setTextureRect(obj->player->sprite, waler);
    if (y < 0) {
        waler.top += 60;
        sfSprite_setTextureRect(obj->player->sprite, waler);
    }
}

void load_enemy_next_map(objects *obj, int x, int y)
{
    obj->map_x += x;
    obj->map_y += y;
    if (obj->map_x == 3 && obj->map_y == 1 && obj->map_y - y == 0)
        reset_boss(&obj->boss);
    if (obj->map_x != 3 || (obj->map_y != 1 && obj->map_y != 0))
        spawn_enemys(obj);
}

int change_map(objects *obj, int x, int y, int first)
{
    objects *obj2 = malloc(sizeof(objects));
    char *prev = my_strdup("maps/");
    char *fore_after = my_strdup("_foreground.png");
    char *all_after = my_strdup("_all.png");
    char *tmp = mal_cat(prev, obj->map_names[obj->map_y + y][obj->map_x + x]);
    char *fore = mal_cat(tmp, fore_after);
    char *map = mal_cat(tmp, all_after);
    if (first == 0) change_player_for_fcol(obj, y);
    create_for_scole(obj, obj2, fore, map);
    if (!(first)) {
        move_map(obj2, obj, (float) x, (float) y);
        pop_all_enemys(obj);
    }
    free(obj2);
    free(tmp);
    load_enemy_next_map(obj, x, y);
    return (0);
}

int init_maps(objects *obj, int load)
{
    obj->map_names = malloc(sizeof(char ***) * 6);
    for (int i = 0; i < 5; i++) {
        obj->map_names[i] = malloc(sizeof(char **) * 8);
        for (int j = 0; j < 8; j++)
            obj->map_names[i][j] = NULL;
    }
    add_names_to_maps(obj);
    if (load == 0) {
        change_map(obj, 3, 1, 1);
        obj->map_x = 3;
        obj->map_y = 1;
    }
    return (0);
}