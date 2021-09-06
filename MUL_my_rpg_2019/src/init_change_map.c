/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_change_map.c
*/

#include "../include/all_includes.h"

void add_names_to_maps(const objects *obj)
{
    obj->map_names[0][3] = my_strdup("boss_map");
    obj->map_names[0][5] = my_strdup("gras_3");
    obj->map_names[0][6] = my_strdup("gras_5");

    obj->map_names[1][1] = my_strdup("cave_2");
    obj->map_names[1][2] = my_strdup("cave_1");
    obj->map_names[1][3] = my_strdup("main");
    obj->map_names[1][4] = my_strdup("gras_1");
    obj->map_names[1][5] = my_strdup("gras_2");

    obj->map_names[2][1] = my_strdup("cave_4");
    obj->map_names[2][3] = my_strdup("water_4");
    obj->map_names[2][5] = my_strdup("gras_4");

    obj->map_names[3][0] = my_strdup("cave_5");
    obj->map_names[3][1] = my_strdup("cave_3");
    obj->map_names[3][3] = my_strdup("water_2");
    obj->map_names[3][4] = my_strdup("water_5");
    obj->map_names[4][3] = my_strdup("water_1");
    obj->map_names[4][4] = my_strdup("water_3");
}

void create_for_scole(objects *obj, objects *obj2, char *fore, char *map)
{
    sfVector2f scale4 = {4.3, 4.3};

    obj2->map_texture = obj->map_texture;
    obj2->map_sprite = obj->map_sprite;
    obj2->foreground_texture = obj->foreground_texture;
    obj2->foreground_sprite = obj->foreground_sprite;
    obj->map_texture = sfTexture_createFromFile(map, NULL);
    obj->foreground_texture = sfTexture_createFromFile(fore, NULL);
    obj->map_sprite = create_my_sprite(obj->map_sprite, obj->map_texture);
    obj->foreground_sprite = create_my_sprite(obj->foreground_sprite,
        obj->foreground_texture);
    sfSprite_scale(obj->foreground_sprite, (scale4));
    sfSprite_scale(obj->map_sprite, (scale4));
    free(map);
    free(fore);
}

void create_scroller(const objects *obj2, const objects *obj, sfVector2f *mover,
    sfVector2f *mover2)
{
    sfSprite_move(obj->map_sprite, (*mover));
    sfSprite_move(obj2->map_sprite, (*mover));
    sfSprite_move(obj->player->sprite, (*mover2));
    sfSprite_move(obj->foreground_sprite, (*mover));
    sfSprite_move(obj2->foreground_sprite, (*mover));
    sfRenderWindow_clear(obj->window, sfBlack);
    sfRenderWindow_drawSprite(obj->window, obj->map_sprite, NULL);
    sfRenderWindow_drawSprite(obj->window, obj2->map_sprite, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->player->sprite, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->foreground_sprite, NULL);
    sfRenderWindow_drawSprite(obj->window, obj2->foreground_sprite,
        NULL);
    sfRenderWindow_display(obj->window);
}