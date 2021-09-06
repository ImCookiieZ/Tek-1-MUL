/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void set_variables_enemy(const objects *obj, enemy_t *new)
{
    new->type = get_type(obj->map_x, obj->map_y);
    new->texture = get_texture(new->type);
    new->life_texture = sfTexture_createFromFile("assets/red.png", NULL);
    new->life_sprite = create_my_sprite(new->life_sprite, new->life_texture);
    new->sprite = create_my_sprite(new->sprite, new->texture);
    new->next = NULL;
    new->hp = 100;
    new->damage = 5 * mult_effective(obj->player->choice, new->type);
    new->clock = sfClock_create();
    new->move_clock = sfClock_create();
    new->anim = 1;
    new->last_hit = sfTime_Zero;
}

enemy_t *init_enemy(objects *obj, sfVector2f pos)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    sfVector2f scale = {4, 4};
    sfIntRect rect = {0, 60, 30, 30};
    sfVector2f origin = {15, 15};
    if (new == NULL)
        return (NULL);
    set_variables_enemy(obj, new);
    sfSprite_setTextureRect(new->sprite, rect);
    sfSprite_setOrigin(new->sprite, origin);
    sfSprite_setScale(new->sprite, scale);
    sfSprite_setPosition(new->sprite, pos);
    return (new);
}

enemy_t *add_enemy(objects *obj)
{
    enemy_t *og = obj->enemy;

    if (og == NULL)
        obj->enemy = init_enemy(obj, get_random_pos(obj));
    else {
        for (; obj->enemy->next != NULL; obj->enemy =
            obj->enemy->next);
        obj->enemy->next = init_enemy(obj, get_random_pos(obj));
        obj->enemy = og;
    }
    return (obj->enemy);
}

enemy_t *destroy_find(const objects *obj, enemy_t *og, enemy_t *pre)
{
    for (enemy_t *tmp = og; tmp != NULL; pre = tmp, tmp = tmp->next) {
        if (tmp->hp < 1) {
            obj->player->hp += 5 *
                mult_effective(tmp->type, obj->player->choice);
            obj->player->xp += 5 *
                mult_effective(tmp->type, obj->player->choice);;
        }
        if (tmp->hp < 1 && pre != NULL) {
            pre->next = tmp->next;
            destroy_enemy(tmp);
            break;
        }
        else if (tmp->hp < 1 && pre == NULL) {
            og = og->next;
            destroy_enemy(tmp);
            break;
        }
    }
    return og;
}

void pop_enemy(objects *obj)
{
    enemy_t *og = obj->enemy;
    enemy_t *pre = NULL;
    if (og != NULL && og->next == NULL && og->hp < 1) {
        obj->player->hp += 5;
        obj->player->xp += 5 * mult_effective(obj->player->choice,
            obj->enemy->type);
        destroy_enemy(og);
        og = NULL;
    } else {
        og = destroy_find(obj, og, pre);
    }
    obj->enemy = og;
}