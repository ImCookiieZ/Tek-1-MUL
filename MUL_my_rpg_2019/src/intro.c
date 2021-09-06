/*
** EPITECH PROJECT, 2019
** intro.c
** File description:
** intro
*/

#include "../include/all_includes.h"

const double texts[4][4] = {
        {750 + 50, 500, 80, 300},
        {750 + 50, 620, 80, 300},
        {750 + 50, 740, 80, 300},
        {500, 300, 100, 300}
};

void intro_destroy(sfClock *clock, sfClock *clocky)
{
    sfClock_destroy(clock);
    sfClock_destroy(clocky);
}

void show(objects *obj, intro_t *intro, sfSprite *bg)
{
    intro_t *tmp = intro;
    intro_t *head = intro;
    sfClock *clock = NULL;
    sfClock *clocky = NULL;
    clock = sfClock_create();
    clocky = sfClock_create();
    sfText *text = create_intro_text();

    while (sfRenderWindow_isOpen(obj->window)) {
        while (sfRenderWindow_pollEvent(obj->window, &obj->event)) {
            if (obj->event.type == sfEvtClosed)
                sfRenderWindow_close(obj->window);
            if (obj->event.type == sfEvtKeyPressed)
                if (obj->event.key.code == sfKeySpace) return;
        }
        if (set_all_intro(obj, tmp, text, bg) == -1) return;
        tmp = move_x(tmp, head, clock);
        tmp = move_y(tmp, head, clocky);
    }
    intro_destroy(clock, clocky);
}

int choose_language(objects *object, sfSprite *bg)
{
    int choice = 0;

    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            choice = menu_button(object, texts, 3);
            if (choice != -1)
                return (choice + 1);
        }
        sfRenderWindow_clear(object->window, sfBlack);
        sfRenderWindow_drawSprite(object->window, bg, NULL);
        set_text(object, texts[0], "ENGLISH", 1);
        set_text(object, texts[1], "FRENCH", 1);
        set_text(object, texts[2], "GERMAN", 1);
        set_text(object, texts[3], "CHOOSE YOUR LANGUAGE", 0);
        sfRenderWindow_display(object->window);
    }
    return -1;
}

void intro(objects *obj)
{
    intro_t *intro = NULL;
    sfSprite *bg = NULL;
    sfTexture *bg_t = NULL;
    int choice = 0;

    bg_t = sfTexture_createFromFile("assets/intro.png", NULL);
    bg = create_my_sprite(bg, bg_t);
    choice = choose_language(obj, bg);
    if (choice == 1)
        sfMusic_play(obj->musics[9]);
    if (choice == 2)
        sfMusic_play(obj->musics[8]);
    if (choice == 3)
        sfMusic_play(obj->musics[10]);
    intro = get_input(intro, choice);
    if (!intro)
        return;
    show(obj, intro, bg);
}
