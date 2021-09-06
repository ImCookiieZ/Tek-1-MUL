/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void hit_boss_projectile(objects *obj)
{
    sfVector2f proj_pos = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f boss_pos = sfSprite_getPosition(obj->boss.sprite);

    if ((((proj_pos.x - 4 * 4) <= (boss_pos.x + 8 * 4) && (proj_pos.x - 4 *
    4) >= (boss_pos.x - 8 * 4)) || ((proj_pos.x + 4 * 4) >= (boss_pos.x
    - 8 * 4) && (proj_pos.x + 4 * 4) <= boss_pos.x + 8 * 4)) && (((proj_pos
    .y - 2 * 4) <= (boss_pos.y + 8 * 4) && (proj_pos.y - 2 * 4) >=
    (boss_pos.y - 8 * 4)) || ((proj_pos.y + 2 * 4) >= (boss_pos.y - 8 *
    4) && (proj_pos.y + 2 * 4) <= (boss_pos.y + 8 * 4)))) {
        if (obj->projectile->type == 3)
            obj->boss.hp -= (float) obj->player->damage / 4;
        else
            obj->boss.hp -= (float) obj->player->damage / 2;
        obj->projectile->hit = 1;
    }
}

void hit_boss_player(objects *obj)
{
    sfVector2f player_pos = sfSprite_getPosition(obj->player->sprite);
    sfVector2f enemy_pos = sfSprite_getPosition(obj->boss.sprite);

    if ((((player_pos.x - 8 * 4) <= (enemy_pos.x + 8 * 4) && (player_pos.x - 8 *
    4) >= (enemy_pos.x - 8 * 4)) || ((player_pos.x + 8 * 4) >= (enemy_pos.x - 8
    * 4) && (player_pos.x + 8 * 4) <= enemy_pos.x + 8 * 4)) && ((player_pos
    .y <= (enemy_pos.y + 8 * 4) && player_pos.y >= enemy_pos.y) || ((player_pos
    .y + 8 * 4) >= enemy_pos.y && (player_pos.y + 8 * 4) <= (enemy_pos.y + 8
    * 4))))
        if ((sfTime_asSeconds(obj->gametime) - sfTime_asSeconds
        (obj->play_hit)) > 0.5f) {
            obj->player->hp -= obj->boss.damage;
            obj->play_hit = obj->gametime;
        }
}