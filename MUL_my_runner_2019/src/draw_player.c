/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** draw_player.c
*/

#include "../include/all_includes.h"

sfVector2f calc_pos(params_t *para, int my_sprite_int, int
change)
{
    if (my_sprite_int < 3) {
        para->down = 120;
        if (change == 1 && para->up < 120) {
            para->up++;
            para->player_pos.y--;
        }
    }
    else {
        para->up = 0;
        if (change == 1 && para->down > 0) {
            para->down--;
            para->player_pos.y++;
        }
    }
    return (para->player_pos);
}

void player_jump_ground(params_t *para)
{
    para->jump_rect.left = 40 * para->my_sprite_int;
    sfSprite_setTexture(para->spritePlayerJump, para->player_jump, sfTrue);
    sfSprite_setTextureRect(para->spritePlayerJump, para->jump_rect);
    sfSprite_setPosition(para->spritePlayerJump, para->player_pos);
    sfRenderWindow_drawSprite(para->window, para->spritePlayerJump, NULL);
    if (para->my_sprite_int == 6) {
        para->jump = 0;
        para->my_sprite_int = 0;
        para->jump_tmp_1 = sfTime_Zero;
        para->jump_tmp_2 = sfTime_Zero;
    }
}

void draw_player_jump(params_t *para, int ground)
{
    sfTime time = sfClock_getElapsedTime(para->jump_clock);
    int change = 0;

    if (time.microseconds - para->jump_tmp_1.microseconds > 200000) {
        para->my_sprite_int++;
        para->jump_tmp_1 = time;
    }
    if (time.microseconds - para->jump_tmp_2.microseconds > 3500) {
        change = 1;
        para->jump_tmp_2 = time;
    }
    else change = 0;
    para->player_pos = calc_pos(para, para->my_sprite_int, change);
    if ((para->player_pos.y - 8) / 63 > ground - 1 && para->my_sprite_int > 1) {
        para->jump = 0;
        para->my_sprite_int = 0;
        para->jump_tmp_1 = sfTime_Zero;
        para->jump_tmp_2 = sfTime_Zero;
        return;
    }
    player_jump_ground(para);
}

void draw_player_fall(params_t *para, int ground)
{
    sfIntRect rect = {160, 0, 38, 55};

    para->fall = 1;
    if (para->now.microseconds - para->tmp_time.microseconds > 2500) {
        para->tmp_time = para->now;
        para->player_pos.y++;
    }
    sfSprite_setTexture(para->spritePlayerJump, para->player_jump, sfTrue);
    sfSprite_setTextureRect(para->spritePlayerJump, rect);
    sfSprite_setPosition(para->spritePlayerJump, para->player_pos);
    sfRenderWindow_drawSprite(para->window, para->spritePlayerJump, NULL);
}

void draw_player(params_t *para, char **map)
{
    int ground = get_ground(para, map);

    if (((para->player_pos.y - 8) / 63 < ground - 1) && para->jump == 0)
        draw_player_fall(para, ground);
    else if (para->jump == 0) {
        para->fall = 0;
        sfSprite_setTexture(para->spritePlayer, para->player, sfTrue);
        sfSprite_setTextureRect(para->spritePlayer, para->run);
        sfSprite_setPosition(para->spritePlayer, para->player_pos);
        sfRenderWindow_drawSprite(para->window, para->spritePlayer, NULL);
        my_change_rect(para);
    }
    else
        draw_player_jump(para, ground);
}