/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** run_function.c
*/

#include "../include/all_includes.h"

void check_end(params_t *para, char **map)
{
    int y_coordinate = (int) (para->player_pos.y + 55 - 7) /
        63;
    int x_coordinate = (int) (para->player_pos.x + 35 +
        para->now.microseconds / 3500) / 63;

    if (y_coordinate  < 17) {
        if (map[y_coordinate] && map[y_coordinate][x_coordinate]) {
            if (map[y_coordinate][x_coordinate] == '#')
                para->play = 0;
            for (; map[y_coordinate]; y_coordinate++)
                if (map[y_coordinate][x_coordinate - 1] == 'F')
                    para->play = 4;
        }
    }
    else
        para->play = 0;
}

void my_statements(sfEvent event, loop_params_t *loop, params_t *para)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(para->window);
    if (event.key.code == sfKeyEscape) {
        sfMusic_pause(loop->music);
        para->play = 3;
        para->play = get_menu3();
        if (para->play == 2)
            sfRenderWindow_close(para->window);
        sfMusic_play(loop->music);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) && para->jump == 0 && \
            para->fall == 0) {
        para->jump = 1;
        para->jump_clock = sfClock_create();
    }
}

void game_loop(params_t *para, char **map, loop_params_t *loop)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(para->window) && para->play != 0 &&
    para->play != 4) {
        para->now = sfClock_getElapsedTime(loop->clock);
        sfRenderWindow_clear(para->window, sfBlack);
        while (sfRenderWindow_pollEvent(para->window, &event)) {
            my_statements(event, loop, para);
        }
        if (para->play == 1) {
            draw_game(para, map);
            draw_score(para);
            check_end(para, map);
            sfRenderWindow_display(para->window);
        }
        para->prev = para->now;
    }
}

int start_game(char **map, long highscore)
{
    params_t para = create_everything();
    loop_params_t loop_params = {para.music, sfClock_create()};

    para.highNumber = highscore;
    sfMusic_play(loop_params.music);
    para.prev = sfClock_getElapsedTime(loop_params.clock);
    draw_map(map, &para);
    para.play = 1;
    game_loop(&para, map, &loop_params);
    para.jump = 0;
    para.fall = 0;
    para.now = sfTime_Zero;
    para.tmp_time = sfTime_Zero;
    para.prev = para.now;
    sfMusic_destroy(para.music);
    sfClock_destroy(loop_params.clock);
    sfRenderWindow_destroy(para.window);
    if (para.play == 0 || para.play == 4)
        if (get_end(&para) == 1)
            start_game(map, para.highNumber);
    return (0);
}

int run_function(char **map)
{
    int answer = get_menu();

    my_printf("%i", answer);
    if (answer == 1)
        answer = start_game(map, 0);
    return (answer);
}