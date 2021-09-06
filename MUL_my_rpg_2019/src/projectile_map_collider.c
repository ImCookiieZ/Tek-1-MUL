/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int check_reachable(sfVector2f pos, sfVector2f move, sfVector2f scale,
    sfVector2f offset)
{
    if ((int) ((pos.y + move.y + offset.y * scale.y) / 4.3 /
    16) < 0 || (int) ((pos.y + move.y + offset.y * scale.y)
    / 4.3 / 16) > 14 || (int) ((pos.x) / 4.3 / 16) < 0 || (int) ((pos.x) /
    4.3 / 16) > 28)
        return (0);
    return (1);
}

void link_collision(objects *obj, float offset_x, float offset_y)
{
    sfVector2f p = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f s = obj->projectile->scale;
    sfVector2f m = obj->projectile->move;
    sfVector2f o = {offset_x, offset_y};
    if (!check_reachable(p, m, s, o)) return;
    if (obj->map_link[obj->map_y][obj->map_x][(int) ((p.y + m.y) / 4.3 /
    16)][(int) ((p.x + m.x + o.x * s.x) / 4.3 / 16)] != 0)
        obj->projectile->hit = 1;
    if (obj->map_link[obj->map_y][obj->map_x][(int) ((p.y + m.y) / 4.3 /
    16)][(int) ((p.x + m.x - o.x * s.x) / 4.3 / 16)] != 0)
        obj->projectile->hit = 1;
    if (obj->map_link[obj->map_y][obj->map_x][(int) ((p.y + m.y) / 4.3 /
    16)][(int) ((p.x + m.x) / 4.3 / 16)] != 0) obj->projectile->hit = 1;
    if (obj->map_link[obj->map_y][obj->map_x][(int) ((p.y + m.y + o
    .y * s.y) / 4.3 / 16)][(int) ((p.x + m.x + o.x * s.x) /
    4.3 / 16)] != 0) obj->projectile->hit = 1;
    if (obj->map_link[obj->map_y][obj->map_x][(int) ((p.y + m.y + o
    .y * s.y) / 4.3 / 16)][(int) ((p.x + m.x - o.x * s.x) / 4.3 / 16)] != 0)
        obj->projectile->hit = 1;
    if (obj->map_link[obj->map_y][obj->map_x][(int) ((p.y + m.y + o.y * s.y) /
    4.3 / 16)][(int) ((p.x + m.x) / 4.3 / 16)] != 0) obj->projectile->hit = 1;
}

void collision_projectile(objects *obj, float offset_x, float offset_y)
{
    sfVector2f p = sfSprite_getPosition(obj->projectile->sprite);
    sfVector2f s = obj->projectile->scale;
    sfVector2f m = obj->projectile->move;
    sfVector2f o = {offset_x, offset_y};
    if (!check_reachable(p, m, s, o)) return;
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((p.y + m.y) / 4.3 /
    16)][(int) ((p.x + m.x + o.x * s.x) / 4.3 / 16)] != 0)
        obj->projectile->hit = 1;
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((p.y + m.y) / 4.3 /
    16)][(int) ((p.x + m.x - o.x * s.x) / 4.3 / 16)] != 0)
        obj->projectile->hit = 1;
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((p.y + m.y) / 4.3 /
    16)][(int) ((p.x + m.x) / 4.3 / 16)] != 0) obj->projectile->hit = 1;
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((p.y + m.y + o
    .y * s.y) / 4.3 / 16)][(int) ((p.x + m.x + o.x * s.x) /
    4.3 / 16)] != 0) obj->projectile->hit = 1;
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((p.y + m.y + o
    .y * s.y) / 4.3 / 16)][(int) ((p.x + m.x - o.x * s.x) /
    4.3 / 16)] != 0) obj->projectile->hit = 1;
    if (obj->map_col[obj->map_y][obj->map_x][(int) ((p.y + m.y + o.y * s.y) /
    4.3 / 16)][(int) ((p.x + m.x) / 4.3 / 16)] != 0) obj->projectile->hit = 1;
}