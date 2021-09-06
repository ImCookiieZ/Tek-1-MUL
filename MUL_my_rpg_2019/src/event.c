/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int check_button(objects *object, double const buttons[][4], int len)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(object->window);

    for (int i = 0; i < len; i += 1) {
        if ((m_pos.x >= buttons[i][0] && m_pos.x <=
        buttons[i][0] + buttons[i][3]) && (m_pos.y >=
        buttons[i][1] && m_pos.y <= buttons[i][1] + buttons[i][2])) {
            return (i);
        }
    }
    return (-1);
}

int menu_button(objects *object, const double buttons[][4], int len)
{
    if (object->event.type == sfEvtClosed)
        sfRenderWindow_close(object->window);
    if (object->event.type == sfEvtMouseButtonReleased) {
        if (object->event.mouseButton.button == sfMouseLeft)
            return (check_button(object, buttons, len));
    }
    return (-1);
}

