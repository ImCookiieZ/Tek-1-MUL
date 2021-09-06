/*
** EPITECH PROJECT, 2019
** settings_keymap.c
** File description:
** keymap
*/

#include "../include/all_includes.h"

const double keymap_texts[9][4] = {
        {670, 300, 80, 190},
        {670, 200, 80, 160},
        {670, 400, 80, 190},
        {670, 500, 80, 270},
        {820, 900, 80, 180},
        {1250, 300, 80, 50},
        {1250, 200, 80, 50},
        {1250, 400, 80, 50},
        {1250, 500, 80, 50},
};

void draw_keymap(objects *object)
{
    sfRenderWindow_clear(object->window, sfBlack);
    set_text(object, keymap_texts[0], "WALK UP", 0);
    set_text(object, keymap_texts[1], "WALK DOWN", 0);
    set_text(object, keymap_texts[2], "WALK RIGHT", 0);
    set_text(object, keymap_texts[3], "WALK LEFT", 0);
    set_text(object, keymap_texts[4], "BACK", 1);
    set_text(object, keymap_texts[5], object->settings->up_string, 1);
    set_text(object, keymap_texts[6], object->settings->down_string, 1);
    set_text(object, keymap_texts[7], object->settings->right_string, 1);
    set_text(object, keymap_texts[8], object->settings->left_string, 1);
    sfRenderWindow_display(object->window);
}

int get_key_two(objects *object, int choice, char c)
{
    if (choice == 7) {
        object->settings->right_string[0] = c;
        object->settings->right_string[1] = '\0';
        return 0;
    }
    if (choice == 8) {
        object->settings->left_string[0] = c;
        object->settings->left_string[1] = '\0';
        return 0;
    }
    return 1;
}

int get_key(objects *object, int choice)
{
    char c;
    if (object->event.text.type == sfEvtKeyPressed) {
        c = object->event.text.unicode + 65;
        if (c == 'P' || c == 'I' || c == 'E') return 0;
        if (c < 65 || c > 90) return 0;
        if (choice == 5) {
            object->settings->up_string[0] = c;
            object->settings->up_string[1] = '\0';
            return 0;
        }
        if (choice == 6) {
            object->settings->down_string[0] = c;
            object->settings->down_string[1] = '\0';
            return 0;
        }
        if (get_key_two(object, choice, c) == 1)
            return 1;
        else return 0;
    }
    return 1;
}

void change_keymap(objects *object)
{
    object->settings->up = object->settings->up_string[0] - 65;
    object->settings->down = object->settings->down_string[0] - 65;
    object->settings->left = object->settings->left_string[0] - 65;
    object->settings->right = object->settings->right_string[0] - 65;
}

int keymap(objects *object)
{
    int choice = 0;
    int flag = 0;

    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)\
        && flag == 0) {
            choice = menu_button(object, keymap_texts, 9);
            if (choice == 4)
                return (0);
            if (choice > 4)
                flag = 1;
        }
        if (choice > 4) {
            flag = get_key(object, choice);
            change_keymap(object);
        }
        draw_keymap(object);
    }
    return 0;
}
