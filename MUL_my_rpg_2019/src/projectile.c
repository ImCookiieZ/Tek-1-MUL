/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

const float cooldown[3] = {0.5f, 1.5f, 0.02f};

int *get_dir(void)
{
    int *dirs = malloc(sizeof(int) * 4);
    if (dirs == NULL)
        return (0);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        dirs[0] = 1;
    else
        dirs[0] = 0;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        dirs[1] = 1;
    else
        dirs[1] = 0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        dirs[2] = 1;
    else
        dirs[2] = 0;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        dirs[3] = 1;
    else
        dirs[3] = 0;
    return (dirs);
}

void set_player_dir(player_t *player, const int *dirs)
{
    if (!dirs[2] && dirs[3]) {
        player->dir = 2;
        if (!player->move_vec.x && !player->move_vec.y)
            player->dir += 4;
    }
    if (dirs[2] && !dirs[3]) {
        player->dir = 4;
        if (!player->move_vec.x && !player->move_vec.y)
            player->dir += 4;
    }
    if (!dirs[2] && !dirs[3] && dirs[1] && !dirs[0]) {
        player->dir = 3;
        if (!player->move_vec.x && !player->move_vec.y)
            player->dir += 4;
    }
    if (!dirs[2] && !dirs[3] && !dirs[1] && dirs[0]) {
        player->dir = 1;
        if (!player->move_vec.x && !player->move_vec.y)
            player->dir += 4;
    }
}

float get_cooldown(int skill, float beam)
{
    float ret = cooldown[skill - 1];

    if (skill == 3)
        ret += beam;
    return (ret);
}

void check_new_projectile(objects *obj)
{
    projectile_t *og = obj->projectile;
    float diff = sfTime_asSeconds(obj->gametime) - sfTime_asSeconds
        (obj->tmtime);
    int *dirs = get_dir();
    if (dirs[0] || dirs[1] || dirs[2] || dirs[3]) {
        if (diff > get_cooldown(obj->skill_index, obj->beamcd)) {
            og = add_projectile(obj, dirs);
            obj->tmtime = obj->gametime;
        }
        if (!(!dirs[0] && !dirs[1] && !dirs[2] && !dirs[3]) &&
            !(dirs[0] && dirs[1] && dirs[2] && dirs[3]) &&
            !(dirs[0] && dirs[1] && !dirs[2] && !dirs[3]) &&
            !(!dirs[0] && !dirs[1] && dirs[2] && dirs[3])) {
            set_player_dir(obj->player, dirs);
            obj->player->is_acting = 1;
        } else obj->player->is_acting = 0;
    } else obj->player->is_acting = 0;
    if (obj->player->is_acting == 0 && obj->beamcd > 0) obj->beamcd -= 0.0015f;
    if (obj->skill_index == 3 && obj->player->is_acting) obj->beamcd += 0.001f;
    free(dirs);
    obj->projectile = og;
}

void change_skill(objects *obj)
{
    if (sfTime_asSeconds(obj->gametime) - sfTime_asSeconds(obj->change_skill) >
        0.2) {
        if (sfKeyboard_isKeyPressed(sfKeyNum1))
            obj->skill_index = 1;
        if (sfKeyboard_isKeyPressed(sfKeyNum2) && obj->player->level > 0)
            obj->skill_index = 2;
        if (sfKeyboard_isKeyPressed(sfKeyNum3) && obj->player->level > 1)
            obj->skill_index = 3;
        obj->change_skill = obj->gametime;
    }
}