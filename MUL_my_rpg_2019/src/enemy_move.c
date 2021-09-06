/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

float my_abs(float i)
{
    if (i < 0)
        i *= -1;
    return (i);
}

int check_enemy_collision(sfVector2f pos, sfVector2f move, objects *obj)
{
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((pos.y + move.y) / 4.3 /
    16)][(int) ((pos.x + move.x + 8 * 4) / 4.3 / 16)] != 0) return (1);
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((pos.y + move.y) / 4.3 /
    16)][(int) ((pos.x + move.x - 8 * 4) / 4.3 / 16)] != 0) return (1);
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((pos.y + move.y) / 4.3 /
    16)][(int) ((pos.x + move.x) / 4.3 / 16)] != 0) return (1);
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((pos.y + move.y + 8 * 4) /
    4.3 / 16)][(int) ((pos.x + move.x + 8 * 4) / 4.3 / 16)] != 0) return (1);
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((pos.y + move.y + 8 * 4) /
    4.3 / 16)][(int) ((pos.x + move.x - 8 * 4) / 4.3 / 16)] != 0) return (1);
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((pos.y + move.y + 8 * 4) /
    4.3 / 16)][(int) ((pos.x + move.x) / 4.3 / 16)] != 0) return (1);
    return (0);
}

sfVector2f check_move(sfVector2f pos, sfVector2f move, objects *obj)
{
    float tmp = 0;
    if (check_enemy_collision(pos, move, obj)) {
        tmp = move.y;
        move.y = 0;
    }
    if (check_enemy_collision(pos, move, obj)) {
        move.y = tmp;
        tmp = move.x;
        move.x = 0;
    }
    if (check_enemy_collision(pos, move, obj))
        move.y = 0;
    return (move);
}

sfVector2f round_move(sfVector2f move)
{
    float i = 0;
    if (my_abs(move.x) > my_abs(move.y)) i = move.x;
    else i = move.y;
    if (i < 0) i *= -1;
    while (i < 2.5) {
        if (i == 0) i += 0.01f;
        i *= 1.1f;
        if (move.x > 0) move.x *= 1.1f;
        else move.x /= 0.91f;
        if (move.y > 0) move.y *= 1.1f;
        else move.y /= 0.91f;
    }
    while (i > 2.5) {
        i /= 1.1f;
        if (move.x < 0) move.x *= 0.91f;
        else move.x /= 1.1f;
        if (move.y < 0) move.y *= 0.91f;
        else move.y /= 1.1f;
    }
    return (move);
}

void move_enemy(enemy_t *enemy, sfVector2f target, objects *obj)
{
    sfVector2f move = {0, 0};
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    move.x = (target.x - pos.x);
    move.y = (target.y - pos.y);
    move = round_move(move);
    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy->move_clock)) > 0.016) {
        sfSprite_move(enemy->sprite, check_move(pos, move, obj));
        sfClock_restart(enemy->move_clock);
    }
}