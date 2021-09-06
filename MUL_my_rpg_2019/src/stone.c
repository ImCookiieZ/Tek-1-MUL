/*
** EPITECH PROJECT, 2020
** stone
** File description:
** stone
*/

#include "../include/all_includes.h"

void destroy_stone(objects *obj)
{
    static int i = 0;
    sfIntRect rect = {0, 0, 119, 84};

    if (sfTime_asSeconds(sfClock_getElapsedTime(obj->stone_clock)) > 0.125f) {
        sfClock_restart(obj->stone_clock);
        if (i < 20) {
            rect.left = i * 119;
            sfSprite_setTextureRect(obj->stone, rect);
            i += 1;
        } else {
            destroy_stone_stuff(obj);
            obj->stone_destroyed = 1;
            obj->map_col[1][3][14][16] = 0;
            obj->map_col[1][3][14][17] = 0;
            obj->map_col[1][3][14][18] = 0;
            i = 0;
        }
    }
}

void hit_stone(objects *obj, float offset_x, float offset_y)
{
    sfVector2f pos = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f move = obj->projectile->move;
    sfVector2f offset = {offset_x, offset_y};
    if ((int) ((pos.y + move.y + offset.y * obj->projectile->scale.y) / 4.3 /
    16) < 0 || (int) ((pos.y + move.y + offset.y * obj->projectile->scale.y)
    / 4.3 / 16) > 14 || (int) ((pos.x) / 4.3 / 16) < 0 || (int) ((pos.x) /
    4.3 / 16) > 28)
        return;
    if (obj->map_col[obj->map_y][obj->map_x][(int) (
        (pos.y + move.y + offset.y * obj->projectile->scale.y) / 4.3 /
        16)][(int) ((pos.x) / 4.3 / 16)] == 1) {
        obj->projectile->hit = 1;
        obj->hit_stone = 1;
    }
}

void init_stone(objects *object)
{
    sfVector2f pos = {1190, 1000};
    sfVector2f scale = {5, 5};
    sfVector2f origin = {59.5f, 42};

    object->stone_destroyed = 0;
    object->hit_stone = 0;
    object->stone_clock = sfClock_create();
    sfIntRect stone_rect = {0, 0, 119, 84};
    object->stone_t = sfTexture_createFromFile("assets/stone.png", NULL);
    object->stone = sfSprite_create();
    object->stone = create_my_sprite(object->stone, object->stone_t);
    sfSprite_setTextureRect(object->stone, stone_rect);
    sfSprite_setPosition(object->stone, pos);
    sfSprite_setOrigin(object->stone, origin);
    sfSprite_setScale(object->stone, scale);
}