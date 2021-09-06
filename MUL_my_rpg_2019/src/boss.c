/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void reset_game(objects *obj)
{
    sfVector2f vec_start = {1212, 609};

    obj->map_x = 3;
    obj->map_y = 1;
    obj->player->xp_level += 2;
    sfSprite_setPosition(obj->player->sprite, vec_start);
    save_game(obj);
}

void animate_boss(boss_t *boss)
{
    sfIntRect one = {0, 60, 30, 30};
    sfIntRect two = {0, 90, 30, 30};

    if (sfTime_asSeconds(sfClock_getElapsedTime(boss->animator)) > 0.75) {
        if (boss->anim == 1) {
            sfSprite_setTextureRect(boss->sprite, two);
            boss->anim = 2;
        } else {
            sfSprite_setTextureRect(boss->sprite, one);
            boss->anim = 1;
        }
        sfClock_restart(boss->animator);
    }
}

void reset_boss(boss_t *boss)
{
    boss->is_active = 0;
    sfVector2f pos = {500, 225};
    sfSprite_setPosition(boss->sprite, pos);
    boss->hp = 500;
}

void boss_bar(boss_t *boss, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(boss->sprite);
    sfVector2f scale = {0, 0.125f};

    if (boss->hp > 0)
        scale.x = ((float) boss->hp / 100) / 5;
    pos.y += 60;
    pos.x -= (float) boss->hp / 4;
    sfSprite_setScale(boss->life_sprite, scale);
    sfSprite_setPosition(boss->life_sprite, pos);
    sfRenderWindow_drawSprite(window, boss->life_sprite, NULL);
}