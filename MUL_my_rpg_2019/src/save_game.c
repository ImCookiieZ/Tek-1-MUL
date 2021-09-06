/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save_game.c
*/

#include "../include/all_includes.h"

void save_even_more(const objects *obj, FILE *ptr)
{
    my_put_nbr_f(ptr, obj->player->xp_level);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, (int) obj->player->damage);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, (int) obj->map_type);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->level);
    my_putchar_f(ptr, '\n');
    fclose(ptr);
}

void save_more(const objects *obj, FILE *ptr)
{
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->item_is_found);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->settings->right);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->settings->left);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->max_hp);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->settings->up);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->settings->down);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->dir);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->gender);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->boss.is_active);
    my_putchar_f(ptr, '\n');
    save_even_more(obj, ptr);
}

int save_game(objects *obj)
{
    FILE *ptr = fopen(SAVE_FILE, "w");
    if (ptr == NULL) return (84);
    sfVector2f pos = sfSprite_getPosition(obj->player->sprite);
    my_put_nbr_f(ptr, obj->stone_destroyed);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->choice);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->map_x);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->map_y);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->hp);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, obj->player->xp);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, (int) pos.x);
    my_putchar_f(ptr, '\n');
    my_put_nbr_f(ptr, (int) pos.y);
    save_more(obj, ptr);
    return (0);
}
