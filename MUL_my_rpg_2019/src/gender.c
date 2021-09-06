/*
** EPITECH PROJECT, 2019
** gender.c
** File description:
** gender
*/

#include "../include/all_includes.h"

const double gender_text[2][4] = {
        {800, 900, 100, 275},
        {500, 100, 100, 300}
};

void is_gender_hit(objects *object, sfVector2f *scale, sfVector2f *set_scale,
        sfVector2f *reset_scale)
{
    if (is_sprite_hit(object, object->gender->male, 132, 200) == 1) {
        sfSprite_setScale(object->gender->male, (*scale));
        sfSprite_setScale(object->gender->female, (*reset_scale));
        if (object->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setScale(object->gender->male, (*set_scale));
            object->player->gender = 0;
        }
    }
    if (is_sprite_hit(object, object->gender->female, 145, 200) == 1) {
        sfSprite_setScale(object->gender->female, (*scale));
        sfSprite_setScale(object->gender->male, (*reset_scale));
        if (object->event.type == sfEvtMouseButtonPressed) {
            sfSprite_setScale(object->gender->female, (*set_scale));
            object->player->gender = 1;
        }
    }
}

int change_gender_buttons(objects *object)
{
    int choice;
    sfVector2f scale = {1.05, 1.05};
    sfVector2f set_scale = {1.2, 1.2};
    sfVector2f reset_scale = {1, 1};

    is_gender_hit(object, &scale, &set_scale, &reset_scale);
    choice = menu_button(object, gender_text, 1);
    return choice;
}

void draw_gender(objects *object)
{
    sfRenderWindow_clear(object->window, sfBlack);
    sfRenderWindow_drawSprite(object->window, object->gender->male, NULL);
    sfRenderWindow_drawSprite(object->window, object->gender->female, NULL);
    if (object->player->gender == 0)
        sfRenderWindow_drawSprite\
        (object->window, object->gender->male_pokemon, NULL);
    else
        sfRenderWindow_drawSprite\
        (object->window, object->gender->female_pokemon, NULL);
    set_text(object, gender_text[0], "START", 1);
    set_text(object, gender_text[1], "CHOOSE YOUR GENDER", 0);
    sfRenderWindow_display(object->window);
}

int choose_gender(objects *object, int which)
{
    int choice = 0;
    init_gender_sprites(object, which);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = change_gender_buttons(object);
            if (choice == 0) {
                play_music(object, object->map_type);
                init_hud_frame(object);
                return (gameloop(object));
            }
        }
        draw_gender(object);
    }
    return 0;
}