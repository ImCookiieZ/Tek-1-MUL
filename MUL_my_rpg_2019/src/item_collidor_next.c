/*
** EPITECH PROJECT, 2020
** item collidor
** File description:
** collidor 2
*/

#include "../include/all_includes.h"

void glumanda_items_next(objects *object, sfVector2f player_pos)
{
    if (object->map_x == 4 && object->map_y == 4 && \
    object->player->xp_level >= 10) {
        if (object->player->item_is_found == 1) {
            sfRenderWindow_drawSprite\
            (object->window, object->items->fire_item2, NULL);
        }
        if (player_pos.x >= 1040 && player_pos.x <= 1140 &&
            player_pos.y >= 400 && player_pos.y <= 500 &&
            object->player->item_is_found == 1) {
            sfSound_play(object->sounds[7]);
            object->player->item_is_found = 2;
        }
    }
}

void bisasam_items_next(objects *object, sfVector2f player_pos)
{
    if (object->map_x == 0 && object->map_y == 3 && \
    object->player->xp_level >= 10) {
        if (object->player->item_is_found == 1) {
            sfRenderWindow_drawSprite\
            (object->window, object->items->grass_item2, NULL);
        }
        if (player_pos.x >= 300 && player_pos.x <= 400 &&
            player_pos.y >= 200 && player_pos.y <= 300 &&
            object->player->item_is_found == 1) {
            sfSound_play(object->sounds[7]);
            object->player->item_is_found = 2;
        }
    }
}

void shiggy_items_next(objects *object, sfVector2f player_pos)
{
    if (object->map_x == 6 && object->map_y == 0 && \
    object->player->xp_level >= 10) {
        if (object->player->item_is_found == 1) {
            sfRenderWindow_drawSprite\
            (object->window, object->items->water_item2, NULL);
        }
        if (player_pos.x >= 1500 && player_pos.x <= 1550 &&
            player_pos.y >= 400 && player_pos.y <= 500 &&
            object->player->item_is_found == 1) {
            sfSound_play(object->sounds[7]);
            object->player->item_is_found = 2;
        }
    }
}