/*
** EPITECH PROJECT, 2019
** gameloop.c
** File description:
** gameloop
*/

#include "../include/all_includes.h"

int check_event(objects *obj)
{
    if (obj->stone_destroyed == 0) {
        obj->map_col[1][3][14][16] = 1;
        obj->map_col[1][3][14][17] = 1;
        obj->map_col[1][3][14][18] = 1;
    }
    if (obj->event.type == sfEvtClosed)
        sfRenderWindow_close(obj->window);
    if (obj->event.type == sfEvtKeyPressed) {
        if (obj->event.key.code == sfKeyP || obj->event.key.code == sfKeyEscape)
            return (pause_menu(obj));
        if (obj->event.key.code == sfKeyI) {
            sfSound_play(obj->sounds[3]);
            return (inventory_menu(obj));
        }
    }
    return (-1);
}

int gameloop(objects *obj)
{
    int choice = 0;
    while (sfRenderWindow_isOpen(obj->window)) {
        while (sfRenderWindow_pollEvent(obj->window, &obj->event)) {
            choice = check_event(obj);
            if (choice == 22 || choice == 23) return (choice);
        }
        obj->gametime = sfClock_getElapsedTime(obj->clock);
        draw(obj);
        if (obj->player->hp <= 0) {
            choice = game_over_menu(obj);
            if (choice == 31) return (get_game(obj));
            if (choice == 32 || choice == 33) return (choice - 10);
        }
        if (obj->boss.is_destroyed == 1) return (win_menu(obj) - 10);
    }
    return (0);
}