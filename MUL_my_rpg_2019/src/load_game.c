/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_game.c
*/

#include "../include/all_includes.h"

int get_more(objects *obj, FILE *ptr)
{
    size_t buf;
    char *line = NULL;
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->settings->up = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->settings->down = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->dir = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->gender = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->boss.is_active = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->xp_level = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->damage = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->map_type = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->level = my_getnbr(line);
    return (1);
}

int get_even_more(objects *obj, FILE *ptr)
{
    size_t buf;
    char *line = NULL;
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->stone_destroyed = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (1);
    obj->player->choice = my_getnbr(line);
    init_player(obj, obj->player->choice);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->map_x = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->map_y = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->hp = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->xp = my_getnbr(line);
    return (2);
}

void load_game(objects *obj, FILE *ptr, char *line)
{
    init_hud_player_image(obj, obj->player->choice);
    free(line);
    fclose(ptr);
    init_maps(obj, 1);
    change_map(obj, 0, 0, 1);
    init_hud_frame(obj);
    init_cooldown_box(obj);
    if (obj->stone_destroyed == 0 && obj->map_y == 1 && obj->map_x == 3)
        init_stone(obj);
    play_music(obj, obj->map_type);
}

int load_or_new(objects *obj, FILE *ptr)
{
    sfVector2f pos;
    size_t buf;
    char *line = NULL;
    obj->boss = init_boss(obj);
    if (getline(&line, &buf, ptr) == -1) return (0);
    pos.x = (float) my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    pos.y = (float) my_getnbr(line);
    sfSprite_setPosition(obj->player->sprite, pos);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->item_is_found = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->settings->right = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->settings->left = my_getnbr(line);
    if (getline(&line, &buf, ptr) == -1) return (0);
    obj->player->max_hp = my_getnbr(line);
    if (get_more(obj, ptr) == 0) return (0);
    load_game(obj, ptr, line);
    return (gameloop(obj));
}

int get_game(objects *obj)
{
    pop_all_enemys(obj);
    FILE *ptr = fopen(SAVE_FILE, "r");
    int ret = 0;
    if (ptr == NULL) {
        if ((ret = choose_player(obj)) == 23)
            return (23);
        return (ret);
    }
    ret = get_even_more(obj, ptr);
    if (ret != 2)
        return (ret);
    ret = load_or_new(obj, ptr);
    if (ret == 1) {
        if (choose_player(obj) == 23)
            return (23);
    }
    return (ret);
}