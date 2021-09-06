/*
** EPITECH PROJECT, 2019
** init_inv.c
** File description:
** initialize inventory files
*/

#include "../include/all_includes.h"
#include "../include/functions.h"
#include "../include/structs.h"

int init_inv(objects *object)
{
    inventory_t *inv = inv = malloc(sizeof(inventory_t));

    if (inv == NULL)
        return -1;
    object->inventory = inv;

    init_quest_items(object);
    init_inv_pokemon(object);
    init_inventory_frame(object);
    return (0);
}

void init_inventory_frame(objects *object)
{
    sfSprite *background = NULL;
    sfTexture *background_t = NULL;
    sfSprite *frame = NULL;
    sfTexture *frame_t = NULL;
    sfVector2f pos = {900, 100};

    background_t = sfTexture_createFromFile(
        "assets/inventory/transparent.png", NULL);
    background = create_my_sprite(background, background_t);
    object->inventory->inv_sp = background;
    object->inventory->inv_tex = background_t;
    frame_t = sfTexture_createFromFile("assets/inventory/window.png", NULL);
    frame = create_my_sprite(frame, frame_t);
    object->inventory->inv_frame = frame;
    object->inventory->inv_frame_t = frame_t;
    sfSprite_setPosition(object->inventory->inv_frame, pos);
}

void init_quest_items(objects *object)
{
    sfSprite *quest_items = NULL;
    sfTexture *quest_items_t = NULL;
    sfVector2f vec = {1610, 500};

    quest_items_t = sfTexture_createFromFile(
        "assets/inventory/questitems.png", NULL);
    quest_items = create_my_sprite(quest_items, quest_items_t);
    object->inventory->quest_items = quest_items;
    object->inventory->quest_items_t = quest_items_t;
    quest_items_rect(object);
    sfSprite_setPosition(object->inventory->quest_items, vec);
}

void init_inv_pokemon(objects *object)
{
    sfSprite *inv_poke = NULL;
    sfTexture *inv_poke_t = NULL;
    sfVector2f vec = {950, 205};

    inv_poke_t = sfTexture_createFromFile(
        "assets/inventory/inv_poke.png", NULL);
    inv_poke = create_my_sprite(inv_poke, inv_poke_t);
    object->inventory->inv_poke = inv_poke;
    object->inventory->inv_poke_t = inv_poke_t;
    pokemon_rect(object);
    sfSprite_setPosition(object->inventory->inv_poke, vec);
}