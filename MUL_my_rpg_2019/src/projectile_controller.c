/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

void projectile_controller(objects *obj)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime
    (obj->projectile->clock)) > 0.016) {
        sfSprite_move(obj->projectile->sprite, obj->projectile->move);
        sfClock_restart(obj->projectile->clock);
    }
    sfRenderWindow_drawSprite(obj->window, obj->projectile->sprite,
        NULL);
    if (sfTime_asSeconds(sfClock_getElapsedTime(obj->projectile->destroy)) > 3)
        obj->projectile->hit = 1;
    hit_projectile(obj);
    collision_projectile(obj, 4, 2);
    link_collision(obj, 4, 2);
    if (obj->boss.is_active == 1)
        hit_boss_projectile(obj);
}

void wave_controller(objects *obj)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime
    (obj->projectile->clock)) > 0.016) {
        sfSprite_move(obj->projectile->sprite, obj->projectile->move);
        sfClock_restart(obj->projectile->clock);
    }
    sfRenderWindow_drawSprite(obj->window, obj->projectile->sprite,
        NULL);
    obj->projectile->scale.x += 0.05f;
    obj->projectile->scale.y += 0.05f;
    sfSprite_setScale(obj->projectile->sprite, obj->projectile->scale);
    if (sfTime_asSeconds(sfClock_getElapsedTime
    (obj->projectile->destroy)) > 0.75)
        obj->projectile->hit = 1;
    hit_wave(obj);
    collision_projectile(obj, 4, 6);
    link_collision(obj, 4, 6);
    if (obj->boss.is_active == 1)
        hit_boss_projectile(obj);
}

void beam_controller(objects *obj)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime
    (obj->projectile->clock)) > 0.016) {
        sfSprite_move(obj->projectile->sprite, obj->projectile->move);
        sfClock_restart(obj->projectile->clock);
    }
    sfRenderWindow_drawSprite(obj->window, obj->projectile->sprite,
        NULL);
    obj->projectile->scale.x -= 0.01f;
    obj->projectile->scale.y -= 0.01f;
    sfSprite_setScale(obj->projectile->sprite, obj->projectile->scale);
    if (sfTime_asSeconds(sfClock_getElapsedTime
    (obj->projectile->destroy)) > 0.5) obj->projectile->hit = 1;
    hit_beam(obj, 2, 2);
    collision_projectile(obj, 2, 3);
    link_collision(obj, 2, 3);
    if (obj->boss.is_active == 1)
        hit_boss_projectile(obj);
}

void skill_controller(objects *obj)
{
    projectile_t *og = obj->projectile;
    change_skill(obj);
    if (og == NULL)
        return;
    else {
        for (; obj->projectile != NULL; obj->projectile =
            obj->projectile->next) {
            if (obj->projectile->type == 1)
                projectile_controller(obj);
            if (obj->projectile->type == 2)
                wave_controller(obj);
            if (obj->projectile->type == 3)
                beam_controller(obj);
        }
        obj->projectile = og;
    }
}