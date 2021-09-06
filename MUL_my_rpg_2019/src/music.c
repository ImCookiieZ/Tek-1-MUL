/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void init_music_next(objects *object)
{
    object->musics[8] = \
    sfMusic_createFromFile("assets/music/french.ogg");
    object->musics[9] = \
    sfMusic_createFromFile("assets/music/usa.ogg");
    object->musics[10] = \
    sfMusic_createFromFile("assets/music/german.ogg");
    object->musics[11] = NULL;
    for (int i = 0; object->musics[i] != NULL; i++) {
        sfMusic_setLoop(object->musics[i], sfTrue);
        sfMusic_setVolume(object->musics[i], 50);
    }
}

void init_music_names(objects *object)
{
    object->play_game_over_music = 1;
    object->musics = malloc(sizeof(sfMusic *) * 12);
    object->musics[0] = \
    sfMusic_createFromFile("assets/music/start_menu.ogg");
    object->musics[1] = \
    sfMusic_createFromFile("assets/music/pause_menu.ogg");
    object->musics[2] = \
    sfMusic_createFromFile("assets/music/main_map.ogg");
    object->musics[3] = \
    sfMusic_createFromFile("assets/music/cave_map.ogg");
    object->musics[4] = \
    sfMusic_createFromFile("assets/music/beach_map.ogg");
    object->musics[5] = \
    sfMusic_createFromFile("assets/music/grass_map.ogg");
    object->musics[6] = \
    sfMusic_createFromFile("assets/music/boss_map.ogg");
    object->musics[7] = \
    sfMusic_createFromFile("assets/music/boss_fight.ogg");
    init_music_next(object);
}

void init_soundbuffer(objects *object)
{
    object->soundsbuf = malloc(sizeof(sfSoundBuffer *) * 10);
    object->soundsbuf[0] = \
    sfSoundBuffer_createFromFile("assets/sound/attack1.ogg");
    object->soundsbuf[1] = \
    sfSoundBuffer_createFromFile("assets/sound/attack2.ogg");
    object->soundsbuf[2] = \
    sfSoundBuffer_createFromFile("assets/sound/evolution.ogg");
    object->soundsbuf[3] = \
    sfSoundBuffer_createFromFile("assets/sound/open.ogg");
    object->soundsbuf[4] = \
    sfSoundBuffer_createFromFile("assets/sound/close.ogg");
    object->soundsbuf[5] = \
    sfSoundBuffer_createFromFile("assets/sound/lost.ogg");
    object->soundsbuf[6] = \
    sfSoundBuffer_createFromFile("assets/sound/victory.ogg");
    object->soundsbuf[7] = \
    sfSoundBuffer_createFromFile("assets/sound/found_stone.ogg");
    object->soundsbuf[8] = \
    sfSoundBuffer_createFromFile("assets/sound/attack3.ogg");
    object->soundsbuf[9] = NULL;
}

void create_sound_next(objects *object)
{
    object->sounds[8] = sfSound_create();
    sfSound_setBuffer(object->sounds[8], object->soundsbuf[8]);
    object->sounds[9] = NULL;
}

void create_music(objects *object)
{
    init_music_names(object);
    init_soundbuffer(object);
    object->sounds = malloc(sizeof(sfSound *) * 10);
    object->sounds[0] = sfSound_create();
    sfSound_setBuffer(object->sounds[0], object->soundsbuf[0]);
    object->sounds[1] = sfSound_create();
    sfSound_setBuffer(object->sounds[1], object->soundsbuf[1]);
    object->sounds[2] = sfSound_create();
    sfSound_setBuffer(object->sounds[2], object->soundsbuf[2]);
    object->sounds[3] = sfSound_create();
    sfSound_setBuffer(object->sounds[3], object->soundsbuf[3]);
    object->sounds[4] = sfSound_create();
    sfSound_setBuffer(object->sounds[4], object->soundsbuf[4]);
    object->sounds[5] = sfSound_create();
    sfSound_setBuffer(object->sounds[5], object->soundsbuf[5]);
    object->sounds[6] = sfSound_create();
    sfSound_setBuffer(object->sounds[6], object->soundsbuf[6]);
    object->sounds[7] = sfSound_create();
    sfSound_setBuffer(object->sounds[7], object->soundsbuf[7]);
    create_sound_next(object);
}