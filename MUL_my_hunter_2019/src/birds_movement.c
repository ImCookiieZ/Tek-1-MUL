/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/functions.h"
#include "../include/params_struct.h"

int sprite_prepare(sfVector2f pos, sfRenderWindow *window, sfVector2f scale, \
    char *path)
{
    sfSprite *sprite;
    sfTexture *texture;

    texture = sfTexture_createFromFile(path, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_scale(sprite, scale);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    return (0);
}

int sprite_prepare2(sfVector2f pos, sfRenderWindow *window, sfVector2f scale, \
    sfTexture *birds)
{
    sfSprite *sprite;
    sfTexture *texture;

    texture = birds;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_scale(sprite, scale);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    return (0);
}

int fall_down(sfRenderWindow *window, int ar[2], sfVector2f *pos_down, \
    int const *r)
{
    sfVector2f scale[ar[0]];
    int a = 0;

    for (int i = 0; i < ar[0]; i++) {
        scale[i].x = (float) r[i];
        scale[i].y = (float) r[i];
    }
    if (ar[1] == 1)
        sprite_prepare(pos_down[ar[0]- 1], window, \
        scale[ar[0] - 1], "pictures/blue_down.png");
    for (int i = 0; i < ar[0] - ar[1]; i++) {
        if (pos_down[i].y > 900)
            a++;
        else
            sprite_prepare(pos_down[i], window, \
            scale[i], "pictures/blue_down2.png");
    }
    return (ar[0] - a);
}

sfVector2f my_printing(float const ar[3], sfVector2f pos, \
    sfRenderWindow *window, sfTexture *birds[3][2])
{
    int a = 0;
    int o = 0;

    srand(time(0));
    sfVector2f begin[2] = {{-35,  rand() % 700 + 80}, \
    {1280, rand() % 700 + 80}};
    sfVector2f end = {1279, -100};
    sfVector2f scaling = {ar[0], ar[0]};
    if (ar[1] < 0)
        a = 1;
    if ((int) ar[2] % 4 == 0)
        o = 0;
    else if ((int)ar[2] % 4 == 2)
        o = 2;
    else
        o = 1;
    sprite_prepare2(pos, window, scaling, birds[o][a]);
    if (pos.x > end.x || pos.x < end.y)
        pos = begin[a];
    return (pos);
}

int change_cursor(sfTexture *texture, params para)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f mousepos;
    sfVector2f scale = {0.1, 0.1};

    mousepos.x = (float) sfMouse_getPositionRenderWindow(para.window).x - 45;
    mousepos.y = (float) sfMouse_getPositionRenderWindow(para.window).y - 45;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, mousepos);
    sfSprite_scale(sprite, scale);
    sfRenderWindow_drawSprite(para.window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfRenderWindow_drawText(para.window, para.numberScore, NULL);
    sfRenderWindow_drawText(para.window, para.scoreText, NULL);
    sfRenderWindow_display(para.window);
    return (0);
}