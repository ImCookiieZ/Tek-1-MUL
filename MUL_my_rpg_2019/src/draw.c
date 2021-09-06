/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw.c
*/

#include "../include/all_includes.h"

int switch_for_effect(objects *obj, int effect)
{
    int r = rand() % 3;
    if (obj->effect.last.microseconds < sfClock_getElapsedTime(obj->effect
    .clocky).microseconds) {
        sfClock_restart(obj->effect.clocky);
        obj->effect.last.microseconds = 60000000;
        switch (r) {
            case 3:
                effect = 1;
                break;
            case 2:
                effect = 2;
                break;
            case 1:
                effect = 0;
                break;
            default:
                break;
        }
    }
    return effect;
}

void draw_effect(objects *obj)
{
    static int effect = 1;
    sfVector2f mover = {0, 1081};
    sfVector2f tart = {0, 0};
    sfVector2f second = {0, -1080};
    effect = switch_for_effect(obj, effect);
    if (effect == 1) {
        sfRenderWindow_drawSprite(obj->window, obj->effect.sprite_1, NULL);
        sfSprite_move(obj->effect.sprite_1, second);
        sfRenderWindow_drawSprite(obj->window, obj->effect.sprite_1, NULL);
        sfSprite_move(obj->effect.sprite_1, mover);
        if (sfSprite_getPosition(obj->effect.sprite_1).y > 1080)
            sfSprite_setPosition(obj->effect.sprite_1, tart);
    }
    if (effect == 2) {
        sfRenderWindow_drawSprite(obj->window, obj->effect.sprite_2, NULL);
        sfSprite_move(obj->effect.sprite_2, second);
        sfRenderWindow_drawSprite(obj->window, obj->effect.sprite_2, NULL);
        sfSprite_move(obj->effect.sprite_2, mover);
        if (sfSprite_getPosition(obj->effect.sprite_2).y > 1080)
            sfSprite_setPosition(obj->effect.sprite_2, tart);
    }
}

void controll_draw(objects *obj)
{
    sfRenderWindow_clear(obj->window, sfBlack);
    change_player(obj);
    sfRenderWindow_drawSprite(obj->window, obj->map_sprite, NULL);
    pop_projectile(obj);
    skill_controller(obj);
    check_new_projectile(obj);
    draw_npc(obj->window, obj->map_x, obj->map_y);
    pop_enemy(obj);
    enemy_controller(obj);
    draw_player(obj);
    if (obj->map_x == 3 && obj->map_y == 0)
        boss_controller(obj);
}

void draw(objects *obj)
{
    if (sfClock_getElapsedTime(obj->player->hp_generator_clock).microseconds >
    obj->player->hp_creator_time.microseconds && obj->player->hp < 100) {
        sfClock_restart(obj->player->hp_generator_clock);
        obj->player->hp += 5;
    }
    if (obj->player->hp > obj->player->max_hp)
        obj->player->hp = obj->player->max_hp;
    controll_draw(obj);
    sfRenderWindow_drawSprite(obj->window, obj->foreground_sprite, NULL);
    draw_effect(obj);
    get_player_direction(obj);
    change_healthbar(obj);
    show_items(obj, obj->player->choice);
    if (obj->map_type == MAIN_MUSIC && obj->stone_destroyed == 0)
        sfRenderWindow_drawSprite(obj->window, obj->stone, NULL);
    if (obj->map_x == 3 && obj->map_y == 1)
        is_chatting(obj);
    if (obj->hit_stone == 1 && obj->stone_destroyed == 0)
        destroy_stone(obj);
    sfRenderWindow_display(obj->window);
}