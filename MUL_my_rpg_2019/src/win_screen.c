/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

const double win_texts[5][4] = {
    {550, 200, 200, 0},
    {750, 700, 80, 360},
    {820, 800, 80, 160},
};

void set_win_text(objects *obj)
{
    sfRenderWindow_clear(obj->window, sfBlack);
    set_text(obj, win_texts[0], "YOU WIN!", 1);
    set_text(obj, win_texts[1], "MAIN MENU", 1);
    set_text(obj, win_texts[2], "QUIT", 1);
    sfRenderWindow_display(obj->window);
}

int win_menu(objects *obj)
{
    int choice = 0;
    obj->map_y = 0;
    obj->map_x = 0;
    pop_all_enemys(obj);
    while (sfRenderWindow_isOpen(obj->window)) {
        while (sfRenderWindow_pollEvent(obj->window, &obj->event)) {
            choice = menu_button(obj, win_texts, 3) + 30;
            if (choice == 31) {
                play_music(obj, START_MUSIC);
                obj->map_type = MAIN_MUSIC;
            }
            if (choice == 32) return (33);
            if (choice != 29) return (choice);
        }
        set_win_text(obj);
    }
    return (0);
}