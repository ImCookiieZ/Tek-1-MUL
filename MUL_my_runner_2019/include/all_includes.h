/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** add_all_includes
*/

#include "my.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>
#include <string.h>
#include "params_struct.h"

void draw_fin(sfVector2f pos, params_t *para);
int get_ground(params_t *para, char **map);
void my_change_rect(params_t *para);
sfMusic *music_player(char *path);
int get_end(params_t *para);
void my_cases(char c, params_t *para, sfVector2f pos);
int get_menu3(void);
void draw_score(params_t *params);
void draw_player_jump(params_t *para, int ground);
void draw_player(params_t *para, char **map);
void draw_game(params_t *para, char **map);
void draw_map(char **map, params_t *para);
void draw_sprite(sfSprite *sprite, params_t *para, sfTexture
*texture, sfVector2f position);
params_t create_everything();
int my_open(char *file);
int my_error_checker(char const *buffer);
int get_menu(void);
int run_function(char **map);