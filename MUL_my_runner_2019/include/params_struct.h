/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "my.h"
#include "struct.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>
#include <string.h>

typedef struct loop_params {
    sfMusic *music;
    sfClock *clock;
}loop_params_t;

typedef struct my_params {
    int my_sprite_int;
    sfIntRect run;
    sfSprite *spriteEnemy;
    sfTexture *enemy;
    sfSprite *score_backrground;
    sfTexture *scoreTexture;
    sfSprite *spritePlayer;
    sfSprite *spritePlayerJump;
    sfTexture *player;
    sfTexture *player_jump;
    int jump;
    sfIntRect jump_rect;
    sfVector2f player_pos;
    sfClock *jump_clock;
    int fall;
    int play;
    sfTime tmp_time;
    sfTime jump_tmp_1;
    sfTime jump_tmp_2;
    sfSprite *spriteGold;
    sfTexture *gold;
    int up;
    int down;
    sfTime now;
    sfTime prev;
    sfFont *font;
    long highNumber;
    sfText *highText;
    sfText *scoreText;
    long numberScore;
    sfTexture *background1;
    sfTexture *background2;
    sfTexture *background3;
    sfTexture *background4;
    sfSprite *spriteBackground1;
    sfSprite *spriteBackground2;
    sfSprite *spriteBackground3;
    sfSprite *spriteBackground4;
    sfSprite *spriteBlock;
    sfTexture *block;
    sfRenderWindow *window;
    sfVector2f fin;
    sfVector2f pos_b1;
    sfVector2f pos_b2;
    sfVector2f pos_b3;
    sfVector2f pos_b4;
    sfMusic *music;
}params_t;