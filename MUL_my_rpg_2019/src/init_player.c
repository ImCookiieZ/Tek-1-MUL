/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_player.c
*/

#include "../include/all_includes.h"

void init_player_vars(objects *obj, sfVector2f *vec, sfVector2f *vec_move,
    sfVector2f *vec_start)
{
    sfClock *clock = NULL;
    sfSprite_setOrigin(obj->player->sprite, (*vec));
    obj->player->move_vec = (*vec_move);
    obj->player->dir = 5;
    obj->player->move = -1;
    obj->player->level = 0;
    sfSprite_setPosition(obj->player->sprite, (*vec_start));
    clock = sfClock_create();
    obj->player->clock = clock;
    obj->player->hp = 100;
    obj->player->max_hp = 100;
    obj->player->xp = 0;
    obj->player->damage = 10;
    obj->player->item_is_found = 0;
    obj->player->xp_level = 1;
    obj->player->hp_generator_clock = sfClock_create();
    obj->player->hp_creator_time.microseconds = 5000000;
}

void init_player(objects *obj, int choice)
{
    sfVector2f vec = {15, 15};
    sfVector2f vec_move = {0, 0};
    sfVector2f vec_start = {1212, 609};
    obj->player->sprite = NULL;
    obj->player->texture = NULL;
    obj->player->is_acting = 0;
    obj->player->choice = choice;
    if (choice == 1)
        obj->player->texture = sfTexture_createFromFile(
            "assets/glumanda.png", NULL);
    if (choice == 2)
        obj->player->texture = sfTexture_createFromFile(
            "assets/bisasam.png", NULL);
    if (choice == 3)
        obj->player->texture = sfTexture_createFromFile(
            "assets/shiggy.png", NULL);
    obj->player->sprite =
        create_my_sprite(obj->player->sprite, obj->player->texture);
    init_player_vars(obj, &vec, &vec_move, &vec_start);
}