/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main.c
*/

#include "../include/all_includes.h"

void my_change_rect(params_t *para)
{
    if (para->now.microseconds / 50000 > para->prev.microseconds / 50000) {
        if (para->run.left > 500) {
            para->run.left = 280;
        }
        else {
            para->run.left += 40;
        }
    }
}

int get_ground(params_t *para, char **map)
{
    int y_coordinate = (int) (para->player_pos.y - 7) / 63;
    int x_coordinate = (int) (para->player_pos.x + para->now.microseconds /
        3500) / 63;

    if (y_coordinate < 18) {
        for (int i = y_coordinate + 1; map[i] && map[i][x_coordinate]; i++)
            if (map[i][x_coordinate] == '#')
                return (i);
    }
    return (84);
}

void draw_fin(sfVector2f pos, params_t *para)
{
    pos.y = 0;
    for (; pos.y <= 1920; pos.y += 280)
        draw_sprite(para->spriteGold, para, para->gold, pos);
}

void disp_help(void)
{
    my_printf("./my_runner [path_map] ? [-h]\n");
    my_printf("\tmap usage:\n\t\tOne time 'B' for the beginning.\n");
    my_printf("\t\tX times '#' for the blocks.\n");
    my_printf("\t\tX times 'F' for the end.\n");
    my_printf("\t\tX time '+' for the enemys.\n");
    my_printf("\t-h:\n\t\tshows this option menu.\n");
}

int main(int argc, char **argv)
{
    int ret = 0;
    char *my_error_out = "sorry bro, need execty one map or the -h option\n";

    if (argc != 2) {
        for (int i = 0; my_error_out[i]; i++)
            write(2, &my_error_out[i], 1);
        return (84);
    }
    if (my_strcmp(argv[1], "-h") == 0)
        disp_help();
    else {
        ret = my_open(argv[1]);
    }
    if (ret == 84)
        return (ret);
    return (0);
}