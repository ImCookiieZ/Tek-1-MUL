/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void boss_move(sfVector2f target, boss_t *boss)
{
    sfVector2f move = {0, 0};
    sfVector2f pos = sfSprite_getPosition(boss->sprite);
    move.x = (target.x - pos.x);
    move.y = (target.y - pos.y);
    move = round_move(move);
    move.x *= 1 + (float) ((500 - boss->hp + 1) * 0.0015);
    move.y *= 1 + (float) ((500 - boss->hp + 1) * 0.0015);
    if (sfTime_asSeconds(sfClock_getElapsedTime(boss->move_clock)) > 0.016) {
        sfSprite_move(boss->sprite, move);
        sfClock_restart(boss->move_clock);
    }
}

void boss_teleport(boss_t *boss)
{
    float x = rand() % 1700 + 100;
    float y = rand() % 800 + 100;
    sfVector2f new_pos = {x, y};
    if (sfTime_asSeconds(sfClock_getElapsedTime(boss->teleport)) > 5 - ((500
    - boss->hp + 1) * 0.008)) {
        sfSprite_setPosition(boss->sprite, new_pos);
        sfClock_restart(boss->teleport);
    }
}

void boss_controller(objects *obj)
{
    sfVector2f pos = sfSprite_getPosition(obj->player->sprite);
    if (obj->boss.hp > 0) {
        if (pos.x <= 1450 && pos.x >= 1250 && pos.y <= 600 && pos.y >= 500) {
            obj->boss.is_active == 0 ? play_music(obj, BOSS_FIGHT_MUSIC),
            obj->map_type = BOSS_FIGHT_MUSIC : 0;
            obj->boss.is_active = 1;
        }
        sfRenderWindow_drawSprite(obj->window, obj->boss.sprite, NULL);
        if (obj->boss.is_active == 1) {
            boss_move(sfSprite_getPosition(obj->player->sprite), &obj->boss);
            boss_teleport(&obj->boss);
            animate_boss(&obj->boss);
            hit_boss_player(obj);
            boss_bar(&obj->boss, obj->window);
        }
    } else if (obj->boss.is_destroyed == 0) {
        sfRenderWindow_drawSprite(obj->window, obj->boss.sprite, NULL);
        destroy_boss(obj);
    }
}