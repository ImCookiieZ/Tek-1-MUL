/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_boss.c
*/

#include "../include/all_includes.h"

void destroy_boss_stuff(objects *obj)
{
    sfMusic_stop(obj->musics[obj->map_type]);
    sfSound_play(obj->sounds[6]);
    sfTexture_destroy(obj->boss.texture);
    sfSprite_destroy(obj->boss.sprite);
    sfClock_destroy(obj->boss.animator);
    sfClock_destroy(obj->boss.move_clock);
    sfClock_destroy(obj->boss.teleport);
}

int destroy_boss(objects *obj)
{
    static float i = 5.0f;
    sfVector2f scale = {0, 0};
    obj->boss.is_active = 0;
    if (i > 0.1f) {
        scale.x = i;
        scale.y = i;
        i -= 0.25f;
        sfSprite_setScale(obj->boss.sprite, scale);
        return (1);
    } else {
        destroy_boss_stuff(obj);
        obj->boss.is_destroyed = 1;
        reset_game(obj);
        i = 5.0f;
        return (0);
    }
}

boss_t init_boss_variables(boss_t *new, objects *obj)
{
    (*new).texture = sfTexture_createFromFile("assets/enemies/boss1.png", NULL);
    (*new).sprite = sfSprite_create();
    (*new).sprite = create_my_sprite((*new).sprite, (*new).texture);
    (*new).life_texture = sfTexture_createFromFile("assets/red.png", NULL);
    (*new).life_sprite = create_my_sprite((*new).life_sprite,
        (*new).life_texture);
    (*new).hp = 500 * (int)(((double)(obj->player->xp_level) * 0.1 + 1));
    (*new).anim = 0;
    (*new).damage = 30 + 5 * (int)(((double)(obj->player->xp_level) * 0.1));
    (*new).is_active = 0;
    (*new).teleport = sfClock_create();
    (*new).move_clock = sfClock_create();
    (*new).animator = sfClock_create();
    (*new).is_destroyed = 0;
    return (*new);
}

boss_t init_boss(objects *obj)
{
    boss_t new;
    sfVector2f scale = {5, 5};
    sfVector2f pos = {500, 225};
    sfVector2f origin = {15, 15};
    sfIntRect rect = {0, 60, 30, 30};
    new = init_boss_variables(&new, obj);
    sfSprite_setTextureRect(new.sprite, rect);
    sfSprite_setOrigin(new.sprite, origin);
    sfSprite_setPosition(new.sprite, pos);
    sfSprite_setScale(new.sprite, scale);
    return (new);
}