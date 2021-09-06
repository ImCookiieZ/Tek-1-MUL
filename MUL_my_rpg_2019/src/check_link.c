/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_link.c
*/

#include "../include/all_includes.h"
extern double p_c_s[3][3][2][3];

int check_top_right(objects *obj)
{
    float scale = 2.2;
    float x = sfSprite_getPosition(obj->player->sprite).x;
    float y = sfSprite_getPosition(obj->player->sprite).y;
    double x_box = p_c_s[obj->player->choice - 1][obj->player->level][1][0] / 2;
    if (obj->player->move_vec.x == 0)
        x_box = p_c_s[obj->player->choice - 1][obj->player->level][0][0] / 2;
    if (obj->map_link[obj->map_y][obj->map_x][(int) (
        ((y + obj->player->move_vec.y) / 4.3) / 16)][(int) (
        ((x + obj->player->move_vec.x + x_box * scale) / 4.3) / 16)] != 0)
        return (1);
    return (0);
}

int check_top_left(objects *obj)
{
    float scale = 2.2;
    float x = sfSprite_getPosition(obj->player->sprite).x;
    float y = sfSprite_getPosition(obj->player->sprite).y;
    double x_box = p_c_s[obj->player->choice - 1][obj->player->level][1][0] / 2;
    if (obj->player->move_vec.x == 0)
        x_box = p_c_s[obj->player->choice - 1][obj->player->level][0][0] / 2;
    if (obj->map_link[obj->map_y][obj->map_x][(int) (
        ((y + obj->player->move_vec.y) / 4.3) / 16)][(int) (
        ((x + obj->player->move_vec.x - x_box * scale) / 4.3) / 16)] != 0)
        return (1);
    return (0);
}

int check_right_down(objects *obj)
{
    float x = sfSprite_getPosition(obj->player->sprite).x;
    float y = sfSprite_getPosition(obj->player->sprite).y;
    double x_box = p_c_s[obj->player->choice - 1][obj->player->level][1][0] / 2;
    double y_box = p_c_s[obj->player->choice - 1][obj->player->level][1][1] / 2;
    float scale = 2.2;
    if (obj->player->move_vec.x == 0) {
        x_box = p_c_s[obj->player->choice - 1][obj->player->level][0][0] / 2;
        y_box = p_c_s[obj->player->choice - 1][obj->player->level][1][1] / 2;
    }
    y_box += 3.1 + obj->player->level;
    if ((obj->map_link[obj->map_y][obj->map_x][(int) (
        ((y + obj->player->move_vec.y + y_box * scale) / 4.3) / 16)][(int) (
        ((x + obj->player->move_vec.x + x_box * scale) / 4.3) / 16)] != 0))
        return (1);
    return (0);
}

int check_left_down(objects *obj)
{
    float x = sfSprite_getPosition(obj->player->sprite).x;
    float y = sfSprite_getPosition(obj->player->sprite).y;
    float scale = 2.2;
    double x_box = p_c_s[obj->player->choice - 1][obj->player->level][1][0] / 2;
    double y_box = p_c_s[obj->player->choice - 1][obj->player->level][1][1] / 2;
    if (obj->player->move_vec.x == 0) {
        x_box = p_c_s[obj->player->choice - 1][obj->player->level][0][0] / 2;
        y_box = p_c_s[obj->player->choice - 1][obj->player->level][1][1] / 2;
    }
    y_box += 3.1 + obj->player->level;
    if ((obj->map_link[obj->map_y][obj->map_x][(int) (
        ((y + obj->player->move_vec.y + y_box * scale) / 4.3) / 16)][(int) (
        ((x + obj->player->move_vec.x - x_box * scale) / 4.3) / 16)] != 0))
        return (1);
    return (0);
}

int ismy_link(objects *obj)
{
    int right_up = 0;
    int left_up = 0;
    int right_down = 0;
    int left_down = 0;
    right_up = check_top_right(obj);
    left_up = check_top_left(obj);
    right_down = check_right_down(obj);
    left_down = check_left_down(obj);
    if ((left_down && left_up) || (left_up && right_up) || (right_up &&
    right_down) || (left_down && right_down))
        return (1);
    return (0);
}
