/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void anim_sprites(sfSprite *b, sfSprite *c, sfSprite *s, sfRenderWindow *window)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(window);
    sfIntRect standard = {0, 0, 80, 80};
    sfIntRect hovered = {80, 0, 80 , 80};
    sfVector2f pos_b = {800, 500};
    sfVector2f pos_c = {300, 500};
    sfVector2f pos_s = {1300, 500};

    sfSprite_setPosition(b, pos_b);
    sfSprite_setPosition(c, pos_c);
    sfSprite_setPosition(s, pos_s);
    sfSprite_setTextureRect(c, standard);
    sfSprite_setTextureRect(b, standard);
    sfSprite_setTextureRect(s, standard);
    if ((m.x >= 300 && m.x <= 650) && (m.y >= 800 && m.y <= 860))
        sfSprite_setTextureRect(c, hovered);
    if ((m.x >= 850 && m.x <= 1150) && (m.y >= 800 && m.y <= 860))
        sfSprite_setTextureRect(b, hovered);
    if ((m.x >= 1350 && m.x <= 1590) && (m.y >= 800 && m.y <= 860))
        sfSprite_setTextureRect(s, hovered);
}

void scale_draw_anim(sfRenderWindow *window, sfSprite *baulba_s,
    sfSprite *chari_s, sfSprite *squirtle_s)
{
    sfVector2f scale = {4, 4};
    sfSprite_setScale(baulba_s, (scale));
    sfSprite_setScale(chari_s, (scale));
    sfSprite_setScale(squirtle_s, (scale));
    anim_sprites(baulba_s, chari_s, squirtle_s, window);
    sfRenderWindow_drawSprite(window, baulba_s, NULL);
    sfRenderWindow_drawSprite(window, chari_s, NULL);
    sfRenderWindow_drawSprite(window, squirtle_s, NULL);
}

void draw_choice_sprites(sfRenderWindow *window)
{
    sfTexture *baulba = sfTexture_createFromFile("assets/bisasam_c.png", NULL);
    sfTexture *chari = sfTexture_createFromFile("assets/glumanda_c.png", NULL);
    sfTexture *squirtle = sfTexture_createFromFile("assets/shiggy_c.png", NULL);
    sfSprite *baulba_s = NULL;
    sfSprite *chari_s = NULL;
    sfSprite *squirtle_s = NULL;
    baulba_s = create_my_sprite(baulba_s, baulba);
    chari_s = create_my_sprite(chari_s, chari);
    squirtle_s = create_my_sprite(squirtle_s, squirtle);
    scale_draw_anim(window, baulba_s, chari_s, squirtle_s);
    sfSprite_destroy(baulba_s);
    sfSprite_destroy(chari_s);
    sfSprite_destroy(squirtle_s);
    sfTexture_destroy(baulba);
    sfTexture_destroy(chari);
    sfTexture_destroy(squirtle);
}