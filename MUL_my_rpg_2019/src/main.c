/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

int display_help(int ac, char **av)
{
    char buffer[75];
    int fd = 0;
    int size = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        fd = open("help", O_RDONLY);
        if (fd == -1)
            return (2);
        size = read(fd, buffer, 500);
        if (size == -1)
            return (2);
        buffer[size] = '\0';
        write(1, buffer, size);
        return (1);
    }
    else if (ac != 1) {
        write(1, "Retry with -h\n", 14);
        return (2);
    }
    return (0);
}

void destroy_all(objects *object)
{
    settings_destroy(object);
    hud_destroy(object);
    destroy_music(object);
    destroy_sound(object);
    if (object->stone_destroyed == 0)
        destroy_stone_stuff(object);
}

int main(int ac, char ** av)
{
    srand(random_seed());
    objects object = build_game();
    object.is_hud_set = 0;
    create_music(&object);
    player_t *player = NULL;
    player = malloc(sizeof(player_t));
    if (!player) return 84;
    object.player = player;
    object.map_type = MAIN_MUSIC;
    if (init_hud(&object) == -1) return 84;
    if (init_settings(&object) == -1)
        return 84;
    int help = display_help(ac, av);
    if (help == 0)
        main_menu(&object);
    else if (help == 2)
        return (84);
    destroy_all(&object);
    return (0);
}
