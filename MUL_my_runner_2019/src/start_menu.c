/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/all_includes.h"

sfVideoMode video_mode2 = {1920, 1080, 32};
sfVector2f startVec = {535, 440};
sfVector2f my_duckhuntVec = {250, 100};
sfVector2f my_exitVec = {545, 540};

sfMusic *music_player(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);

    sfMusic_play(music);
    sfMusic_setVolume(music, 20);
    sfMusic_setLoop(music, 1);
    return (music);
}

int draw_manu(sfRenderWindow *window, sfText *start, sfText *my_exit, \
    sfText *my_duckhunt)
{
    sfRenderWindow_drawText(window, start, NULL);
    sfRenderWindow_drawText(window, my_exit, NULL);
    sfRenderWindow_drawText(window, my_duckhunt, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    return (0);
}

int prepare_manu(sfRenderWindow *window, sfFont *font)
{
    sfText *my_duckhunt = sfText_create();
    sfText *start = sfText_create();
    sfText *my_exit = sfText_create();

    sfText_setPosition(start, startVec);
    sfText_setCharacterSize(start, 30);
    sfText_setString(start, "START");
    sfText_setFont(start, font);
    sfText_setPosition(my_duckhunt, my_duckhuntVec);
    sfText_setCharacterSize(my_duckhunt, 100);
    sfText_setString(my_duckhunt, "My runner");
    sfText_setFont(my_duckhunt, font);
    sfText_setPosition(my_exit, my_exitVec);
    sfText_setCharacterSize(my_exit, 30);
    sfText_setString(my_exit, "EXIT");
    sfText_setFont(my_exit, font);
    draw_manu(window, start, my_exit, my_duckhunt);
    return (0);
}

int get_answer(sfRenderWindow *window, sfVector2i mouse_pos)
{
    int answer = 0;

    if (mouse_pos.x >= 535 && mouse_pos.x <= 835) {
        if (mouse_pos.y >= 440 && mouse_pos.y <= 540)
            answer = 1;
        else if (mouse_pos.y >= 540 && mouse_pos.y <= 640)
            answer = 2;
    }
    if (answer != 0)
        sfRenderWindow_close(window);
    return (answer);
}

int get_menu(void)
{
    sfMusic *music = music_player("music/optionmusic.ogg");
    int answer = 0;
    sfEvent event;
    sfRenderWindow *window;
    sfFont *font = sfFont_createFromFile("pictures/font.ttf");

    window = sfRenderWindow_create(video_mode2, "Start", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) {
                answer = get_answer(window, \
                    sfMouse_getPositionRenderWindow(window));
            }
        }
        prepare_manu(window, font);
    }
    sfMusic_destroy(music);
    sfRenderWindow_destroy(window);
    return (answer);
}