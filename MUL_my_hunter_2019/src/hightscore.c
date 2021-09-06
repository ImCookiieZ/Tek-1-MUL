/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/functions.h"
#include "../include/params_struct.h"

sfVector2f highVecNum = { 930, 20};
sfVector2f highVecText = {600, 20};

int end_func(int ret, params para)
{
    if (para.run == 2)
        ret = 2;
    else
        ret = get_end();
    return (ret);
}

params get_struct2(int level, params para)
{

    para.level = level;
    para.run = 1;
    para.tmp_score = 0;
    para.new = 0;
    para.k = 0;
    para.ducks = 0;
    para.tmp_hit = 0;
    para.bullets = 6 - level;
    para.difficult_speed = level;
    para.spawn_speed = 1;
    para.difficult_size = 1;
    para.now = 0;
    para.prev = 0;
    para.newDuck = 1;
    para.hit = 0;
    para.i = 0;
    para.score = 0;
    return (para);
}

int draw_scores(params para)
{
    sfText_setString(para.numberScore, para.string);
    para.string2[0] = '0';
    para.tmp_highscore = para.highscore;
    for (int l = count_digits(para.highscore) - 1; l >= 0; l--) {
        para.string2[l] = (char) (para.tmp_highscore % 10 + 48);
        para.tmp_highscore /= 10;
    }
    para.string2[count_digits(para.highscore)] = 0;
    if (para.string2[0] == 0) {
        para.string2[0] = '0';
        para.string2[1] = 0;
    }
    sfText_setPosition(para.highNumber, highVecNum);
    sfText_setPosition(para.highText, highVecText);
    sfText_setString(para.highNumber, para.string2);
    sfRenderWindow_drawText(para.window, para.highNumber, NULL);
    sfRenderWindow_drawText(para.window, para.highText, NULL);
    return (0);
}