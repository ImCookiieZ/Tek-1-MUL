/*
** EPITECH PROJECT, 2019
** hud.c
** File description:
** lkj6
*/

#include "../include/all_includes.h"

const double hud_text[3][4] = {
        {210, 62, 20, 20},
        {260, 62, 20, 20},
        {225, 21, 34, 34}
};

const float cooldown_hud[3] = {0.5f, 1.0f, 0.01f};

void change_xp(objects *obj)
{
    sfVector2f scale = {1, 1};
    scale.x = (float)obj->player->xp / (25 * (obj->player->xp_level));

    sfSprite_setScale(obj->hud->xp_blue, scale);
    sfRenderWindow_drawSprite(obj->window, obj->hud->xp_blue, NULL);
}

sfIntRect hud_player_img(objects *obj)
{
    sfIntRect arr[1] = {
            {60 * obj->player->level, 60 * obj->hud->layer, 60, 60}
    };
    return arr[0];
}

sfIntRect hud_icons_img(objects *obj)
{
    sfIntRect arr[1] = {
            {186 * obj->player->level, 60 * obj->hud->layer, 186, 60}
    };
    return arr[0];
}

void draw_cooldown(objects *obj, float diff)
{
    if (obj->skill_index == 1)
        if (diff < cooldown_hud[0]) {
            sfRenderWindow_drawSprite(obj->window, obj->hud->cd_one, NULL);
        }
    if (obj->skill_index == 2)
        if (diff < cooldown_hud[1]) {
            sfRenderWindow_drawSprite(obj->window, obj->hud->cd_two, NULL);
        }
    if (obj->skill_index == 3)
        if (obj->beamcd > 0.13) {
            sfRenderWindow_drawSprite(obj->window, obj->hud->cd_three, NULL);
        }
}

void change_healthbar(objects *obj)
{
    sfVector2f scale = {1, 1};

    scale.x = (float)obj->player->hp / (float)obj->player->max_hp;
    float diff = sfTime_asSeconds(obj->gametime) - sfTime_asSeconds
            (obj->tmtime);
    sfSprite_setTextureRect(obj->hud->player, hud_player_img(obj));
    sfSprite_setTextureRect(obj->hud->icons, hud_icons_img(obj));
    sfRenderWindow_drawSprite(obj->window, obj->hud->xp_frame, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->hud->hb_black, NULL);
    sfSprite_setScale(obj->hud->hb_red, scale);
    sfRenderWindow_drawSprite(obj->window, obj->hud->hb_red, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->hud->hb_frame, NULL);
    set_text(obj, hud_text[0], obj->hud->level_string, 0);
    set_text(obj, hud_text[1], my_itoa(obj->player->xp_level), 0);
    change_xp(obj);
    sfRenderWindow_drawSprite(obj->window, obj->hud->player, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->hud->icons, NULL);
    draw_cooldown(obj, diff);
    set_text(obj, hud_text[2], "XP", 0);
}