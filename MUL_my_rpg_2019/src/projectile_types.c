/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

projectile_t *init_projectile_values(projectile_t *new)
{
    new->type = 1;
    new->move.x *= 5;
    new->move.y *= 5;
    sfIntRect rect = {180, 0, 8, 5};
    sfVector2f origin = {4, 3};
    sfVector2f scale = {4, 4};
    new->scale = scale;
    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setOrigin(new->sprite, origin);
    sfSprite_setScale(new->sprite, scale);
    return (new);
}

projectile_t *init_wave_values(projectile_t *new)
{
    new->type = 2;
    new->move.x *= 6;
    new->move.y *= 6;
    sfIntRect rect = {180, 6, 8, 19};
    sfVector2f origin = {4, 9};
    sfVector2f scale = {3, 3};
    new->scale = scale;
    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setOrigin(new->sprite, origin);
    sfSprite_setScale(new->sprite, scale);
    return (new);
}

projectile_t *init_beam_values(projectile_t *new)
{
    new->type = 3;
    new->move.x *= 7;
    new->move.y *= 7;
    sfIntRect rect = {180, 26, 5, 6};
    sfVector2f origin = {2, 3};
    sfVector2f scale = {3, 2};
    new->scale = scale;
    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setOrigin(new->sprite, origin);
    sfSprite_setScale(new->sprite, scale);
    return (new);
}