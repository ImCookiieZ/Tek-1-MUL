/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** draw_game.c
*/

#include "../include/all_includes.h"

void draw_sprite2(sfSprite *sprite, params_t *params, sfTexture
*texture, sfVector2f position)
{
    position.x += 1920;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(params->window, sprite, NULL);
}

void draw_backs(params_t *para)
{
    if (para->pos_b1.x > -1920) para->pos_b1.x -= (float)0.3;
    else para->pos_b1.x = 0;
    if (para->pos_b2.x > -1920) para->pos_b2.x -= (float)0.2;
    else para->pos_b2.x = 0;
    if (para->pos_b3.x > -1920) para->pos_b3.x -= (float)0.1;
    else para->pos_b3.x = 0;
    draw_sprite(para->spriteBackground4, para, para->background4, para->pos_b4);
    draw_sprite2(para->spriteBackground4, para, para->background4,
                 para->pos_b4);
    draw_sprite(para->spriteBackground3, para, para->background3, para->pos_b3);
    draw_sprite2(para->spriteBackground3, para, para->background3,
                 para->pos_b3);draw_sprite(para->spriteBackground2, para, para->background2, para->pos_b2);
    draw_sprite2(para->spriteBackground2, para, para->background2,
                 para->pos_b2);draw_sprite(para->spriteBackground1, para, para->background1, para->pos_b1);
    draw_sprite2(para->spriteBackground1, para, para->background1,
        para->pos_b1);
}

void my_switch_map(char c, params_t *para, char **map, sfVector2f pos)
{
    switch (c) {
        case '#':
            draw_sprite(para->spriteBlock, para, para->block, pos);
            break;
        case 'B':
            draw_player(para, map);
            break;
        case 'F':
            draw_fin(pos, para);
            para->fin = pos;
            break;
        case '+':
            draw_sprite(para->spriteEnemy, para, para->enemy, pos);
            break;
        default:
            break;
    }
}

void draw_game(params_t *para, char **map)
{
    sfVector2f pos = {0, 0};
    draw_backs(para);
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++) {
            pos.y = (float)(i * 63);
            pos.x = (float)(j * 63 - para->now.microseconds / 3500);
            my_switch_map(map[i][j], para, map, pos);
        }
}

void draw_sprite(sfSprite *sprite, params_t *params, sfTexture
*texture, sfVector2f position)
{
    if (sprite == params->spriteEnemy) {
        position.y += 7;
        if (params->player_pos.x + 35 >= position.x && params->player_pos.x +
        35 <= position.x + 24 && params->player_pos.y + 55 >= position.y + 30
        && params->player_pos.y <= position.y + 55)
            params->play = 0;
        else if (params->player_pos.x >= position.x + 24 && params->player_pos
        .x <= position.x + 80 && params->player_pos.y + 55 >= position.y &&
        params->player_pos.y <= position.y + 80) {
            params->play = 0;
        }
    }
    else if (sprite == params->spriteBlock)
        if (position.x <= params->player_pos.x + 35 && position.x + 63 >=
        params->player_pos.x && position.y <= params->player_pos.y &&
        position.y + 63 >= params->player_pos.y && params->play == 1)
            params->play = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(params->window, sprite, NULL);
}