/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>
#include <string.h>
#include <SFML/Audio.h>

#ifndef MUL_MY_HUNTER_2019_PARAMS_STRUCT_H
#define MUL_MY_HUNTER_2019_PARAMS_STRUCT_H

typedef struct params_t {
    int highscore;
    int tmp_highscore;
    char string2[10];
    sfText *highText;
    sfText *highNumber;
    sfMusic *music;
    int level;
    sfFont *font;
    sfText *scoreText;
    sfText *numberScore;
    sfSprite *spriteBullet;
    sfTexture *bullet;
    int run;
    sfTime timer;
    sfSprite *spriteBackground;
    sfEvent event;
    sfRenderWindow *window;
    sfTexture *background;
    sfTexture *birds[3][2];
    int tmp_score;
    float mousePosX;
    float mousePosY;
    int new;
    int k;
    int ducks;
    char string[10];
    int tmp_hit;
    int bullets;
    int difficult_speed;
    long long spawn_speed;
    int difficult_size;
    long long now;
    long long prev;
    int newDuck;
    int direction[14];
    int scaling_down[80];
    int hit;
    int i;
    int score;
    int r[14];
    float speed[14];
    sfVector2f pos[14];
    sfVector2f pos_down[14];
} params;

#endif //MUL_MY_HUNTER_2019_PARAMS_STRUCT_H
