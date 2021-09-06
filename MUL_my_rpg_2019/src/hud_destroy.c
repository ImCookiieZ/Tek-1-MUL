/*
** EPITECH PROJECT, 2019
** hud
** File description:
** ksjdlfökjs
*/

#include "../include/all_includes.h"

void hud_destroy(objects *obj)
{
    if (obj->is_hud_set > 0) {
        sfSprite_destroy(obj->hud->hb_black);
        sfSprite_destroy(obj->hud->hb_red);
        sfSprite_destroy(obj->hud->hb_frame);
        sfTexture_destroy(obj->hud->hb_black_t);
        sfTexture_destroy(obj->hud->hb_red_t);
        sfTexture_destroy(obj->hud->hb_frame_t);
        free(obj->hud->xp_string);
        sfSprite_destroy(obj->hud->xp_blue);
        sfTexture_destroy(obj->hud->xp_blue_t);
        if (obj->is_hud_set == 2) {
            sfSprite_destroy(obj->hud->player);
            sfTexture_destroy(obj->hud->player_t);
            sfSprite_destroy(obj->hud->icons);
            sfTexture_destroy(obj->hud->icons_t);
        }
        free(obj->hud);
    }
}