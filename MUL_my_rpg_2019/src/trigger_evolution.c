/*
** EPITECH PROJECT, 2019
** trigger_evolution.c
** File description:
** for each pokemon
*/

#include "../include/all_includes.h"
#include "../include/functions.h"
#include "../include/structs.h"

void trigger_glumanda_evo(objects *obj)
{
    if (obj->player->item_is_found == 1 && obj->player->xp_level >= 5
    && obj->player->level == 0) {
        obj->player->damage += 10;
        evolution(obj);
    }
    if (obj->player->item_is_found == 2 && obj->player->xp_level >= 10
    && obj->player->level == 1) {
        obj->player->damage += 10;
        evolution(obj);
    }
}

void trigger_bisasam_evo(objects *obj)
{
    if (obj->player->item_is_found == 1 && obj->player->xp_level >= 5
    && obj->player->level == 0) {
        obj->player->damage += 10;
        evolution(obj);
    }
    if (obj->player->item_is_found == 2 && obj->player->xp_level >= 10
    && obj->player->level == 1) {
        obj->player->damage += 10;
        evolution(obj);
    }
}

void trigger_shiggy_evo(objects *obj)
{
    if (obj->player->item_is_found == 1 && obj->player->xp_level >= 5
    && obj->player->level == 0) {
        obj->player->damage += 10;
        evolution(obj);
    }
    if (obj->player->item_is_found == 2 && obj->player->xp_level >= 10
    && obj->player->level == 1) {
        obj->player->damage += 10;
        evolution(obj);
    }
}

void trigger_evo(objects *obj)
{
    sfVector2f pos1 = {135, 310};
    sfVector2f pos3 = {1350, 90};
    sfVector2f pos2 = {1750, 620};
    int trigger = npc_trigger(sfSprite_getPosition(obj->player->sprite),
        pos1, pos2, pos3);

    if (obj->player->choice == 1 && trigger == 1)
        trigger_glumanda_evo(obj);
    if (obj->player->choice == 2 && trigger == 2)
        trigger_bisasam_evo(obj);
    if (obj->player->choice == 3 && trigger == 3)
        trigger_shiggy_evo(obj);
}

