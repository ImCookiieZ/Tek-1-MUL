/*
** EPITECH PROJECT, 2019
** init_items2.c
** File description:
** items for pokegame
*/

#include "../include/all_includes.h"

void glumanda_items(objects *object)
{
    sfVector2f player_pos = sfSprite_getPosition(object->player->sprite);

    if (object->map_x == 0 && object->map_y == 3 && \
    object->player->xp_level >= 5) {
        if (object->player->item_is_found == 0) {
            sfRenderWindow_drawSprite\
            (object->window, object->items->fire_item1, NULL);
        }
        if (player_pos.x >= 300 && player_pos.x <= 400 &&
        player_pos.y >= 200 && player_pos.y <= 300 && \
        object->player->item_is_found == 0) {
            sfSound_play(object->sounds[7]);
            object->player->item_is_found = 1;
        }
    }
    glumanda_items_next(object, player_pos);
}

void bisasam_items(objects *object)
{
    sfVector2f player_pos = sfSprite_getPosition(object->player->sprite);

    if (object->map_x == 6 && object->map_y == 0 && \
    object->player->xp_level >= 5) {
        if (object->player->item_is_found == 0) {
            sfRenderWindow_drawSprite\
            (object->window, object->items->grass_item1, NULL);
        }
        if (player_pos.x >= 1500 && player_pos.x <= 1550 &&
        player_pos.y >= 400 && player_pos.y <= 500 && \
        object->player->item_is_found == 0) {
            sfSound_play(object->sounds[7]);
            object->player->item_is_found = 1;
        }
    }
    bisasam_items_next(object, player_pos);
}

void shiggy_items(objects *object)
{
    sfVector2f player_pos = sfSprite_getPosition(object->player->sprite);

    if (object->map_x == 4 && object->map_y == 4 && \
    object->player->xp_level >= 5) {
        if (object->player->item_is_found == 0) {
            sfRenderWindow_drawSprite\
            (object->window, object->items->water_item1, NULL);
        }
        if (player_pos.x >= 1040 && player_pos.x <= 1140
        && player_pos.y >= 400 && player_pos.y <= 500 && \
        object->player->item_is_found == 0) {
            sfSound_play(object->sounds[7]);
            object->player->item_is_found = 1;
        }
    }
    shiggy_items_next(object, player_pos);
}

int show_items(objects *object, int choice)
{
    item_t *item = malloc(sizeof(item_t));
    choice = object->player->choice;

    if (item == NULL)
        return -1;
    object->items = item;

    if (choice == 1) {
        init_fire_items(object);
        glumanda_items(object);
    }
    if (choice == 2) {
        init_gras_items(object);
        bisasam_items(object);
    }
    if (choice == 3) {
        init_water_items(object);
        shiggy_items(object);
    }
    return 0;
}