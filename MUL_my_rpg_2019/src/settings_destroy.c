/*
** EPITECH PROJECT, 2019
** Marcel Taubert - > settings_destroy.c
** File description:
** sedd
*/

#include "../include/all_includes.h"

void settings_destroy(objects *obj)
{
    free(obj->settings->sound_string);
    free(obj->settings->music_string);
    free(obj->settings->right_string);
    free(obj->settings->up_string);
    free(obj->settings->down_string);
    free(obj->settings->left_string);
    sfTexture_destroy(obj->settings->black_bar_t);
    sfTexture_destroy(obj->settings->grey_bar_t);
    sfTexture_destroy(obj->settings->red_bar_t);
    sfSprite_destroy(obj->settings->black_bar_sound);
    sfSprite_destroy(obj->settings->black_bar_mus);
    sfSprite_destroy(obj->settings->red_bar_sound);
    sfSprite_destroy(obj->settings->red_bar_mus);
    sfSprite_destroy(obj->settings->grey_bar_sound);
    sfSprite_destroy(obj->settings->grey_bar_mus);
    sfSprite_destroy(obj->settings->grey_bar_fps);
    sfSprite_destroy(obj->settings->red_bar_fps);
    sfSprite_destroy(obj->settings->black_bar_fps);
    free(obj->settings);
}