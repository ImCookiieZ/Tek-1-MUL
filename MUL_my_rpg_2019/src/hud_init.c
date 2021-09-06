/*
** EPITECH PROJECT, 2019
** hud_init.c
** File description:
** hud
*/

#include "../include/all_includes.h"

void init_hud_xp_bar(objects *obj)
{
    sfSprite *xp = NULL;
    sfTexture *xp_t = NULL;
    sfVector2f vec = {105, 33};

    xp_t = sfTexture_createFromFile("assets/xp_blue.png", NULL);
    xp = create_my_sprite(xp, xp_t);
    obj->hud->xp_blue = xp;
    obj->hud->xp_blue_t = xp_t;
    sfSprite_setPosition(obj->hud->xp_blue, vec);
}

void init_hud_frame(objects *obj)
{
    sfSprite *hb_frame = NULL;
    sfTexture *hb_frame_t = NULL;
    sfVector2f vec = {10, 10};

    if (obj->player->gender == 0)
        hb_frame_t = sfTexture_createFromFile(
            "assets/hud_frame_blue.png", NULL);
    else
        hb_frame_t = sfTexture_createFromFile(
            "assets/hud_frame_pink.png", NULL);
    hb_frame = create_my_sprite(hb_frame, hb_frame_t);
    obj->hud->xp_frame = hb_frame;
    obj->hud->xp_frame_t = hb_frame_t;
    sfSprite_setPosition(obj->hud->xp_frame, vec);
}

void init_hud_player_image(objects *obj, int choice)
{
    sfSprite *player = NULL;
    sfTexture *player_t = NULL;
    sfVector2f vec = {35, 30};

    obj->is_hud_set = 2;
    obj->hud->layer = choice - 1;
    player_t = sfTexture_createFromFile("assets/player_in_hud.png", NULL);
    player = create_my_sprite(player, player_t);
    obj->hud->player = player;
    obj->hud->player_t = player_t;
    sfSprite_setPosition(obj->hud->player, vec);
}

void init_hud_icons(objects *obj)
{
    sfSprite *icons = NULL;
    sfTexture *icons_t = NULL;
    sfVector2f vec = {540, 860};
    sfVector2f vec_scale = {1.4, 1.4};

    icons_t = sfTexture_createFromFile("assets/hud_icons.png", NULL);
    icons = create_my_sprite(icons, icons_t);
    obj->hud->icons = icons;
    obj->hud->icons_t = icons_t;
    sfSprite_setPosition(obj->hud->icons, vec);
    sfSprite_setScale(obj->hud->icons, vec_scale);
}

int init_hud(objects *obj)
{
    hud_t *hud = malloc(sizeof(hud_t));

    if (hud == NULL)
        return -1;
    obj->hud = hud;
    obj->is_hud_set = 1;
    init_cooldown_box(obj);
    init_healthbar(obj);
    if (init_hud_strings(obj) == -1)
        return -1;
    init_hud_xp_bar(obj);
    init_hud_icons(obj);
    return 0;
}