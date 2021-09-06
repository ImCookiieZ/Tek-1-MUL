/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/functions.h"

sfVideoMode video_mode3 = {1280, 880, 32};
sfVector2f startVec2 = {505, 440};
sfVector2f my_duckhuntVec2 = {200, 100};
sfVector2f my_exitVec2 = {545, 540};

int draw_end_manu(sfRenderWindow *window, sfText *start, sfText *my_exit, \
    sfText *my_duckhunt)
{
    sfRenderWindow_drawText(window, start, NULL);
    sfRenderWindow_drawText(window, my_exit, NULL);
    sfRenderWindow_drawText(window, my_duckhunt, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    return (0);
}

int prepare_end_manu(sfRenderWindow *window, sfFont *font)
{
    sfText *my_duckhunt = sfText_create();
    sfText *start = sfText_create();
    sfText *my_exit = sfText_create();

    sfText_setPosition(start, startVec2);
    sfText_setCharacterSize(start, 30);
    sfText_setString(start, "RESTART");
    sfText_setFont(start, font);
    sfText_setPosition(my_duckhunt, my_duckhuntVec2);
    sfText_setCharacterSize(my_duckhunt, 100);
    sfText_setString(my_duckhunt, "Game Over");
    sfText_setFont(my_duckhunt, font);
    sfText_setPosition(my_exit, my_exitVec2);
    sfText_setCharacterSize(my_exit, 30);
    sfText_setString(my_exit, "EXIT");
    sfText_setFont(my_exit, font);
    draw_end_manu(window, start, my_exit, my_duckhunt);
    return (0);
}

int get_end_answer(sfRenderWindow *window, sfVector2i mouse_pos)
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

int get_end(void)
{
    int end_answer = 0;
    sfEvent event;
    sfRenderWindow *window;
    sfFont *font = sfFont_createFromFile("pictures/font.ttf");
    sfMusic *music = music_player("music/optionmusic.ogg");
    window = sfRenderWindow_create(video_mode3, "Game Over", sfDefaultStyle, \
        NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            else if (event.type == sfEvtMouseButtonPressed)
                end_answer = get_end_answer(window, \
                    sfMouse_getPositionRenderWindow(window));
        }
        prepare_end_manu(window, font);
    }
    sfMusic_destroy(music);
    return (end_answer);
}

params sub_hit(params para, int l)
{
    if (para.pos_down[l].y > 800)
        for (int g = l; g < para.tmp_hit - 1; g++) {
            para.pos_down[g] = para.pos_down[g + 1];
            para.scaling_down[g] = para.scaling_down[g + 1];
        }
    return (para);
}