/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** preparation.c
*/

#include "../include/all_includes.h"

sfVector2f scale_back = {8, 7};
sfVideoMode video_mode = {1920, 1080, 32};

void my_cases(char c, params_t *para, sfVector2f pos)
{
    switch (c) {
        case '#':
            draw_sprite(para->spriteBlock, para, para->block, pos);
            break;
        case 'B':
            para->player_pos = pos;
            para->player_pos.y -= 7;
            break;
        case 'F':
            para->fin = pos;
            break;
    }
}

params_t create_everything4(params_t para)
{
    para.player_jump = sfTexture_createFromFile("pictures/jump.png", NULL);
    sfText_setFont(para.scoreText, para.font);
    sfText_setFont(para.highText, para.font);
    para.run.top = 0;
    para.fall = 0;
    para.up = 0;
    para.my_sprite_int = 0;
    return (para);
}

params_t create_everything3(params_t para)
{
    para.scoreText = sfText_create();
    para.highText = sfText_create();
    para.player = sfTexture_createFromFile("pictures/player.png", NULL);
    para.block = sfTexture_createFromFile("pictures/block.png", NULL);
    para.spriteBlock = sfSprite_create();
    para.down = 120;
    para.play = 0;
    para.tmp_time = sfTime_Zero;
    para.jump_tmp_1 = sfTime_Zero;
    para.jump_tmp_2 = sfTime_Zero;
    para.run.height = 55;
    para.run.width = 38;
    para.jump_rect = para.run;
    para.spritePlayer = sfSprite_create();
    para.spritePlayerJump = sfSprite_create();
    para.run.left = 0;
    para = create_everything4(para);
    return (para);
}

params_t create_everything2(params_t para)
{
    para.enemy = sfTexture_createFromFile("pictures/enemy.png", NULL);
    para.spriteEnemy = sfSprite_create();
    para.font = sfFont_createFromFile("pictures/font.ttf");
    para.numberScore = 0;
    para.background1 = sfTexture_createFromFile("pictures/back1.png", NULL);
    para.background2 = sfTexture_createFromFile("pictures/back2.png", NULL);
    para.background3 = sfTexture_createFromFile("pictures/back3.png", NULL);
    para.background4 = sfTexture_createFromFile("pictures/back4.png", NULL);
    para.spriteBackground1 = sfSprite_create();
    sfSprite_scale(para.spriteBackground1, scale_back);
    para.spriteBackground2 = sfSprite_create();
    sfSprite_scale(para.spriteBackground2, scale_back);
    para.spriteBackground3 = sfSprite_create();
    sfSprite_scale(para.spriteBackground3, scale_back);
    para.spriteBackground4 = sfSprite_create();
    sfSprite_scale(para.spriteBackground4, scale_back);
    para.window = sfRenderWindow_create(video_mode, "Horror", sfDefaultStyle,
                                        NULL);
    para = create_everything3(para);
    return (para);
}

params_t create_everything(void)
{
    params_t para;

    para.music = sfMusic_createFromFile("music/my_game.ogg");
    sfMusic_setVolume(para.music, 30);
    para.score_backrground = sfSprite_create();
    para.scoreTexture = sfTexture_createFromFile(
        "pictures/scor_background.png", NULL);
    para.pos_b1.x = 0;
    para.spriteGold = sfSprite_create();
    para.gold = sfTexture_createFromFile("pictures/gold.png", NULL);
    para.pos_b2.x = 0;
    para.pos_b3.x = 0;
    para.pos_b4.x = 0;
    para.pos_b1.y = 1080 - 100 * 7;
    para.pos_b2.y = 1080 - 140 * 7;
    para.pos_b3.y = 1080 - 140 * 7;
    para.pos_b4.y = 0;
    para.run.top = 0;
    para.jump = 0;
    para = create_everything2(para);
    return (para);
}