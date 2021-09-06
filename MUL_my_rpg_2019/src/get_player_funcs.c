/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_player_funcs.c
*/

#include "../include/all_includes.h"
float PLAYER_SPEED  = 3;
float NORMAL_SPEED = 3;
float CHEAT_SPEED = 8;

int *get_player_dir(objects *object)
{
    int *dirs = malloc(sizeof(int) * 4);
    if (dirs == NULL)
        return (0);
    if (sfKeyboard_isKeyPressed(object->settings->up))
        dirs[0] = 1;
    else
        dirs[0] = 0;
    if (sfKeyboard_isKeyPressed(object->settings->down))
        dirs[1] = 1;
    else
        dirs[1] = 0;
    if (sfKeyboard_isKeyPressed(object->settings->left))
        dirs[2] = 1;
    else
        dirs[2] = 0;
    if (sfKeyboard_isKeyPressed(object->settings->right))
        dirs[3] = 1;
    else
        dirs[3] = 0;
    return (dirs);
}

sfVector2f get_player_move(int *dirs)
{
    sfVector2f move = {0, 0};

    if (dirs[0] && !dirs[1])
        move.y = -PLAYER_SPEED;
    if (!dirs[0] && dirs[1])
        move.y = PLAYER_SPEED;
    if (dirs[2] && !dirs[3])
        move.x = -PLAYER_SPEED;
    if (!dirs[2] && dirs[3])
        move.x = PLAYER_SPEED;
    return (move);
}

int get_player_anim(sfVector2f move, int cur_dir)
{
    if (!move.x && !move.y && cur_dir < 5)
        return (cur_dir + 4);
    if (move.x > 0)
        return (2);
    else if (move.x < 0)
        return (4);
    if (move.y > 0)
        return (3);
    else if (move.y < 0)
        return (1);
    return (cur_dir);
}

void my_cheats(objects *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed(sfKeyF))
        PLAYER_SPEED = CHEAT_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed(sfKeyH))
        obj->player->hp = obj->player->max_hp;
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed(sfKeyL))
        obj->player->xp++;
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed(sfKeyD))
        obj->player->damage = 1000;
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed(sfKeyN))
        PLAYER_SPEED = NORMAL_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed
        (sfKeyE)) {
        evolution(obj);
    }
    if (sfKeyboard_isKeyPressed(sfKeyK) && sfKeyboard_isKeyPressed(sfKeyS))
        save_game(obj);
}

void get_player_direction(objects *obj)
{
    int *dirs = get_player_dir(obj);

    obj->player->move_vec = get_player_move(dirs);
    if (!obj->player->is_acting)
        obj->player->dir = get_player_anim(obj->player->move_vec, obj->player
            ->dir);
    my_cheats(obj);
    free(dirs);
}