/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** add_to_menus.c
*/

#include "../include/all_includes.h"
const double player_texts[4][4] = {
    {250, 200, 150, 0},
    {300, 800, 60, 350},
    {850, 800, 60, 300},
    {1350, 800, 60, 240}
};

const double menu_texts[6][4] = {
    {820, 500, 80, 160},
    {720, 600, 80, 450},
    {820, 800, 80, 160},
    {320, 100, 250, 0},
    {760, 700, 80, 345},
    {10, 10, 20, 20}
};

const double pause_texts[6][4] = {
    {420, 200, 200, 0},
    {770, 500, 80, 320},
    {750, 700, 80, 360},
    {820, 900, 80, 160},
    {750, 800, 80, 360},
    {820, 600, 80, 160}
};

void set_main_menu_texts(objects *object)
{
    set_text(object, menu_texts[0], "PLAY", 1);
    set_text(object, menu_texts[1], "HOW TO PLAY", 1);
    set_text(object, menu_texts[2], "EXIT", 1);
    set_text(object, menu_texts[3], "POKEVENTURE", 0);
    set_text(object, menu_texts[4], "SETTINGS", 1);
    set_text(object, menu_texts[5], object->settings->fps_string, 0);
}

void set_pause_menu_text(objects *object)
{
    set_text(object, pause_texts[0], "GAME PAUSED", 0);
    set_text(object, pause_texts[1], "CONTINUE", 1);
    set_text(object, pause_texts[2], "MAIN MENU", 1);
    set_text(object, pause_texts[3], "QUIT", 1);
    set_text(object, pause_texts[4], "SETTINGS", 1);
    set_text(object, pause_texts[5], "SAVE", 1);
}

void set_choose_player_text(objects *object)
{
    sfRenderWindow_clear(object->window, sfBlack);
    draw_choice_sprites(object->window);
    set_text(object, player_texts[0], "CHOOSE YOUR POKEMON", 0);
    set_text(object, player_texts[1], "CHARMANDER", 1);
    set_text(object, player_texts[2], "BULBASAUR", 1);
    set_text(object, player_texts[3], "SQUIRTLE", 1);
    sfRenderWindow_display(object->window);
}

int choose_player(objects *object)
{
    int choice = 0;

    init_stone(object);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, player_texts, 4);
            if (choice >= 1 && choice <= 3) {
                init_player(object, choice);
                init_hud_player_image(object, choice);
                object->boss = init_boss(object);
                init_maps(object, 0);
            }
            if (choice != -1 && choice != 0 && choice != 4 && choice != 5)
                return choose_gender(object, choice);
        }
        set_choose_player_text(object);
    }
    return (0);
}