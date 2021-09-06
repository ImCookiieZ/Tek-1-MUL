/*
** EPITECH PROJECT, 2019
** pixel
** File description:
** creator
*/

#include "../include/functions.h"
#include "../include/params_struct.h"

sfVideoMode video_mode = {1280, 880, 32};
sfVector2f bulletvec = {930, 750};
sfVector2f textVec = {20, 20};
sfVector2f back = {0, 80};
sfVector2f scoreVec = {250, 20};
sfVector2f scaleBullet = {0.5, 0.5};
char *pictures[3][2] = {\
        {"pictures/blue_1.png", "pictures/blue_1_2.png"}, \
        {"pictures/blue_2.png", "pictures/blue_2_2.png"}, \
        {"pictures/blue_3.png", "pictures/blue_3_2.png"}};
char *backgrounds[2] = {"pictures/background.jpg", "pictures/back2.jpg"};

params my_drawing(params para)
{
    if (para.score < 150)
        para.difficult_size = para.score / 50;
    if (para.ducks == 0)
        para.newDuck = 1;
    if (para.now / (5000000 - para.spawn_speed * para.level) >
            para.prev / (5000000 - para.spawn_speed * para.level) || \
            para.newDuck == 1) {
        para.ducks++;
        para.pos[para.ducks - 1].y = (float) (rand() % 700 + 80);
        para.speed[para.ducks - 1] = rand() % 4 + 1 + \
        para.difficult_speed * 0.33 * para.level;
        para.r[para.ducks - 1] = rand() % (4 - para.difficult_size) + 2;
        para.pos[para.ducks - 1].x = (float) (-100);
        para.direction[para.ducks - 1] = rand() % 2;
        if (para.direction[para.ducks - 1] == 0) {
            para.pos[para.ducks - 1].x = 1200;
            para.speed[para.ducks - 1] *= -1;
        }
    }
    return (para);
}

params hit_function(params para, sfTexture *my_cursor)
{
    int ar[2] = {para.hit, para.new};
    if (para.hit > 0) {
        para.tmp_hit = para.hit;
        para.hit = fall_down(para.window, ar, para.pos_down, \
        para.scaling_down);
        if (para.tmp_hit > para.hit)
            for (int l = 0; l < para.tmp_hit; l++)
                para = sub_hit(para, l);
    }
    change_cursor(my_cursor, para);
    para.spawn_speed = para.score * 10000;
    para.difficult_speed = para.score / 10;
    para = my_drawing(para);
    return (para);
}

params run_function(params para, sfTexture *my_cursor)
{
    float param_print[3];
    sfRenderWindow_drawSprite(para.window, para.spriteBackground, NULL);
    for (int l = 0; l < para.bullets && l < 6; l++) {
        sfSprite_setPosition(para.spriteBullet, bulletvec);
        sfRenderWindow_drawSprite(para.window, para.spriteBullet, NULL);
        bulletvec.x += 30;
    }
    bulletvec.x = 930;
    for (int l = 0; l < para.ducks; l++) {
        param_print[0] = (float) para.r[l];
        param_print[1] = para.speed[l];
        param_print[2] = (float) para.i;
        para.pos[l] = my_printing(param_print, para.pos[l],
            para.window, para.birds);
        if (para.now / 10000 > para.prev / 10000) {
            para.pos[l].x += (float) (para.speed[l] * (float) para.level);
        }
    }
    para = hit_function(para, my_cursor);
    return (para);
}

params prepare_everything(params para)
{
    sfSprite_scale(para.spriteBullet, scaleBullet);
    sfSprite_setTexture(para.spriteBullet, para.bullet, sfTrue);
    sfText_setString(para.scoreText, "Score:");
    sfText_setCharacterSize(para.scoreText, 30);
    sfText_setPosition(para.scoreText, textVec);
    sfText_setFont(para.scoreText, para.font);
    sfText_setString(para.highText, "HighScore:");
    sfText_setCharacterSize(para.highText, 30);
    sfText_setPosition(para.highText, textVec);
    sfText_setFont(para.highText, para.font);
    sfText_setFont(para.numberScore, para.font);
    sfText_setPosition(para.numberScore, scoreVec);
    sfText_setCharacterSize(para.numberScore, 30);
    sfText_setFont(para.highNumber, para.font);
    sfText_setPosition(para.highNumber, scoreVec);
    sfText_setCharacterSize(para.highNumber, 30);
    sfSprite_setTexture(para.spriteBackground, para.background, sfTrue);
    sfSprite_setPosition(para.spriteBackground, back);
    return (para);
}

params create_everything(params para)
{
    sfClock *clock = sfClock_create();
    para.font = sfFont_createFromFile("pictures/font.ttf");
    para.highNumber = sfText_create();
    para.scoreText = sfText_create();
    para.numberScore = sfText_create();
    para.spriteBullet = sfSprite_create();
    para.bullet = sfTexture_createFromFile("pictures/bullet.png", NULL);
    para.background = sfTexture_createFromFile(backgrounds[1], NULL);
    para.spriteBackground = sfSprite_create();
    para.window = sfRenderWindow_create(video_mode, "My Window", \
    sfDefaultStyle, NULL);
    para.music = sfMusic_createFromFile("music/shot.ogg");
    para = prepare_everything(para);
    for (int l = 0; l < 3; l++)
        for (int t = 0; t < 2; t++)
            para.birds[l][t] = sfTexture_createFromFile(pictures[l][t], NULL);
    para = gameloop(clock, para);
    sfSprite_destroy(para.spriteBackground);
    sfRenderWindow_destroy(para.window);
    return (para);
}