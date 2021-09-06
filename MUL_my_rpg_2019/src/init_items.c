/*
** EPITECH PROJECT, 2019
** init_items.c
** File description:
** for evolutions in pokemon
*/

#include "../include/all_includes.h"
#include "../include/functions.h"
#include "../include/structs.h"

int init_water_items(objects *object)
{
    sfSprite *water_item1 = NULL;
    sfTexture *water_item1_t = NULL;
    sfVector2f pos = {1040, 400};
    sfSprite *water_item2 = NULL;
    sfTexture *water_item2_t = NULL;
    sfVector2f pos2 = {1475, 430};

    water_item1_t = sfTexture_createFromFile(
        "assets/inventory/water_item1.png", NULL);
    water_item1 = create_my_sprite(water_item1, water_item1_t);
    object->items->water_item1 = water_item1;
    sfSprite_setPosition(object->items->water_item1, pos);

    water_item2_t = sfTexture_createFromFile(
        "assets/inventory/water_item2.png", NULL);
    water_item2 = create_my_sprite(water_item2, water_item2_t);
    object->items->water_item2 = water_item2;
    sfSprite_setPosition(object->items->water_item2, pos2);
    return (0);
}

int init_fire_items(objects *object)
{
    sfSprite *fire_item1 = NULL;
    sfTexture *fire_item1_t = NULL;
    sfVector2f pos = {300, 223};
    sfSprite *fire_item2 = NULL;
    sfTexture *fire_item2_t = NULL;
    sfVector2f pos2 = {1040, 400};

    fire_item1_t = sfTexture_createFromFile(
        "assets/inventory/fire_item1.png", NULL);
    fire_item1 = create_my_sprite(fire_item1, fire_item1_t);
    object->items->fire_item1 = fire_item1;
    sfSprite_setPosition(object->items->fire_item1, pos);

    fire_item2_t = sfTexture_createFromFile(
        "assets/inventory/fire_item2.png", NULL);
    fire_item2 = create_my_sprite(fire_item2, fire_item2_t);
    object->items->fire_item2 = fire_item2;
    sfSprite_setPosition(object->items->fire_item2, pos2);
    return (0);
}

int init_gras_items(objects *object)
{
    sfSprite *gras_item1 = NULL;
    sfTexture *gras_item1_t = NULL;
    sfVector2f pos = {1475, 430};
    sfSprite *gras_item2 = NULL;
    sfTexture *gras_item2_t = NULL;
    sfVector2f pos2 = {300, 223};

    gras_item1_t = sfTexture_createFromFile(
        "assets/inventory/grass_item1.png", NULL);
    gras_item1 = create_my_sprite(gras_item1, gras_item1_t);
    object->items->grass_item1 = gras_item1;
    sfSprite_setPosition(object->items->grass_item1, pos);

    gras_item2_t = sfTexture_createFromFile(
        "assets/inventory/grass_item2.png", NULL);
    gras_item2 = create_my_sprite(gras_item2, gras_item2_t);
    object->items->grass_item2 = gras_item2;
    sfSprite_setPosition(object->items->grass_item2, pos2);
    return (0);
}

void destroy_items(objects *object)
{
    sfTexture_destroy(object->items->water_item1_t);
    sfTexture_destroy(object->items->water_item2_t);
    sfTexture_destroy(object->items->fire_item1_t);
    sfTexture_destroy(object->items->fire_item2_t);
    sfTexture_destroy(object->items->grass_item1_t);
    sfTexture_destroy(object->items->grass_item2_t);
    sfSprite_destroy(object->items->water_item1);
    sfSprite_destroy(object->items->water_item2);
    sfSprite_destroy(object->items->fire_item1);
    sfSprite_destroy(object->items->fire_item2);
    sfSprite_destroy(object->items->grass_item1);
    sfSprite_destroy(object->items->grass_item2);
}
