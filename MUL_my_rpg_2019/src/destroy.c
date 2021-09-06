/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void destroy_projectile(projectile_t *node)
{
    sfSprite_destroy(node->sprite);
    sfClock_destroy(node->clock);
    sfClock_destroy(node->destroy);
    free(node);
}

void destroy_enemy(enemy_t *node)
{
    sfTexture_destroy(node->texture);
    sfSprite_destroy(node->sprite);
    sfClock_destroy(node->clock);
    sfClock_destroy(node->move_clock);
    free(node);
}

void destroy_music(objects *object)
{
    for (int i = 0; object->musics[i] != NULL; i++)
        sfMusic_destroy(object->musics[i]);
    free(object->musics);
}

void destroy_sound(objects *object)
{
    for (int i = 0; object->sounds[i] != NULL; i++)
        sfSound_destroy(object->sounds[i]);
    free(object->sounds);
    for (int i = 0; object->soundsbuf[i] != NULL; i++)
        sfSoundBuffer_destroy(object->soundsbuf[i]);
    free(object->soundsbuf);
}

void destroy_stone_stuff(objects *object)
{
    sfSprite_destroy(object->stone);
    sfTexture_destroy(object->stone_t);
    sfClock_destroy(object->stone_clock);
}