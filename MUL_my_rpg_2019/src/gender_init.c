/*
** EPITECH PROJECT, 2019
** Marcel Taubert - > gender_init.c
** File description:
** init
*/

#include "../include/all_includes.h"

void set_up_sprites(objects *object)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {850, 300};
    sfSprite_setScale(object->gender->female_pokemon, scale);
    sfSprite_setScale(object->gender->male_pokemon, scale);
    sfSprite_setPosition(object->gender->male_pokemon, pos);
    sfSprite_setPosition(object->gender->female_pokemon, pos);
}

void set_gender_sprite(int which, sfTexture **female_t, sfTexture **male_t)
{
    if (which == 1) {
        (*female_t) = sfTexture_createFromFile\
        ("assets/glumanda_female.png", NULL);
        (*male_t) = sfTexture_createFromFile("assets/glumanda_male.png", NULL);
    }
    if (which == 2) {
        (*female_t) = sfTexture_createFromFile\
        ("assets/bisasam_female.png", NULL);
        (*male_t) = sfTexture_createFromFile("assets/bisasam_male.png", NULL);
    }
    if (which == 3) {
        (*female_t) = sfTexture_createFromFile\
        ("assets/shiggy_female.png", NULL);
        (*male_t) = sfTexture_createFromFile("assets/shiggy_male.png", NULL);
    }
}

void init_gender_sprites(objects *object, int which)
{
    sfSprite *female = NULL;
    sfTexture *female_t = NULL;
    sfSprite *male = NULL;
    sfTexture *male_t = NULL;

    set_gender_sprite(which, &female_t, &male_t);
    female = create_my_sprite(female, female_t);
    male = create_my_sprite(male, male_t);
    object->gender->male_pokemon = male;
    object->gender->male_pokemon_t = male_t;
    object->gender->female_pokemon_t = female_t;
    object->gender->female_pokemon = female;
    set_up_sprites(object);
}

void init_gender(objects *object)
{
    sfSprite *male = NULL;
    sfSprite *female = NULL;
    sfTexture *male_t = NULL;
    sfTexture *female_t = NULL;
    sfVector2f pos = {700, 500};
    gender_t *gender = NULL;
    gender = malloc(sizeof(gender_t));
    object->gender = gender;
    male_t = sfTexture_createFromFile("assets/male.png", NULL);
    female_t = sfTexture_createFromFile("assets/female.png", NULL);
    male = create_my_sprite(male, male_t);
    female = create_my_sprite(female, female_t);
    object->gender->male = male;
    object->gender->female = female;
    sfSprite_setPosition(object->gender->male, pos);
    pos.x += 300;
    sfSprite_setPosition(object->gender->female, pos);
    object->gender->male_t = male_t;
    object->gender->female_t = female_t;
    object->player->gender = 0;
}