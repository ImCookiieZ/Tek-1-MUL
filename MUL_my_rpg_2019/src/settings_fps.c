/*
** EPITECH PROJECT, 2019
** settings_fps.c
** File description:
** fps
*/

#include "../include/all_includes.h"

void set_fps_string(objects *object)
{
    if (object->settings->fps <= 30)
        object->settings->fps = 30;
    if (object->settings->fps >= 230)
        object->settings->fps = 230;
    object->settings->fps_string = my_itoa(object->settings->fps);
    object->settings->fps_string = \
    my_strcat(object->settings->fps_string, " FPS\0");
}

void check_fps(objects *object)
{
    sfVector2i vec;
    sfVector2f vec_sprite;

    if (is_sprite_hit(object, object->settings->red_bar_fps, 275, 40)\
    == 1 && object->event.type == sfEvtMouseButtonPressed) {
        while (is_sprite_hit(object, object->settings->red_bar_fps, 275, 40)\
        == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
            vec = sfMouse_getPositionRenderWindow(object->window);
            vec_sprite = sfSprite_getPosition\
            (object->settings->black_bar_fps);
            vec_sprite.x = (float)vec.x;
            object->settings->fps = ((int)(vec.x - 1002) / 1.335) + 30;
            set_fps_string(object);
            sfSprite_setPosition(object->settings->black_bar_fps, vec_sprite);
            sfRenderWindow_clear(object->window, sfBlack);
            draw_settings(object);
        }
    }
}

int init_fps_string(objects *object)
{
    char *fps = NULL;

    if (!(fps = malloc(sizeof(char) * 8)))
        return -1;
    fps[0] = '\0';
    fps = my_strcpy(fps, "60 FPS\0");

    object->settings->fps_string = fps;
    return 0;
}