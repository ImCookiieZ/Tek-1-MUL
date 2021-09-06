/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** TODO: add description
*/

#include "../include/params_struct.h"
#include <SFML/Graphics.h>
#include "SFML/Audio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zconf.h>
#include <string.h>

#ifndef MUL_MY_HUNTER_2019_FUNCTIONS_H
#define MUL_MY_HUNTER_2019_FUNCTIONS_H
int my_getnbr(char const *);
int end_func(int ret, params para);
int draw_scores(params para);
params sub_hit(params para, int l);
params my_drawing(params para);
params hit_function(params para, sfTexture *);
params run_function(params para, sfTexture *);
params time_checker(params para);
params gameloop(sfClock *clock, params para);
params get_struct2(int level, params para);
params prepare_everything(params para);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *);
int my_putstr(char const *str);
int fall_down(sfRenderWindow *window, int ar[2], sfVector2f *pos_down,
    int const *r);
void print_h(void);
sfVector2f
my_printing(float const ar[3], sfVector2f pos, sfRenderWindow *window,
    sfTexture *birds[3][2]);
int count_digits(int nb);
int main(int ac, char **av);
params my_shoot2(params para);
params my_shoot(params para);
sfMusic *music_player(char *path);
int change_cursor(sfTexture *my_cursor, params para);
params key_checker(params para, sfMusic *music);
params get_struct(int);
int error_try(int ac, char **av);
params create_everything(params para);
int draw_manu(sfRenderWindow *window, sfText *start, sfText *my_exit, sfText
*my_duckhunt);
int prepare_manu(sfRenderWindow *window, sfFont *font);
int get_answer(sfRenderWindow *window, sfVector2i mouse_pos);
int get_menu(void);
int get_end(void);
int get_menu3(void);
#endif //MUL_MY_HUNTER_2019_FUNCTIONS_H