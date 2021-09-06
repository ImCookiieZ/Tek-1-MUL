/*
** EPITECH PROJECT, 2019
** hud_init_two.c
** File description:
** lksjdf
*/

#include "../include/all_includes.h"

void set_cooldown_box(const objects *obj, sfVector2f *vec, sfVector2f *scale)
{
    sfVector2f origin = {23, 23};

    sfSprite_setPosition(obj->hud->cd_one, (*vec));
    sfSprite_setScale(obj->hud->cd_one, (*scale));
    (*vec).x += 88;
    sfSprite_setPosition(obj->hud->cd_two, (*vec));
    sfSprite_setScale(obj->hud->cd_two, (*scale));
    (*vec).x += 89;
    sfSprite_setScale(obj->hud->cd_three, (*scale));
    sfSprite_setPosition(obj->hud->cd_three, (*vec));
    sfSprite_setOrigin(obj->hud->cd_one, origin);
    sfSprite_setOrigin(obj->hud->cd_two, origin);
    sfSprite_setOrigin(obj->hud->cd_three, origin);

}

void init_cooldown_box(objects *obj)
{
    sfTexture *cd_t = NULL;
    sfSprite *cd_one = NULL;
    sfSprite *cd_two = NULL;
    sfSprite *cd_three = NULL;
    sfVector2f vec = {580, 903};
    sfVector2f scale = {1.4, 1.4};
    cd_t = sfTexture_createFromFile("assets/cooldownbox.png", NULL);
    cd_one = create_my_sprite(cd_one, cd_t);
    cd_two = create_my_sprite(cd_two, cd_t);
    cd_three = create_my_sprite(cd_three, cd_t);
    obj->hud->cooldown_box = cd_t;
    obj->hud->cd_one = cd_one;
    obj->hud->cd_two = cd_two;
    obj->hud->cd_three = cd_three;
    set_cooldown_box(obj, &vec, &scale);
}

void init_healthbar_two(objects *obj)
{
    sfSprite *hb_black = NULL;
    sfSprite *hb_red = NULL;
    sfTexture *hb_black_t = NULL;
    sfTexture *hb_red_t = NULL;

    hb_red_t = sfTexture_createFromFile("assets/hgreen.png", NULL);
    hb_red = create_my_sprite(hb_red, hb_red_t);
    obj->hud->hb_red = hb_red;
    obj->hud->hb_red_t = hb_red_t;
    hb_black_t = sfTexture_createFromFile("assets/hred.png", NULL);
    hb_black = create_my_sprite(hb_black, hb_black_t);
    obj->hud->hb_black = hb_black;
    obj->hud->hb_black_t = hb_black_t;
}

void init_healthbar(objects *obj)
{
    sfSprite *hb_frame = NULL;
    sfTexture *hb_frame_t = NULL;
    sfVector2f vec = {70, 860};

    hb_frame_t = sfTexture_createFromFile("assets/hb_red.png", NULL);
    hb_frame = create_my_sprite(hb_frame, hb_frame_t);
    obj->hud->hb_frame_t = hb_frame_t;
    obj->hud->hb_frame = hb_frame;
    sfSprite_setPosition(obj->hud->hb_frame, vec);
    vec.x += 70;
    vec.y += 20;
    init_healthbar_two(obj);
    sfSprite_setPosition(obj->hud->hb_red, vec);
    sfSprite_setPosition(obj->hud->hb_black, vec);
}

int init_hud_strings(objects *obj)
{
    char *lvl = malloc(sizeof(char) * 8);
    char *xp = malloc(sizeof(char) * 8);

    if (lvl == NULL)
        return -1;
    lvl[0] = '\0';
    lvl = my_strcat(lvl, "Level: \0");
    obj->hud->level_string = lvl;

    if (xp == NULL)
        return -1;
    xp[0] = '\0';
    xp = my_strcat(xp, "XP: \0");
    obj->hud->xp_string = xp;
    return 0;
}
