/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/functions.h"
#include "../include/params_struct.h"

params get_struct(int level)
{
    params para;

    para.highText = sfText_create();
    para = get_struct2(level, para);
    return (para);
}

sfMusic *my_music(sfMusic *music2)
{
    sfTime time = sfTime_Zero;

    sfMusic_play(music2);
    sfMusic_setPlayingOffset(music2, time);
    sfMusic_setVolume(music2, 20);
    return (music2);

}

params key_checker(params para, sfMusic *music)
{
    if (para.event.type == sfEvtClosed) {
        sfRenderWindow_close(para.window);
        para.run = 2;
    }
    if (para.event.type == sfEvtKeyPressed) {
        if (para.event.key.code == sfKeyEscape) {
            sfMusic_pause(music);
            para.run = 0;
            para.run = get_menu3();
            if (para.run == 2)
                sfRenderWindow_close(para.window);
            sfMusic_play(music);
        }
    }
    if (para.event.type == sfEvtMouseButtonPressed) {
        my_music(para.music);
        para = my_shoot(para);
    }
    return (para);
}

params my_shoot2(params para)
{
    para.scaling_down[para.hit] = para.r[para.k];
    para.pos_down[para.hit].x = para.pos[para.k].x;
    para.pos_down[para.hit].y = para.pos[para.k].y;
    for (int tmp = para.k; tmp < para.ducks; tmp++) {
        para.pos[tmp] = para.pos[tmp + 1];
        para.r[tmp] = para.r[tmp + 1];
        para.speed[tmp] = para.speed[tmp + 1];
    }
    para.r[para.ducks] = rand() % 3 + 1;
    para.pos[para.ducks].y = rand() % 700 + 80;
    para.pos[para.ducks].x = -35;
    para.direction[para.ducks] = rand() % 2;
    if (para.direction[para.ducks] == 0) {
        para.pos[para.ducks].x = 1280;
        para.speed[para.ducks] *= -1;
    }
    return (para);
}

params my_shoot(params para)
{
    para.bullets--;
    para.mousePosX = (float) sfMouse_getPositionRenderWindow(para.window).x;
    para.mousePosY = (float) sfMouse_getPositionRenderWindow(para.window).y;
    for (para.k = 0; para.k < para.ducks; para.k++)
        if (para.mousePosX > para.pos[para.k].x - para.speed[para.k] && \
        para.mousePosX < (para.pos[para.k].x + 35.0 * para.r[para.k] - \
        para.speed[para.k]) && para.mousePosY > para.pos[para.k].y && \
        para.mousePosY < (para.pos[para.k].y + 25.0) * para.r[para.k]) {
            para.score++;
            para.bullets++;
            if (para.bullets < 6 - para.level)
                para.bullets++;
            para = my_shoot2(para);
            para.hit++;
            para.new++;
            para.ducks--;
        }
    if (para.new == 0)
        para.newDuck = 1;
    return (para);
}