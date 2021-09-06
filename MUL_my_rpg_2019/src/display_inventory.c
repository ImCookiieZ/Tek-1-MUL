/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_inventory.c
*/

#include "../include/all_includes.h"
#include "../include/functions.h"
#include "../include/structs.h"

void display_inv_all(objects *object)
{
    sfRenderWindow_clear(object->window, sfBlack);
    sfRenderWindow_drawSprite(object->window, object->map_sprite, NULL);
    draw_player(object);
    sfRenderWindow_drawSprite(object->window, object->inventory->inv_sp, NULL);
    sfRenderWindow_drawSprite(object->window,
        object->inventory->inv_frame, NULL);
    sfRenderWindow_drawSprite(object->window,
        object->inventory->quest_items, NULL);
    disp_inv_texts(object);
    sfRenderWindow_drawSprite(object->window, object->inventory->inv_poke,
        NULL);
    sfRenderWindow_display(object->window);
}

char *display_power_level(objects *object)
{
    if (object->player->level == 0)
        return ("EVO LVL: 1");
    if (object->player->level == 1)
        return ("EVO LVL: 2");
    if (object->player->level == 2)
        return ("EVO LVL: 3");
    return NULL;
}

char *display_exp_level(objects *object)
{
    if (object->player->level == 0)
        return (my_itoa(object->player->xp_level * 25));
    if (object->player->level == 1)
        return (my_itoa(object->player->xp_level * 25));
    if (object->player->level == 2)
        return (my_itoa(object->player->xp_level * 25));
    return NULL;
}

void quest_items_rect(objects *object)
{
    int choice = object->player->choice - 1;

    if (choice == 1)
        choice = 3;
    if (choice == 2)
        choice = 6;

    sfIntRect arr[9] = {
        {0, 0, 130, 260},
        {0, 260, 130, 260},
        {0, 520, 130, 260},
        {130, 0, 130, 260},
        {130, 260, 130, 260},
        {130, 520, 130, 260},
        {260, 0, 130, 260},
        {260, 260, 130, 260},
        {260, 520, 130, 260},
    };
    sfSprite_setTextureRect(object->inventory->quest_items,
        arr[choice + object->player->item_is_found]);
}

void pokemon_rect(objects *object)
{
    int choice = object->player->choice - 1;

    if (choice == 1)
        choice = 3;
    if (choice == 2)
        choice = 6;

    sfIntRect arr[9] = {
        {0, 0, 250, 200},
        {250, 0, 250, 200},
        {500, 0, 250, 200},
        {0, 200, 250, 200},
        {250, 200, 250, 200},
        {500, 200, 250, 200},
        {0, 400, 250, 200},
        {250, 400, 250, 200},
        {500, 400, 250, 200},
    };
    sfSprite_setTextureRect(object->inventory->inv_poke,
        arr[choice + object->player->level]);
}