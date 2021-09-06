/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void hit_projectile(objects *obj)
{
    sfVector2f proj_pos = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f enemy_pos = {0, 0};
    enemy_t  *og = obj->enemy;

    for (; obj->enemy != NULL; obj->enemy = obj->enemy->next) {
        enemy_pos = sfSprite_getPosition(obj->enemy->sprite);
        if ((((proj_pos.x - 4 * 4) <= (enemy_pos.x + 8 * 4) && (proj_pos.x - 4 *
        4) >= (enemy_pos.x - 8 * 4)) || ((proj_pos.x + 4 * 4) >= (enemy_pos.x
        - 8 * 4) && (proj_pos.x + 4 * 4) <= enemy_pos.x + 8 * 4)) && (((proj_pos
        .y - 2 * 4) <= (enemy_pos.y + 8 * 4) && (proj_pos.y - 2 * 4) >=
        (enemy_pos.y - 8 * 4)) || ((proj_pos.y + 2 * 4) >= (enemy_pos.y - 8 *
        4) && (proj_pos.y + 2 * 4) <= (enemy_pos.y + 8 * 4)))) {
            obj->enemy->hp -= obj->player->damage * 0.5 * mult_effective
                (obj->player->choice, obj->enemy->type);
            obj->projectile->hit = 1;
        }
    }
    obj->enemy = og;
}

void hit_wave(objects *obj)
{
    sfVector2f proj_pos = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f enemy_pos = {0, 0};
    enemy_t  *og = obj->enemy;

    for (; obj->enemy != NULL; obj->enemy = obj->enemy->next) {
        enemy_pos = sfSprite_getPosition(obj->enemy->sprite);
        if ((((proj_pos.x - 4 * 3) <= (enemy_pos.x + 8 * 4) && (proj_pos.x - 4 *
        3) >= (enemy_pos.x - 8 * 4)) || ((proj_pos.x + 4 * 3) >= (enemy_pos.x
        - 8 * 4) && (proj_pos.x + 4 * 3) <= enemy_pos.x + 8 * 4)) && (((proj_pos
        .y - 9 * 3) <= (enemy_pos.y + 8 * 4) && (proj_pos.y - 9 * 3) >=
        (enemy_pos.y - 8 * 4)) || ((proj_pos.y + 9 * 3) >= (enemy_pos.y - 8 *
        4) && (proj_pos.y + 9 * 3) <= (enemy_pos.y + 8 * 4))))
            if (sfTime_asSeconds(obj->gametime) - sfTime_asSeconds(obj
            ->enemy->last_hit) > 0.5) {
                obj->enemy->hp -= obj->player->damage * 0.5 * mult_effective
                    (obj->player->choice, obj->enemy->type);
                obj->enemy->last_hit = obj->gametime;
            }
    }
    obj->enemy = og;
}

void hit_beam(objects *obj, float offset_x, float offset_y)
{
    sfVector2f proj_pos = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f enemy_pos = {0, 0};
    enemy_t  *og = obj->enemy;

    for (; obj->enemy != NULL; obj->enemy = obj->enemy->next) {
        enemy_pos = sfSprite_getPosition(obj->enemy->sprite);
        if ((((proj_pos.x - 7 * 4) <= (enemy_pos.x + 8 * 4) && (proj_pos.x -
        7 * 4) >= (enemy_pos.x - 8 * 4)) || ((proj_pos.x + 7 * 4) >=
        (enemy_pos.x - 8 * 4) && (proj_pos.x + 7 * 4) <= enemy_pos.x + 8 *
        4)) && (((proj_pos.y - 2 * 3) <= (enemy_pos.y + 8 * 4) && (proj_pos.y
        - 2 * 3) >= (enemy_pos.y - 8 * 4)) || ((proj_pos.y + 2 * 3) >=
        (enemy_pos.y - 8 * 4) && (proj_pos.y + 2 * 3) <= (enemy_pos.y + 8 *
        4)))) {
            obj->enemy->hp -= ((float) obj->player->damage / 10) *
                (float) mult_effective(obj->player->choice, obj->enemy->type);
        }
    }
    if (obj->map_y == 1 && obj->map_x == 3 && obj->stone_destroyed == 0)
        hit_stone(obj, offset_x, offset_y);
    obj->enemy = og;
}