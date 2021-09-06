/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"
#include <string.h>

const double settings_texts[9][4] = {
        {670, 200, 80, 190},
        {820, 900, 80, 180},
        {670, 300, 80, 190},
        {670, 500, 80, 290},
        {1320, 180, 100, 190},
        {1320, 280, 100, 190},
        {670, 400, 80, 190},
        {1320, 380, 100, 190},
        {10, 10, 20, 20}
};

int is_sprite_hit(objects *obj, sfSprite *sprite, int width, int height)
{
    sfVector2i vec_mouse = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f vec_sprite = sfSprite_getPosition(sprite);

    int xs = (int)vec_sprite.x;
    int ys = (int)vec_sprite.y;

    int xm = vec_mouse.x;
    int ym = vec_mouse.y;

    if (xm <= xs + width && xm > xs && ym <= ys + height && ym > ys)
        return 1;
    return -1;
}

void draw_background_settings(const objects *object)
{
    sfRenderWindow_drawSprite(object->window, object->settings->red_bar_mus, \
    NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->black_bar_mus, NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->grey_bar_mus, NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->red_bar_sound, NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->black_bar_sound, NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->grey_bar_sound, NULL);

    sfRenderWindow_drawSprite(object->window, \
    object->settings->red_bar_fps, NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->black_bar_fps, NULL);
    sfRenderWindow_drawSprite(object->window, \
    object->settings->grey_bar_fps, NULL);
}

void draw_settings(objects *object)
{
    sfRenderWindow_clear(object->window, sfBlack);
    set_text(object, settings_texts[0], "MUSIC", 0);
    set_text(object, settings_texts[1], "BACK", 1);
    set_text(object, settings_texts[2], "SOUND", 0);
    set_text(object, settings_texts[3], "KEYMAP", 1);
    set_text(object, settings_texts[6], "FPS", 0);
    draw_background_settings(object);

    set_text(object, settings_texts[4], object->settings->music_string, 0);
    set_text(object, settings_texts[5], object->settings->sound_string, 0);
    set_text(object, settings_texts[7], object->settings->fps_string, 0);
    set_text(object, settings_texts[8], object->settings->fps_string, 0);
    sfRenderWindow_display(object->window);
}

int settings(objects *object)
{
    int choice = 0;

    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, settings_texts, 8);
            if (choice == 1)
                return (0);
            if (choice == 3)
                keymap(object);
            check_music(object);
            check_sound(object);
            check_fps(object);
        }
        draw_settings(object);
    }
    return 0;
}
