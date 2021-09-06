/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

const char first_quest[3][200] = {
    "So you are the new one here, right?\n\n"
    "Press Space to continue.",
    "If you want to survive in this world you should\nfirst defeat some enemies"
    " in this area over here.\n\n"
    "Press Space to continue.",
    "Especially for your element it should be easy."
};

const char second_quest[3][200] = {
    "Ah I see now you're strong enough to mess around\nwith the enemies of "
    "your element\n\n"
    "Press Space to continue.",
    "If you want to evolve you need to defeat the\nenemies in this region and "
    "find\nthe evolution gem!\n"
    "Press Space to continue.",
    "Come back when you found the stone and became\nstronger. I'll help "
    "you to evolve!\nJust talk to me again."
};

const char third_quest[3][200] = {
    "You're really strong right now!\n\n"
    "Press Space to continue.",
    "But not strong enough to defeat Mewtwo..\nIf you find the last evolution"
    " gem\nI can help you to evolve one last time.\n"
    "Press Space to continue.",
    "Just talk to your monkey when you found\nthe last evolution gem and "
    "became stronger."
};

const char boss_quest[2][200] = {
    "You are now strong enough to fight against\nMewtwo!\n\n"
    "Press Space to continue.",
    "Hit the large rock with your strongest attack\nto destroy it!"
};

int set_quest_text(objects *obj, int trigger)
{
    if (obj->player->xp_level < 5 && trigger != -1)
        if (mult_effective(obj->player->choice, trigger) == 3)
            return (set_chat_text(obj, first_quest, 3, trigger));
    if (obj->player->xp_level >= 5 && obj->player->item_is_found == 0)
        if (mult_effective(obj->player->choice, trigger) == 2)
            return (set_chat_text(obj, second_quest, 3, trigger));
    if (obj->player->xp_level < 10 && obj->player->item_is_found == 1)
        if (mult_effective(obj->player->choice, trigger) == 1)
            return (set_chat_text(obj, third_quest, 3, trigger));
    if (obj->player->level == 2 && obj->player->item_is_found == 2)
            return (set_chat_text(obj, boss_quest, 2, trigger));
    return (84);
}