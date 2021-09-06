/*
** EPITECH PROJECT, 2020
** settings
** File description:
** settings from pause menu
*/

#include "../include/all_includes.h"
#include <string.h>

const double settings_texts_next[9][4] = {
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

int settings_from_pause(objects *object)
{
    int choice = 0;

    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, settings_texts_next, 8);
            if (choice == 1) {
                sfMusic_stop(object->musics[PAUSE_MUSIC]);
                sfMusic_play(object->musics[object->map_type]);
                return (0);
            }
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