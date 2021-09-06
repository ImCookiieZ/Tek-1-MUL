/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** draw_score.c
*/

#include "../include/all_includes.h"

int my_long_count_digits(long nb, int ret)
{
    if (nb >= 10)
        return (my_long_count_digits(nb / 10 , ret + 1));
    return (ret + 1);
}

char *my_int_to_str(long nb)
{
    int len = my_long_count_digits(nb, 0);
    char *dest = malloc(sizeof(char) * (len + 1));

    dest[len] = '\0';
    for (int i = 1; i <= len; i++) {
        dest[len - i] = nb % 10 + 48;
        nb /= 10;
    }
    return (dest);
}

void prepare_score(params_t *params, sfText *score_name, sfText *high_name)
{
    char *score = my_int_to_str(params->numberScore);
    char *high_score = my_int_to_str(params->highNumber);
    sfVector2f pos1 = {0, 80};
    sfVector2f pos2 = {400, 0};
    sfVector2f pos3 = {400, 80};

    sfText_setString(score_name, "Score:");
    sfText_setString(high_name, "High-Score:");
    sfText_setPosition(high_name, pos1);
    sfText_setFont(score_name, params->font);
    sfText_setFont(high_name, params->font);
    sfText_setString(params->scoreText, score);
    sfText_setString(params->highText, high_score);
    sfText_setPosition(params->highText, pos3);
    sfText_setPosition(params->scoreText, pos2);
    free(score);
    free(high_score);
}

void draw_score(params_t *params)
{
    sfText *score_name = sfText_create();
    sfText *high_name = sfText_create();

    prepare_score(params, score_name, high_name);
    params->numberScore = params->now.microseconds / 5000;
    if (params->numberScore > params->highNumber)
        params->highNumber = params->numberScore;
    sfSprite_setTexture(params->score_backrground, params->scoreTexture,
        sfTrue);
    sfRenderWindow_drawSprite(params->window, params->score_backrground, NULL);
    sfRenderWindow_drawText(params->window, score_name, NULL);
    sfRenderWindow_drawText(params->window, high_name, NULL);
    sfRenderWindow_drawText(params->window, params->scoreText, NULL);
    sfRenderWindow_drawText(params->window, params->highText, NULL);
}