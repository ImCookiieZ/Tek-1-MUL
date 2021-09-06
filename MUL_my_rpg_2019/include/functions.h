/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/


#ifndef MUL_MY_RPG_2019_FUNCTIONS_H
#define MUL_MY_RPG_2019_FUNCTIONS_H

#include <dirent.h>

//item_collidor_next.c
void glumanda_items_next(objects *object, sfVector2f player_pos);
void bisasam_items_next(objects *object, sfVector2f player_pos);
void shiggy_items_next(objects *object, sfVector2f player_pos);

//settings_next.c
int settings_from_pause(objects *object);

//win_screen.c
int win_menu(objects *obj);

//destroy.c
void destroy_projectile(projectile_t *node);
void destroy_enemy(enemy_t *node);
void destroy_music(objects *object);
void destroy_sound(objects *object);
void destroy_stone_stuff(objects *object);

//enemy_spawn.c
void pop_all_enemys(objects *obj);
sfVector2f get_random_pos(objects *obj);
void spawn_enemys(objects *obj);

//settings_music_sound.c
void set_music_string(objects *object);
void check_music(objects *object);
void set_sound_string(objects *object);
void check_sound(objects *object);

//event.c
int check_button(objects *object, double const buttons[][4], int len);
int menu_button(objects *object, const double buttons[][4], int len);

//settings_init.c
void init_grey(objects *objects);
void init_red(objects *objects);
void init_black(objects *objects);
int init_settings(objects *objects);

//projectile_types.c
projectile_t *init_projectile_values(projectile_t *new);
projectile_t *init_wave_values(projectile_t *new);
projectile_t *init_beam_values(projectile_t *new);

//projectile_controller.c
void projectile_controller(objects *obj);
void wave_controller(objects *obj);
void beam_controller(objects *obj);
void skill_controller(objects *obj);

//projectile_init.c
float set_rot(sfVector2f move);
sfVector2f set_move(const int *dirs, sfSprite *sprite);
projectile_t *add_projectile(objects *obj, int *dirs);
void pop_projectile(objects *obj);

//projectile_map_collider.c
void collision_projectile(objects *obj, float offset_x, float offset_y);
void link_collision(objects *obj, float offset_x, float offset_y);

//projectile.c
void check_new_projectile(objects *obj);
void change_skill(objects *obj);
float get_cooldown(int skill, float beam);

//hud.c
void change_xp(objects *obj);
sfIntRect hud_player_img(objects *obj);
sfIntRect hud_icons_img(objects *obj);
void draw_cooldown(objects *obj, float diff);
void change_healthbar(objects *obj);

//load_game.c
int get_more(objects *obj, FILE *ptr);
int get_even_more(objects *obj, FILE *ptr);
void load_game(objects *obj, FILE *ptr, char *line);
int get_game(objects *obj);

//gameloop.c
int check_event(objects *obj);
int gameloop(objects *obj);

//text.c
ui_text create_text(void);
void animate_button(sfRenderWindow *window, sfEvent event, sfVector2f scale,
    sfVector2f pos);
void set_text(objects *object, double const values[], const char *str, int
isButton);
void destroy_texts(objects *object);

//draw.c
int switch_for_effect(objects *obj, int effect);
void draw_effect(objects *obj);
void controll_draw(objects *obj);
void draw(objects *obj);

//intro_move.c
void set_intro_text(objects *object, intro_t *tmp, sfText *text);
sfText *create_intro_text(void);
int set_all_intro(objects *obj, intro_t *tmp, sfText *text, sfSprite *bg);
intro_t *move_y(intro_t *tmp, intro_t *head, sfClock *clocky);
intro_t *move_x(intro_t *tmp, intro_t *head, sfClock *clock);

//music.c
void check_which_music(objects *object);
void play_music(objects *object, int x);
void init_music_names(objects *object);
void init_soundbuffer(objects *object);
void create_music(objects *object);

//intro_get_input.c
intro_t *set_node(intro_t *tmp, const char *line, size_t len, int i);
intro_t *intro_connect_node(intro_t *intro, intro_t *tmp, intro_t *ptr);
intro_t *get_input(intro_t *intro, int choice);

//enemy_textures.c
sfTexture *get_water_tex(void);
sfTexture *get_plats_tex(void);
sfTexture *get_fire_tex(void);
sfTexture *get_texture(int type);

//settings_destroy.c
void settings_destroy(objects *obj);

//enemy_init.c
int get_type(int x, int y);
void set_variables_enemy(const objects *obj, enemy_t *new);
enemy_t *init_enemy(objects *obj, sfVector2f pos);
enemy_t *add_enemy(objects *obj);
void pop_enemy(objects *obj);

//init_items.c
int init_water_items(objects *object);
int init_fire_items(objects *object);
int init_gras_items(objects *object);
void destroy_items(objects *object);

//settings_init_strings.c
int init_string_music_sound(objects *obj);
int init_string_two(objects *objects);
int init_strings(objects *objects);

//projectile.c
int *get_dir(void);
void set_player_dir(player_t *player, const int *dirs);
void check_new_projectile(objects *obj);
void change_skill(objects *obj);

//init_inv.c
int init_inv(objects *object);
void init_inventory_frame(objects *object);
void init_quest_items(objects *object);
void quest_items_rect(objects *object);
void init_inv_pokemon(objects *object);
void pokemon_rect(objects *object);

//get_player_funcs.c
int *get_player_dir(objects *object);
sfVector2f get_player_move(int *dirs);
int get_player_anim(sfVector2f move, int cur_dir);
void my_cheats(objects *obj);
void get_player_direction(objects *obj);

//do_libs.c
int pre_loop(char const *str, int i);
int my_getnbr(char const *str);
int my_put_nbr_f(FILE* ptr, int nb);

//projectile_collider.c
void hit_projectile(objects *obj);
void hit_wave(objects *obj);
void hit_beam(objects *obj, float x, float y);

//add_to_menus.c
void set_main_menu_texts(objects *object);
void set_pause_menu_text(objects *object);
void set_choose_player_text(objects *object);
int choose_player(objects *object);

//settings_num_to_string.c
int digits_of_num(int n);
char *my_itoa(int num);

//init_change_map.c
void add_names_to_maps(const objects *obj);
void create_for_scole(objects *obj, objects *obj2, char *fore, char *map);
void create_scroller(const objects *obj2, const objects *obj, sfVector2f *mover,
    sfVector2f *mover2);

//my_strdup.c
char *my_strdup(char *src);

//hud_init.c
void init_hud_xp_bar(objects *obj);
void init_hud_frame(objects *obj);
void init_hud_player_image(objects *obj, int choice);
void init_hud_icons(objects *obj);
int init_hud(objects *obj);

//settings_fps.c
void set_fps_string(objects *object);
void check_fps(objects *object);
int init_fps_string(objects *object);

//item_collidor.c
void glumanda_items(objects *object);
void bisasam_items(objects *object);
void shiggy_items(objects *object);
int show_items(objects *object, int choice);

//boss_fight.c
void boss_move(sfVector2f target, boss_t *boss);
void boss_teleport(boss_t *boss);
void boss_controller(objects *obj);

//display_inventory.c
void display_inv_all(objects *object);
char *display_power_level(objects *object);
char *display_exp_level(objects *object);

//stone.c
void destroy_stone(objects *obj);
void hit_stone(objects *obj, float offset_x, float offset_y);
void init_stone(objects *object);

//boss_collider.c
void hit_boss_projectile(objects *obj);
void hit_boss_player(objects *obj);

//check_collisions.c
int first_three_cols(objects *obj, float x, float y, double x_box);
int second_three_cols(objects *obj, float y, double x_box, double y_box);
int is_collision(objects *obj);

//game_over.c
void set_game_over_text(objects *obj);
int game_over_menu(objects *obj);

//init_boss.c
int destroy_boss(objects *obj);
boss_t init_boss_variables(boss_t *new, objects *obj);
boss_t init_boss(objects *obj);

//choice_animation.c
void anim_sprites(sfSprite *b, sfSprite *c, sfSprite *s, sfRenderWindow *window);
void draw_choice_sprites(sfRenderWindow *window);

//player.c
int mult_effective(int type1, int type2);
void change_sprites_evolution(objects *obj, int tmp, int tmp_2);
void evolution(objects *obj);
float get_seconds(sfTime time);
void draw_player(objects *obj);

//save_game.c
void save_more(const objects *obj, FILE *ptr);
int save_game(objects *obj);

//menus.c
int pause_menu(objects *object);
void how_to_play(objects *object);
void main_menu(objects *object);

//new_word_array.c
int my_strlen(char const *src);
int is_alnum2(char const character, char const *seperator);
int counts_words2(char const *str, char *seperator);
int counts_character2(char const *str, int toto, char *seperator);
char **my_str_to_word_array2(char const *str, char *seperator);

//intro.c
void intro_destroy(sfClock *clock, sfClock *clocky);
void show(objects *obj, intro_t *intro, sfSprite *bg);
int choose_language(objects *object, sfSprite *bg);
void intro(objects *obj);

//chat_box.c
int my_arraylen(char **array);
void draw_box(sfRenderWindow *window);
int set_chat_text(objects *obj, const char npc_text[][200], int len, int npc);
void is_chatting(objects *obj);

//init_collisions.c
void get_string_cols(FILE *file, int ***const *col, int x, int y);
int ****get_for_one_map(FILE *file, int ****col);
int ****loop_collisions(int ****col, struct dirent *file_dir, FILE *file,
    DIR *directory);
int get_cols(objects *obj);

//create.c
sfRenderWindow *create_window(void);
objects get_objects(objects *object);
objects init_effects(objects *object);
objects build_game(void);
sfSprite *create_my_sprite(sfSprite *sprite, sfTexture *texture);

//gender.c
int change_gender_buttons(objects *object);
void draw_gender(objects *object);
int choose_gender(objects *object, int which);

//random.c
int random_seed(void);

//projectile_init.c
float set_rot(sfVector2f move);
sfVector2f set_move(const int *dirs, sfSprite *sprite);
projectile_t *init_projectile(objects *obj, int *dirs);
projectile_t *add_projectile(objects *obj, int *dirs);
void pop_projectile(objects *obj);

//change_map.c
void move_map(objects *obj2, objects *obj, float x, float y);
void change_player_for_fcol(const objects *obj, int y);
void load_enemy_next_map(objects *obj, int x, int y);
int change_map(objects *obj, int x, int y, int first);
int init_maps(objects *obj, int load);

//init_player.c
void init_player(objects *obj, int choice);

//lib_func.c
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *mal_cat(char *src1, char *src2);
void my_putchar_f(FILE* ptr, char c);

//hud_destroy.c
void hud_destroy(objects *obj);

//enemy_move.c
float my_abs(float i);
int check_enemy_collision(sfVector2f pos, sfVector2f move, objects *obj);
sfVector2f check_move(sfVector2f pos, sfVector2f move, objects *obj);
sfVector2f round_move(sfVector2f move);
void move_enemy(enemy_t *enemy, sfVector2f target, objects *obj);

//gender_init.c
void set_up_sprites(objects *object);
void set_gender_sprite(int which, sfTexture **female_t, sfTexture **male_t);
void init_gender_sprites(objects *object, int which);
void init_gender(objects *object);

//npcs.c
void set_npc_sprites(sfSprite *npc1, sfSprite *npc2, sfSprite *npc3);
void npc_draw(sfRenderWindow *window, sfSprite *npc1,
    sfSprite *npc2, sfSprite *npc3);
void draw_npc(sfRenderWindow *window, int x, int y);
int npc_trigger(sfVector2f player, sfVector2f npc1, sfVector2f npc2,
    sfVector2f npc3);
int choose_text(objects *obj);

//npc_quest_text.c
int set_quest_text(objects *obj, int trigger);

//change.c
sfIntRect get_player_image(player_t *p);
void change_player(objects *obj);
int change_music_to_map(objects *obj, int x);
void do_the_change(objects *obj);

//settings.c
int is_sprite_hit(objects *obj, sfSprite *sprite, int width, int height);
void draw_background_settings(const objects *object);
void draw_settings(objects *object);
int settings(objects *object);

//settings_keymap.c
void draw_keymap(objects *object);
int get_key_two(objects *object, int choice, char c);
int get_key(objects *object, int choice);
void change_keymap(objects *object);
int keymap(objects *object);

//main.c
int display_help(int ac, char **av);
void destroy_all(objects *object);
int main(int ac, char ** av);

//hud_init_two.c
void set_cooldown_box(const objects *obj, sfVector2f *vec, sfVector2f *scale);
void init_cooldown_box(objects *obj);
void init_healthbar_two(objects *obj);
void init_healthbar(objects *obj);
int init_hud_strings(objects *obj);

//boss.c
void animate_boss(boss_t *boss);
void reset_boss(boss_t *boss);
void boss_bar(boss_t *boss, sfRenderWindow *window);
void reset_game(objects *obj);



//inventory.c
void disp_inv_texts(objects *object);
int inventory_menu(objects *object);
void inventory_destroy(objects *object);
char *disp_quest(objects *object);

//trigger_evolution.c
void trigger_glumanda_evo(objects *obj);
void trigger_bisasam_evo(objects *obj);
void trigger_shiggy_evo(objects *obj);
void trigger_evo(objects *obj);

//check_link.c
int check_top_right(objects *obj);
int check_top_left(objects *obj);
int check_right_down(objects *obj);
int check_left_down(objects *obj);
int ismy_link(objects *obj);

//enemy_controller.c
void animate_enemy(enemy_t *enemy);
void hit_player(objects *obj);
void draw_enemy_bar(objects *obj);
void enemy_controller(objects *obj);

//init_links.c
int get_links(objects *obj);
#endif //MUL_MY_RPG_2019_FUNCTIONS_H