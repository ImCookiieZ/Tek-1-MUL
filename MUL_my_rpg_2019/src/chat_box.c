/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

const sfVector2f pos1 = {135, 310};
const sfVector2f pos3 = {1350, 90};
const sfVector2f pos2 = {1750, 620};
const double chat_text[4] = {280, 705, 60, 0};

int my_arraylen(char **array)
{
    int i = 0;
    for (; array[i]; i += 1);
    return (i);
}

void draw_box(sfRenderWindow *window)
{
    sfVector2f scale = {10, 6};
    sfVector2f pos = {250, 700};
    sfTexture *texture = sfTexture_createFromFile("assets/chat.png", NULL);
    sfSprite *box = sfSprite_create();
    box = create_my_sprite(box, texture);
    sfSprite_setPosition(box, pos);
    sfSprite_setScale(box, scale);
    sfRenderWindow_drawSprite(window, box, NULL);
    sfTexture_destroy(texture);
    sfSprite_destroy(box);
}

int set_chat_text(objects *obj, const char npc_text[3][200], int len, int npc)
{
    static int i = 0;
    static int save = 0;

    if (save != 0 && save != npc)
        i = 0;
    set_text(obj, chat_text, npc_text[i], 0);
    if (sfTime_asSeconds(obj->gametime) - sfTime_asSeconds(obj->continue_time) >
        0.2) {
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            i += 1;
        obj->continue_time = obj->gametime;
    }
    save = npc;
    if (i >= len) {
        i = 0;
        return (-1);
    }
    return (0);
}

void is_chatting(objects *obj)
{
    if (sfTime_asSeconds(obj->gametime) -
    sfTime_asSeconds(obj->chat_time) > 0.2) {
        if (sfKeyboard_isKeyPressed(sfKeyE) && obj->is_chatting == 1) {
            obj->is_chatting = 0;
            sfSound_play(obj->sounds[4]);
        }
        else if (sfKeyboard_isKeyPressed(sfKeyE)
        && !obj->is_chatting && npc_trigger(sfSprite_getPosition
        (obj->player->sprite), pos1, pos2, pos3) != -1) {
            obj->is_chatting = 1;
            sfSound_play(obj->sounds[3]);
        }
        obj->chat_time = obj->gametime;
    }
    if (obj->is_chatting) {
        draw_box(obj->window);
        if (choose_text(obj) == -1 || npc_trigger(sfSprite_getPosition
        (obj->player->sprite), pos1, pos2, pos3) == -1)
            obj->is_chatting = 0;
    }
}