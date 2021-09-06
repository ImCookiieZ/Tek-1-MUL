/*
** EPITECH PROJECT, 2019
** inventory.c
** File description:
** for my rpg 2019
*/

#include "../include/all_includes.h"
#include "../include/functions.h"
#include "../include/structs.h"

const double inventory_texts[14][4] = {
    {1230, 110, 130, 160},
    {1230, 260, 70, 450},
    {1235, 330, 70, 450},
    {950, 410, 70, 160},
    {950, 480, 50, 160},
    {1050, 480, 50, 0},
    {950, 530, 50, 345},
    {960, 135, 50, 160},
    {1590, 410, 70, 450},
    {950, 700, 70, 450},
    {950, 780, 50, 450},
    {1360, 330, 70, 450},
    {1110, 580, 50, 450},
    {950, 580, 50, 450}
};

char *disp_quest(objects *object)
{
    if (object->player->xp_level < 5)
        return ("You need to become stronger first.\nReach Level 5!");
    if (object->player->xp_level >= 5 && object->player->item_is_found == 0)
        return ("Find the hidden gem in the last\narea of your home element!");
    if (object->player->xp_level < 10 && object->player->item_is_found == 1)
        return ("You need to become even stronger!\nReach Level 10.");
    if (object->player->xp_level >= 10 && object->player->item_is_found == 1)
        return ("Find the hidden gem in the last\narea where you struggle the"
                " most!");
    if (object->player->item_is_found == 2)
        return ("Find the boss that hides behind the\nlarge rock in the main "
                "area!");
    else
        return NULL;
}

void disp_inv_texts(objects *object)
{
    set_text(object, inventory_texts[0], "INVENTORY", 0);
    set_text(object, inventory_texts[1], "EXP:", 0);
    set_text(object, inventory_texts[2], my_strcat(my_itoa
    (object->player->xp), "/"), 0);
    set_text(object, inventory_texts[3], "STATS", 0);
    set_text(object, inventory_texts[4], "DMG: ", 0);
    set_text(object, inventory_texts[5], my_itoa(object->player->damage), 0);
    set_text(object, inventory_texts[6], "SPD: 3", 0);
    set_text(object, inventory_texts[7], display_power_level(object), 0);
    set_text(object, inventory_texts[8], "ITEMS", 0);
    set_text(object, inventory_texts[9], "QUEST", 0);
    set_text(object, inventory_texts[10], disp_quest(object), 0);
    set_text(object, inventory_texts[11], display_exp_level(object), 0);
    set_text(object, inventory_texts[12], my_itoa(object->player->max_hp), 0);
    set_text(object, inventory_texts[13], "MAX HP:", 0);
}

int inventory_menu(objects *object)
{
    init_inv(object);
    while (sfRenderWindow_isOpen(object->window)) {
        while (sfRenderWindow_pollEvent(object->window, &object->event)) {
            if (object->event.type == sfEvtClosed) {
                sfRenderWindow_close(object->window);
            }
            if (object->event.key.code == sfKeyEscape) {
                sfSound_play(object->sounds[4]);
                return 0;
            }
        }
        display_inv_all(object);
    }
    inventory_destroy(object);
    return 0;
}

void inventory_destroy(objects *object)
{
    sfTexture_destroy(object->inventory->inv_tex);
    sfSprite_destroy(object->inventory->inv_sp);
    sfTexture_destroy(object->inventory->quest_items_t);
    sfSprite_destroy(object->inventory->quest_items);
    sfTexture_destroy(object->inventory->inv_frame_t);
    sfSprite_destroy(object->inventory->inv_frame);
    sfTexture_destroy(object->inventory->inv_poke_t);
    sfSprite_destroy(object->inventory->inv_poke);
}