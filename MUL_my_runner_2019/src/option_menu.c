/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** option_menu.c
*/

#include "../include/all_includes.h"

sfVideoMode video_mode4 = {1920, 1080, 32};
sfVector2f startVec3 = {490, 440};
sfVector2f my_duckhuntVec3 = {300, 200};
sfVector2f my_exitVec3 = {545, 540};

void draw_map(char **map, params_t *para)
{
    sfVector2f pos = {0, 0};

    draw_sprite(para->spriteBackground4, para, para->background1, pos);
    draw_sprite(para->spriteBackground3, para, para->background2, pos);
    draw_sprite(para->spriteBackground2, para, para->background3, pos);
    draw_sprite(para->spriteBackground1, para, para->background4, pos);
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            pos.y = (float)(i * 63);
            pos.x = (float)(j * 63);
            my_cases(map[i][j], para, pos);
        }
    }
}

int draw_manu3(sfRenderWindow *window, sfText *start, sfText *my_exit, \
    sfText *my_duckhunt)
{
    sfRenderWindow_drawText(window, start, NULL);
    sfRenderWindow_drawText(window, my_exit, NULL);
    sfRenderWindow_drawText(window, my_duckhunt, NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    return (0);
}

int prepare_manu3(sfRenderWindow *window, sfFont *font)
{
    sfText *my_duckhunt = sfText_create();
    sfText *start = sfText_create();
    sfText *my_exit = sfText_create();

    sfText_setPosition(start, startVec3);
    sfText_setCharacterSize(start, 30);
    sfText_setString(start, "CONTINUE");
    sfText_setFont(start, font);
    sfText_setPosition(my_duckhunt, my_duckhuntVec3);
    sfText_setCharacterSize(my_duckhunt, 100);
    sfText_setString(my_duckhunt, "Options");
    sfText_setFont(my_duckhunt, font);
    sfText_setPosition(my_exit, my_exitVec3);
    sfText_setCharacterSize(my_exit, 30);
    sfText_setString(my_exit, "EXIT");
    sfText_setFont(my_exit, font);
    draw_manu3(window, start, my_exit, my_duckhunt);
    return (0);
}

int get_answer3(sfRenderWindow *window, sfVector2i mouse_pos)
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

int get_menu3(void)
{
    sfMusic *music = music_player("music/optionmusic.ogg");
    int answer = 1;
    sfEvent event;
    sfRenderWindow *window;
    sfFont *font = sfFont_createFromFile("pictures/font.ttf");

    window = sfRenderWindow_create(video_mode4, "Option", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) {
                answer = get_answer3(window,
                    sfMouse_getPositionRenderWindow(window));
            }
        }
        prepare_manu3(window, font);
    }
    sfMusic_destroy(music);
    return (answer);
}