/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int get_type(int x, int y)
{
    if (x < 3)
        return (FIRE);
    if (x < 5 && x > 2 && y > 1)
        return (WATER);
    if (x > 3 && y < 3)
        return (PLANTS);
    return (-1);
}

void animate_enemy(enemy_t *enemy)
{
    sfIntRect one = {0, 60, 30, 30};
    sfIntRect two = {0, 90, 30, 30};

    if (sfTime_asSeconds(sfClock_getElapsedTime(enemy->clock)) > 0.25) {
        if (enemy->anim == 1) {
            sfSprite_setTextureRect(enemy->sprite, two);
            enemy->anim = 2;
        } else {
            sfSprite_setTextureRect(enemy->sprite, one);
            enemy->anim = 1;
        }
        sfClock_restart(enemy->clock);
    }
}

void hit_player(objects *obj)
{
    sfVector2f player_pos = sfSprite_getPosition(obj->player->sprite);
    sfVector2f enemy_pos = sfSprite_getPosition(obj->enemy->sprite);

    if ((((player_pos.x - 8 * 4) <= (enemy_pos.x + 8 * 4) && (player_pos.x - 8 *
    4) >= (enemy_pos.x - 8 * 4)) || ((player_pos.x + 8 * 2) >= (enemy_pos.x - 8
    * 2) && (player_pos.x + 8 * 2) <= enemy_pos.x + 8 * 2)) && ((player_pos
    .y <= (enemy_pos.y + 8 * 2) && player_pos.y >= enemy_pos.y) || ((player_pos
    .y + 8 * 2) >= enemy_pos.y && (player_pos.y + 8 * 2) <= (enemy_pos.y + 8
    * 2)))) {
        if ((sfTime_asSeconds(obj->gametime) - sfTime_asSeconds
        (obj->play_hit)) > 0.5f) {
            obj->player->hp -= obj->enemy->damage * mult_effective
                (obj->enemy->type, obj->player->choice) * 0.5;
            obj->play_hit = obj->gametime;
        }
        sfClock_restart(obj->player->hp_generator_clock);
    }
}

void draw_enemy_bar(objects *obj)
{
    sfVector2f pos = sfSprite_getPosition(obj->enemy->sprite);
    sfVector2f scale = {0, 0.125f};

    if (obj->enemy->hp > 0)
        scale.x = ((float) obj->enemy->hp / 50) / 5;
    pos.y += 45;
    pos.x -= (float) obj->enemy->hp / 2;
    sfSprite_setScale(obj->enemy->life_sprite, scale);
    sfSprite_setPosition(obj->enemy->life_sprite, pos);
    sfRenderWindow_drawSprite(obj->window, obj->enemy->life_sprite, NULL);
}

void enemy_controller(objects *obj)
{
    enemy_t *og = obj->enemy;
    if (og == NULL)
        return;
    else {
        for (; obj->enemy != NULL; obj->enemy = obj->enemy->next) {
            sfRenderWindow_drawSprite(obj->window, obj->enemy->sprite, NULL);
            draw_enemy_bar(obj);
            animate_enemy(obj->enemy);
            move_enemy(obj->enemy, sfSprite_getPosition(obj->player->sprite),
                obj);
            hit_player(obj);
        }
        obj->enemy = og;
    }
}