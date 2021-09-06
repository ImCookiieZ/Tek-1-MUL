/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

float set_rot(sfVector2f move)
{
    float rot = 0;
    if (move.y > 0) {
        rot = 90;
        if (move.x > 0)
            rot -= 45;
        else if (move.x < 0)
            rot += 45;
    }
    else if (move.y < 0) {
        rot = 270;
        if (move.x > 0)
            rot += 45;
        else if (move.x < 0)
            rot -= 45;
    } else {
        if (move.x < 0)
            rot = 180;
        if (move.x > 0)
            rot = 0;
    }
    return (rot);
}

sfVector2f set_move(const int *dirs, sfSprite *sprite)
{
    sfVector2f move = {0, 0};
    if (dirs[2] && !dirs[3])
        move.x = -1;
    if (!dirs[2] && dirs[3])
        move.x = 1;
    if (dirs[0] && !dirs[1])
        move.y = -1;
    if (!dirs[0] && dirs[1])
        move.y = 1;
    sfSprite_setRotation(sprite, set_rot(move));
    return (move);
}

projectile_t *init_projectile(objects *obj, int *dirs)
{
    projectile_t *new = malloc(sizeof(projectile_t));
    if (new  == NULL)
        return (NULL);
    new->sprite = create_my_sprite(new->sprite, obj->player->texture);
    new->hit = 0;
    new->next = NULL;
    sfSprite_setPosition(new->sprite, sfSprite_getPosition
    (obj->player->sprite));
    new->move = set_move(dirs, new->sprite);
    new->clock = sfClock_create();
    new->destroy = sfClock_create();
    if (new->move.x == 0 && new->move.y == 0)
        return (NULL);
    if (obj->skill_index == 1)
        new = init_projectile_values(new);
    if (obj->skill_index == 2)
        new = init_wave_values(new);
    if (obj->skill_index == 3)
        new = init_beam_values(new);
    return (new);
}

projectile_t *add_projectile(objects *obj, int *dirs)
{
    projectile_t *og = obj->projectile;

    if (og == NULL)
            obj->projectile = init_projectile(obj, dirs);
    else {
        for (; obj->projectile->next != NULL; obj->projectile =
            obj->projectile->next);
        obj->projectile->next = init_projectile(obj, dirs);
        obj->projectile = og;
    }
    if (obj->skill_index == 2)
        sfSound_play(obj->sounds[0]);
    else if (obj->skill_index == 1)
        sfSound_play(obj->sounds[1]);
    if (obj->skill_index == 3 && sfSound_getStatus(obj->sounds[8]) != sfPlaying)
        sfSound_play(obj->sounds[8]);
    return (obj->projectile);
}

void pop_projectile(objects *obj)
{
    projectile_t *og = obj->projectile;
    projectile_t *pre = NULL;
    if (og != NULL && og->next == NULL && og->hit) {
        destroy_projectile(og);
        og = NULL;
    } else {
        for (projectile_t *tmp = og; tmp != NULL; pre = tmp, tmp =
            tmp->next) {
            if (tmp->hit && pre != NULL) {
                pre->next = tmp->next;
                destroy_projectile(tmp);
                break;
            }
            else if (tmp->hit && pre == NULL) {
                og = og->next;
                destroy_projectile(tmp);
                break;
            }
        }
    }
    obj->projectile = og;
}