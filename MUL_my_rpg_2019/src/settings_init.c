/*
** EPITECH PROJECT, 2019
** settings_init.c
** File description:
** sdf
*/

#include "../include/all_includes.h"

void init_grey(objects *objects)
{
    sfSprite *grey = NULL;
    sfSprite *grey_sound = NULL;
    sfSprite *grey_fps = NULL;
    sfTexture *grey_t = NULL;
    sfVector2f vec = {1045 - 50, 525 - 300};
    sfVector2f vec2 = {1045 - 50, 625 - 300};
    sfVector2f vec3 = {1045 - 50, 725 - 300};

    grey_t = sfTexture_createFromFile("assets/gray.png", NULL);
    grey = create_my_sprite(grey, grey_t);
    objects->settings->grey_bar_mus = grey;
    sfSprite_setPosition(objects->settings->grey_bar_mus, vec);
    grey_sound = create_my_sprite(grey_sound, grey_t);
    objects->settings->grey_bar_sound = grey_sound;
    sfSprite_setPosition(objects->settings->grey_bar_sound, vec2);
    grey_fps = create_my_sprite(grey_fps, grey_t);
    objects->settings->grey_bar_fps = grey_fps;
    sfSprite_setPosition(objects->settings->grey_bar_fps, vec3);
    objects->settings->grey_bar_t = grey_t;
    init_red(objects);
}

void init_red(objects *objects)
{
    sfSprite *red = NULL;
    sfSprite *red_sound = NULL;
    sfSprite *red_fps = NULL;
    sfTexture *red_t = NULL;
    sfVector2f vec = {1047 - 50, 535 - 300};
    sfVector2f vec2 = {1047 - 50, 635 - 300};
    sfVector2f vec3 = {1047 - 50, 735 - 300};

    red_t = sfTexture_createFromFile("assets/red.png", NULL);
    red = create_my_sprite(red, red_t);
    objects->settings->red_bar_mus = red;
    sfSprite_setPosition(objects->settings->red_bar_mus, vec);
    red_sound = create_my_sprite(red_sound, red_t);
    objects->settings->red_bar_sound = red_sound;
    sfSprite_setPosition(objects->settings->red_bar_sound, vec2);
    red_fps = create_my_sprite(red_fps, red_t);
    objects->settings->red_bar_fps = red_fps;
    sfSprite_setPosition(objects->settings->red_bar_fps, vec3);
    objects->settings->red_bar_t = red_t;
    init_black(objects);
}

void init_black(objects *objects)
{
    sfSprite *black = NULL;
    sfSprite *black_sound = NULL;
    sfSprite *black_fps = NULL;
    sfTexture *black_t = NULL;
    sfVector2f vec = {1049 + 300 - 210, 537 - 300};
    sfVector2f vec2 = {1049 + 300 - 10, 637 - 300};
    sfVector2f vec3 = {1049 + 300 - 310, 737 - 300};

    black_t = sfTexture_createFromFile("assets/black.png", NULL);
    black = create_my_sprite(black, black_t);
    objects->settings->black_bar_mus = black;
    sfSprite_setPosition(objects->settings->black_bar_mus, vec);
    black_sound = create_my_sprite(black_sound, black_t);
    objects->settings->black_bar_sound = black_sound;
    sfSprite_setPosition(objects->settings->black_bar_sound, vec2);
    black_fps = create_my_sprite(black_fps, black_t);
    objects->settings->black_bar_fps = black_fps;
    sfSprite_setPosition(objects->settings->black_bar_fps, vec3);
    objects->settings->black_bar_t = black_t;

}

int init_settings(objects *objects)
{
    settings_t *set = malloc(sizeof(settings_t));

    if (set == NULL)
        return -1;
    objects->settings = set;
    objects->settings->left = sfKeyA;
    objects->settings->right = sfKeyD;
    objects->settings->up = sfKeyW;
    objects->settings->down = sfKeyS;
    objects->settings->music = 100;
    objects->settings->sounds = 100;
    objects->settings->pause = sfKeyEscape;
    objects->settings->attack_one = sfKeyQ;
    objects->settings->attack_two = sfKeyE;
    objects->settings->attack_three = sfKeyR;
    objects->settings->fps = 60;

    init_grey(objects);
    init_strings(objects);
    return 0;
}