/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/functions.h"
#include <SFML/Window.h>

int error_try(int ac, char **av)
{
    int ret = 1;
    if (ac > 2 || ac == 0)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_h();
        return (-1);
    }
    else if (ac == 2)
        ret = my_getnbr(av[1]);
    if (ret > 3 || ret == 0)
        return (84);
    return (ret);
}

sfMusic *music_player(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);

    sfMusic_play(music);
    sfMusic_setVolume(music, 20);
    sfMusic_setLoop(music, 1);
    return (music);
}

params gameloop(sfClock *clock, params para)
{
    sfMusic *music = music_player("music/gamemusic.ogg");
    sfTexture *my_cursor = sfTexture_createFromFile("pictures/37355.png", NULL);

    sfRenderWindow_setMouseCursorVisible(para.window, 0);
    while (sfRenderWindow_isOpen(para.window)) {
        sfRenderWindow_clear(para.window, sfBlack);
        draw_scores(para);
        para.prev = para.now;
        para.timer = sfClock_getElapsedTime(clock);
        para.now = para.timer.microseconds;
        while (sfRenderWindow_pollEvent(para.window, &para.event))
            para = key_checker(para, music);
        if (para.run == 1) {
            para = run_function(para, my_cursor);
            para = time_checker(para);
            para.string[count_digits(para.score) + 1] = '\0';
        }
    }
    sfMusic_destroy(music);
    return (para);
}

params time_checker(params para)
{
    if (para.now / 140000 > para.prev / 140000)
        para.i++;
    if (para.now / 500000 > para.prev / 500000)
        para.new = 0;
    for (int l = 0; l < para.hit; l++)
        para.pos_down[l].y += (float) 0.5;
    if (para.ducks > 7 || para.bullets < 1)
        sfRenderWindow_close(para.window);
    if (para.i == 4)
        para.i = 0;
    para.newDuck = 0;
    para.tmp_score = para.score;
    para.string[0] = '0';
    for (int l = count_digits(para.score) - 1; l >= 0; l--) {
        para.string[l] = (char) (para.tmp_score % 10 + 48);
        para.tmp_score /= 10;
    }
    return (para);
}

int main(int ac, char **av)
{
    params para;
    int level = error_try(ac, av);
    int ret = get_menu();

    if (level == 84)
        return (84);
    else if (level == -1)
        return (0);
    para = get_struct(level);
    para.highscore = 0;
    para.string2[1] = 0;
    while (ret == 1) {
        para = get_struct2(level, para);
        para = create_everything(para);
        if (para.score > para.highscore)
            para.highscore = para.score;
        ret = end_func(ret, para);
        sfMusic_destroy(para.music);
    }
    return (0);
}