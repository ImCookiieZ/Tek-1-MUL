/*
** EPITECH PROJECT, 2019
** intro_move.c
** File description:
** move
*/

#include "../include/all_includes.h"

const double intro_text[1][4] = {
        {80, 940, 50, 50}
};

void set_intro_text(objects *object, intro_t *tmp, sfText *text)
{
    sfVector2f pos = {tmp->x, tmp->y};
    sfVector2f scale = {tmp->size, tmp->size};
    sfText_setPosition(text, pos);
    sfText_setString(text, tmp->s);
    sfText_setCharacterSize(text, 30);
    sfText_setScale(text, scale);
    sfText_setColor(text, sfYellow);
    sfText_setOutlineThickness(text, 1);
    sfText_setOutlineColor(text, sfBlack);
    sfRenderWindow_drawText(object->window, text, NULL);
}

sfText *create_intro_text(void)
{
    sfFont *font = NULL;
    sfText *text = NULL;

    font = sfFont_createFromFile("assets/volleyball.ttf");
    text = sfText_create();
    sfText_setFont(text, font);

    return text;
}

int set_all_intro(objects *obj, intro_t *tmp, sfText *text, sfSprite *bg)
{
    int count = 0;

    sfRenderWindow_clear(obj->window, sfBlack);
    sfRenderWindow_drawSprite(obj->window, bg, NULL);
    set_text(obj, intro_text[0], "PRESS SPACE TO CONTINUE", 0);
    while (tmp) {
        if (tmp->size > 0 && tmp->y < 850) {
            set_intro_text(obj, tmp, text);
        }
        if (tmp->size > 0 && tmp->y > 0) count++;
        tmp = tmp->next;
    }
    if (count == 0) return -1;
    sfRenderWindow_display(obj->window);
    return 0;
}

intro_t *move_y(intro_t *tmp, intro_t *head, sfClock *clocky)
{
    if (get_seconds(sfClock_getElapsedTime(clocky)) > 0.02) {
        while (tmp) {
            tmp->y -= 0.8;
            tmp = tmp->next;
        }
        sfClock_restart(clocky);
    }
    tmp = head;
    return tmp;
}

intro_t *move_x(intro_t *tmp, intro_t *head, sfClock *clock)
{
    tmp = head;
    if (get_seconds(sfClock_getElapsedTime(clock)) > 0.02) {
        while (tmp) {
            if (tmp->y >= -100 && tmp->y < 1080) {
                tmp->size -= 0.0015;
                tmp->x += 1.7;
            }
            tmp = tmp->next;
        }
        sfClock_restart(clock);
    }
    tmp = head;
    return tmp;
}