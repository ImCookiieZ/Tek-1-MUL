/*
** EPITECH PROJECT, 2019
** Marcel Taubert - > player.c
** File description:
** head
*/

#include "../include/all_includes.h"
extern const double p_c_s[3][3][2][3];
// Some define

#define C_SPEED 10 // HERE you can change the character speed.
#define C_HALF_SIZE 8 // Here the half of an 16*16 tile.

int mult_effective(int type1, int type2)
{
    if (type1 == type2)
        return (2);
    if (type1 == ((type2 == 1 ? 4 : type2) - 1))
        return (3);
    else
        return (1);
}

void change_sprites_evolution(objects *obj, int tmp, int tmp_2)
{
    sfVector2f move = {0, 0};

    obj->player->move_vec = move;
    if (obj->player->level == tmp)
        obj->player->level = tmp_2;
    else
        obj->player->level = tmp;
    sfRenderWindow_clear(obj->window, sfBlack);
    change_player(obj);
    sfRenderWindow_drawSprite(obj->window, obj->map_sprite, NULL);
    draw_player(obj);
    sfRenderWindow_drawSprite(
        obj->window, obj->foreground_sprite, NULL);
    sfRenderWindow_display(obj->window);
}

void evolution(objects *obj)
{
    int tmp = obj->player->level;
    int tmp_2 = tmp + 1;
    sfClock *clocky = sfClock_create();
    sfTime timer = sfClock_getElapsedTime(clocky);
    sfTime tmp_time = sfTime_Zero;
    int z = 40;
    sfSound_play(obj->sounds[2]);
    if (tmp_2 == 3) tmp_2 = 0;
    for (int i = 53; i > 0; timer = sfClock_getElapsedTime(clocky)) {
        if (timer.microseconds > tmp_time.microseconds) {
            change_sprites_evolution(obj, tmp, tmp_2);
            if (z == 0 || i % z == 0) {
                sfRenderWindow_clear(obj->window, sfWhite);
                z /= 2;
            }
            sfRenderWindow_display(obj->window);
            i--;
            tmp_time.microseconds += 50000;
        }
    }
}

void set_player_stats(objects *obj)
{
    obj->player->xp -= obj->player->xp_level * 25;
    obj->player->xp_level++;
    obj->player->max_hp = 100 + (obj->player->level * 50) + \
    (obj->player->xp_level * 5);
    obj->player->damage += 0.5f;
}

void draw_player(objects *obj)
{
    float scale_int = 2.2;
    sfVector2f scale = {scale_int, scale_int};
    float tmp = 0;
    if (obj->player->xp > obj->player->xp_level * 25)
        set_player_stats(obj);
    if (obj->player->move != -1) {
        if (is_collision(obj) == 1) {
            tmp = obj->player->move_vec.y;
            obj->player->move_vec.y = 0;
        }
        if (is_collision(obj) == 1) {
            obj->player->move_vec.y = tmp;
            obj->player->move_vec.x = 0;
        }
        if (is_collision(obj) == 1) obj->player->move_vec.y = 0;
        sfSprite_move(obj->player->sprite, obj->player->move_vec);
        sfSprite_setScale(obj->player->sprite, scale);
        sfRenderWindow_drawSprite(obj->window, obj->player->sprite, NULL);
    }
}