/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

const char denied[1][200] = {
    "There is nothing to see in this area for you.\nTry to talk to my "
    "brothers to become stronger!"
};

void set_npc_sprites(sfSprite *npc1, sfSprite *npc2, sfSprite *npc3)
{
    sfVector2f scale = {2, 2};
    sfVector2f origin = {18, 17};
    sfVector2f pos1 = {135, 310};
    sfVector2f pos3 = {1350, 90};
    sfVector2f pos2 = {1750, 620};
    sfSprite_setPosition(npc1, pos1);
    sfSprite_setPosition(npc2, pos2);
    sfSprite_setPosition(npc3, pos3);
    sfSprite_setScale(npc1, scale);
    sfSprite_setScale(npc2, scale);
    sfSprite_setScale(npc3, scale);
    sfSprite_setOrigin(npc1, origin);
    sfSprite_setOrigin(npc2, origin);
    sfSprite_setOrigin(npc3, origin);
}

void npc_draw(sfRenderWindow *window, sfSprite *npc1,
    sfSprite *npc2, sfSprite *npc3)
{
    set_npc_sprites(npc1, npc2, npc3);
    sfRenderWindow_drawSprite(window, npc1, NULL);
    sfRenderWindow_drawSprite(window, npc2, NULL);
    sfRenderWindow_drawSprite(window, npc3, NULL);
    sfSprite_destroy(npc1);
    sfSprite_destroy(npc2);
    sfSprite_destroy(npc3);
}

void draw_npc(sfRenderWindow *window, int x, int y)
{
    if (x == 3 && y == 1) {
        sfSprite *npc1 = sfSprite_create();
        sfSprite *npc2 = sfSprite_create();
        sfSprite *npc3 = sfSprite_create();
        sfTexture *npc1_t = sfTexture_createFromFile(
            "assets/NPC_fire.png", NULL);
        sfTexture *npc3_t = sfTexture_createFromFile("assets/NPC_water.png",
            NULL);
        sfTexture *npc2_t = sfTexture_createFromFile("assets/NPC_forest.png",
            NULL);
        npc1 = create_my_sprite(npc1, npc1_t);
        npc2 = create_my_sprite(npc2, npc2_t);
        npc3 = create_my_sprite(npc3, npc3_t);
        npc_draw(window, npc1, npc2, npc3);
        sfTexture_destroy(npc1_t);
        sfTexture_destroy(npc2_t);
        sfTexture_destroy(npc3_t);
    }
}

int npc_trigger(sfVector2f player, sfVector2f npc1, sfVector2f npc2,
    sfVector2f npc3)
{
    if (player.x > npc1.x - 200 && player.x < npc1.x + 200 && player.y > npc1
    .y - 200 && player.y < npc1.y + 200)
        return (1);
    if (player.x > npc2.x - 200 && player.x < npc2.x + 200 && player.y > npc2
    .y - 200 && player.y < npc2.y + 200)
        return (2);
    if (player.x > npc3.x - 200 && player.x < npc3.x + 200 && player.y > npc3
    .y - 200 && player.y < npc3.y + 200)
        return (3);
    return (-1);
}

int choose_text(objects *obj)
{
    sfVector2f pos1 = {135, 310};
    sfVector2f pos3 = {1350, 90};
    sfVector2f pos2 = {1750, 620};
    int trigger = npc_trigger(sfSprite_getPosition(obj->player->sprite),
        pos1, pos2, pos3);
    int ret = 0;
    trigger_evo(obj);
    ret = set_quest_text(obj, trigger);
    if (ret != 84)
        return (ret);
    return (set_chat_text(obj, denied, 1, trigger));
}