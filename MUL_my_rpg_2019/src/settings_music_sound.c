/*
** EPITECH PROJECT, 2019
** settings_music_sound.c
** File description:
** settings
*/

#include "../include/all_includes.h"

void set_music_string(objects *object)
{
    if (object->settings->music <= 0)
        object->settings->music = 0;
    if (object->settings->music >= 100)
        object->settings->music = 100;
    object->settings->music_string = my_itoa(object->settings->music);
    object->settings->music_string = \
    my_strcat(object->settings->music_string, "%\0");
}

void check_music(objects *object)
{
    sfVector2i vec;
    sfVector2f vec_sprite;

    if (is_sprite_hit(object, object->settings->red_bar_mus, 275, 40)\
    == 1 && object->event.type == sfEvtMouseButtonPressed) {
        while (is_sprite_hit(object, object->settings->red_bar_mus, 275, 40)\
        == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
            vec = sfMouse_getPositionRenderWindow(object->window);
            vec_sprite = sfSprite_getPosition(object->settings->black_bar_mus);
            vec_sprite.x = (float)vec.x;
            object->settings->music = (int)(vec.x - 1002) / 2.67;
            set_music_string(object);
            sfSprite_setPosition(object->settings->black_bar_mus, vec_sprite);
            sfRenderWindow_clear(object->window, sfBlack);
            draw_settings(object);
        }
        for (int i = 0; object->musics[i] != NULL; i++)
            sfMusic_setVolume(object->musics[i], object->settings->music);
    }
}

void set_sound_string(objects *object)
{
    if (object->settings->sounds <= 0)
        object->settings->sounds = 0;
    if (object->settings->sounds >= 100)
        object->settings->sounds = 100;
    object->settings->sound_string = my_itoa(object->settings->sounds);
    object->settings->sound_string = \
    my_strcat(object->settings->sound_string, "%\0");
}

void check_sound(objects *object)
{
    sfVector2i vec;
    sfVector2f vec_sprite;

    if (is_sprite_hit(object, object->settings->red_bar_sound, 275, 40)\
    == 1 && object->event.type == sfEvtMouseButtonPressed) {
        while (is_sprite_hit(object, object->settings->red_bar_sound, 275, 40)\
        == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
            vec = sfMouse_getPositionRenderWindow(object->window);
            vec_sprite = sfSprite_getPosition\
            (object->settings->black_bar_sound);
            vec_sprite.x = (float)vec.x;
            object->settings->sounds = (int)(vec.x - 1002) / 2.67;
            set_sound_string(object);
            sfSprite_setPosition(object->settings->black_bar_sound, vec_sprite);
            sfRenderWindow_clear(object->window, sfBlack);
            draw_settings(object);
        }
        for (int i = 0; object->sounds[i] != NULL; i++)
            sfSound_setVolume(object->sounds[i], object->settings->sounds);
    }
}