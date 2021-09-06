/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

extern const double menu_texts[6][4];
extern const double pause_texts[6][4];

const double htp_texts[3][4] = {
    {50, 50, 100, 0},
    {100, 900, 80, 180},
    {150, 150, 80, 0},
};

int pause_menu(objects *object)
{
    int choice = 0;
    for (int i = 0; object->musics[i] != NULL; i++)
        sfMusic_pause(object->musics[i]);
    sfMusic_play(object->musics[PAUSE_MUSIC]);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, pause_texts, 6) + 20;
            if (choice == 22) play_music(object, START_MUSIC);
            if (choice == 25) save_game(object);
            if (choice == 21) {
                sfMusic_stop(object->musics[PAUSE_MUSIC]);
                check_which_music(object);
            }
            if (choice == 24) settings_from_pause(object);
            if (choice != 19 && choice != 25) return (choice);
        }
        sfRenderWindow_clear(object->window, sfBlack);
        set_pause_menu_text(object);
        sfRenderWindow_display(object->window);
    }
    return (0);
}

void how_to_play(objects *object)
{
    int choice = 0;

    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, htp_texts, 3);
            if (choice == 1)
                return;
        }
        sfRenderWindow_clear(object->window, sfBlack);
        set_text(object, htp_texts[0], "HOW TO PLAY:", 0);
        set_text(object, htp_texts[2], "(default settings):\nMove your "
"Character with W, A, S, D\nTo open your Inventory press I\nYou can pause"
" your game with P or Esc\nIf you want to change your skills\nuse the "
"buttons 1, 2, 3\nAnd if you want to use them press the Arrow Keys\nTalk "
"to the monkeys if you need an advice ;)\nHave fun!", 0);
        set_text(object, htp_texts[1], "BACK", 1);
        sfRenderWindow_display(object->window);
    }
}

void main_menu(objects *object)
{
    int choice = 0;

    init_gender(object);
    intro(object);
    play_music(object, START_MUSIC);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, menu_texts, 6);
            if (choice == 4) settings(object);
            if (choice == 2) return;
            if (choice == 1) how_to_play(object);
            if (choice == 0 && get_game(object) == 23) return;
        }
        object->map_x = 0;
        object->map_y = 0;
        sfRenderWindow_clear(object->window, sfBlack);
        set_main_menu_texts(object);
        sfRenderWindow_display(object->window);
    }
}
