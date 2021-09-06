/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_collisions.c
*/

#include "../include/all_includes.h"
#include "../include/player_collision_size.h"

int first_three_cols(objects *obj, float x, float y, double x_box)
{
    float scale = 2.2;
    if (obj->player->move_vec.y <= 0 && obj->player->move_vec.x >= 0)
        if (obj->map_col[obj->map_y][obj->map_x][(int) (
            ((y + obj->player->move_vec.y) / 4.3) / 16)][(int) (
            ((x + obj->player->move_vec.x + x_box * scale) / 4.3) / 16)] != 0)
            return (1);
    if (obj->player->move_vec.y <= 0 && obj->player->move_vec.x <= 0)
        if (obj->map_col[obj->map_y][obj->map_x][(int) (
            ((y + obj->player->move_vec.y) / 4.3) / 16)][(int) (
            ((x + obj->player->move_vec.x - x_box * scale) / 4.3) / 16)] != 0)
            return (1);
    if (obj->player->move_vec.y < 0 && obj->player->move_vec.x == 0)
        if (obj->map_col[obj->map_y][obj->map_x][(int) (
            ((y + obj->player->move_vec.y) / 4.3) / 16)][(int) (
            ((x + obj->player->move_vec.x) / 4.3) / 16)] != 0)
            return (1);
    return (0);
}

int second_three_cols(objects *obj, float y, double x_box, double y_box)
{
    float x = sfSprite_getPosition(obj->player->sprite).x;
    float scale = 2.2;
    if (obj->player->move_vec.y >= 0 && obj->player->move_vec.x >= 0) {
        if (obj->map_col[obj->map_y][obj->map_x][(int) (
            ((y + obj->player->move_vec.y + y_box * scale) / 4.3) / 16)][(int) (
            ((x + obj->player->move_vec.x + x_box * scale) / 4.3) / 16)] != 0)
            return (1);
    }
    if (obj->player->move_vec.y >= 0 && obj->player->move_vec.x <= 0) {
        if (obj->map_col[obj->map_y][obj->map_x][(int) (
            ((y + obj->player->move_vec.y + y_box * scale) / 4.3) / 16)][(int) (
            ((x + obj->player->move_vec.x - x_box * scale) / 4.3) / 16)] != 0)
            return (1);
    }
    if (obj->player->move_vec.y > 0 && obj->player->move_vec.x == 0) {
        if (obj->map_col[obj->map_y][obj->map_x][(int) (
            ((y + obj->player->move_vec.y + y_box * scale) / 4.3) / 16)][(int) (
            ((x + obj->player->move_vec.x) / 4.3) / 16)] != 0)
            return (1);
    }
    return (0);
}

int is_collision(objects *obj)
{
    float x = sfSprite_getPosition(obj->player->sprite).x;
    float y = sfSprite_getPosition(obj->player->sprite).y;

    if (x + obj->player->move_vec.x < 0 || y + obj->player->move_vec.y < 0 ||
        x + obj->player->move_vec.x > 1920 ||
        y + obj->player->move_vec.y > 1080) {
        return (1);
    }
    double x_box = p_c_s[obj->player->choice - 1][obj->player->level][1][0] / 2;
    double y_box = p_c_s[obj->player->choice - 1][obj->player->level][1][1] / 2;
    if (obj->player->move_vec.x == 0) {
        x_box = p_c_s[obj->player->choice - 1][obj->player->level][0][0] / 2;
        y_box = p_c_s[obj->player->choice - 1][obj->player->level][0][1] / 2;
    }
    y_box += 3.1 + obj->player->level;
    if (first_three_cols(obj, x, y, x_box)) return (1);
    if (second_three_cols(obj, y, x_box, y_box)) return (1);
    if (ismy_link(obj) == 1) do_the_change(obj);
    return (0);
}