/*
** EPITECH PROJECT, 2020
** music
** File description:
** part 2 music
*/

#include "../include/all_includes.h"

void check_which_music(objects *object)
{
    if (object->map_x < 3)
        sfMusic_play(object->musics[CAVE_MUSIC]);
    if (object->map_x == 3 && object->map_y == 1)
        sfMusic_play(object->musics[MAIN_MUSIC]);
    if ((object->map_x == 3 || object->map_x == 4) && object->map_y > 1)
        sfMusic_play(object->musics[BEACH_MUSIC]);
    if ((object->map_x == 4 && object->map_y == 1) || object->map_x > 4)
        sfMusic_play(object->musics[GRASS_MUSIC]);
    if (object->map_x == 3 && object->map_y == 0)
        sfMusic_play(object->musics[BOSS_MUSIC]);
}

void play_music(objects *object, int x)
{
    for (int i = 0; object->musics[i] != NULL; i++)
        sfMusic_stop(object->musics[i]);
    sfMusic_play(object->musics[x]);
}