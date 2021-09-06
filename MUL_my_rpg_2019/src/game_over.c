/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

const double go_texts[5][4] = {
    {420, 200, 200, 0},
    {770, 600, 80, 320},
    {750, 700, 80, 360},
    {820, 900, 80, 160},
};

void set_game_over_text(objects *obj)
{
    sfRenderWindow_clear(obj->window, sfBlack);
    set_text(obj, go_texts[0], "GAME OVER!", 0);
    set_text(obj, go_texts[1], "CONTINUE", 1);
    set_text(obj, go_texts[2], "MAIN MENU", 1);
    set_text(obj, go_texts[3], "QUIT", 1);
    sfRenderWindow_display(obj->window);
}

void gameover_setobject(objects *obj)
{
    sfVector2f vec_start = {1212, 609};

    sfMusic_stop(obj->musics[obj->map_type]);
    sfSound_play(obj->sounds[5]);
    sfSprite_setPosition(obj->player->sprite, vec_start);
    obj->map_y = 1;
    obj->map_x = 3;
    obj->player->hp = obj->player->max_hp;
    obj->map_type = MAIN_MUSIC;
}

int game_over_menu(objects *obj)
{
    int choice = 0;
    gameover_setobject(obj);
    save_game(obj);
    pop_all_enemys(obj);
    while (sfRenderWindow_isOpen(obj->window)) {
        while (sfRenderWindow_pollEvent(obj->window, &obj->event)) {
            choice = menu_button(obj, go_texts, 4) + 30;
            if (choice == 32) {
                play_music(obj, START_MUSIC);
                obj->map_type = MAIN_MUSIC;
            }
            if (choice == 31) {
                play_music(obj, START_MUSIC);
                obj->map_type = MAIN_MUSIC;
            }
            if (choice != 29) return (choice);
        }
        set_game_over_text(obj);
    }
    return (0);
}