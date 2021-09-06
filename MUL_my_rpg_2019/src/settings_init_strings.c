/*
** EPITECH PROJECT, 2019
** settings_init_strings.c
** File description:
** strings
*/

#include "../include/all_includes.h"
#include <string.h>

int init_string_music_sound(objects *obj)
{
    char *music = malloc(sizeof(char) * 5);
    char *sound = malloc(sizeof(char) * 5);


    if (music == NULL)
        return -1;
    if (sound == NULL)
        return -1;
    music[0] = '\0';
    music = my_strcpy(music, "50%");
    sound[0] = '\0';
    sound = my_strcpy(sound, "100%");
    obj->settings->sound_string = sound;
    obj->settings->music_string = music;

    return 0;
}

int init_string_two(objects *objects)
{
    char *left =  malloc(sizeof(char) * 2);
    char *right = malloc(sizeof(char) * 2);

    if (right == NULL)
        return -1;
    right[0] = '\0';
    right = my_strcpy(right, "D");
    objects->settings->right_string = right;

    if (left == NULL)
        return -1;
    left[0] = '\0';
    left = my_strcpy(left, "A");
    objects->settings->left_string = left;
    return 0;
}

int init_strings(objects *objects)
{
    char *up = malloc(sizeof(char) * 2);
    char *down = malloc(sizeof(char) * 2);

    if (up == NULL)
        return -1;
    up[0] = '\0';
    up = my_strcpy(up, "W");
    objects->settings->up_string = up;

    if (down == NULL)
        return -1;
    down[0] = '\0';
    down = my_strcpy(down, "S");
    objects->settings->down_string = down;

    if (init_string_two(objects) == -1) return -1;
    if (init_string_music_sound(objects) == -1) return -1;
    if (init_fps_string(objects) == -1) return -1;
    return 0;
}
