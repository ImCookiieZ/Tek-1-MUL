/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

sfTexture *get_water_tex(void)
{
    int random = rand() % 6;

    if (random == 0)
        return (sfTexture_createFromFile("assets/enemies/water1.png", NULL));
    if (random == 1)
        return (sfTexture_createFromFile("assets/enemies/water2.png", NULL));
    if (random == 2)
        return (sfTexture_createFromFile("assets/enemies/water3.png", NULL));
    if (random == 3)
        return (sfTexture_createFromFile("assets/enemies/water4.png", NULL));
    if (random == 4)
        return (sfTexture_createFromFile("assets/enemies/water5.png", NULL));
    if (random == 5)
        return (sfTexture_createFromFile("assets/enemies/water6.png", NULL));
    return (NULL);
}

sfTexture *get_plats_tex(void)
{
    int random = rand() % 6;

    if (random == 0)
        return (sfTexture_createFromFile("assets/enemies/plants1.png", NULL));
    if (random == 1)
        return (sfTexture_createFromFile("assets/enemies/plants2.png", NULL));
    if (random == 2)
        return (sfTexture_createFromFile("assets/enemies/plants3.png", NULL));
    if (random == 3)
        return (sfTexture_createFromFile("assets/enemies/plants4.png", NULL));
    if (random == 4)
        return (sfTexture_createFromFile("assets/enemies/plants5.png", NULL));
    if (random == 5)
        return (sfTexture_createFromFile("assets/enemies/plants6.png", NULL));
    return (NULL);
}

sfTexture *get_fire_tex(void)
{
    int random = rand() % 6;

    if (random == 0)
        return (sfTexture_createFromFile("assets/enemies/fire1.png", NULL));
    if (random == 1)
        return (sfTexture_createFromFile("assets/enemies/fire2.png", NULL));
    if (random == 2)
        return (sfTexture_createFromFile("assets/enemies/fire3.png", NULL));
    if (random == 3)
        return (sfTexture_createFromFile("assets/enemies/fire4.png", NULL));
    if (random == 4)
        return (sfTexture_createFromFile("assets/enemies/fire5.png", NULL));
    if (random == 5)
        return (sfTexture_createFromFile("assets/enemies/fire6.png", NULL));
    return (NULL);
}

sfTexture *get_texture(int type)
{
    if (type == FIRE)
        return (get_fire_tex());
    if (type == WATER)
        return (get_water_tex());
    if (type == PLANTS)
        return (get_plats_tex());
    return (NULL);
}