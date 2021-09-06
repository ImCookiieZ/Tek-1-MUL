/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef MUL_MY_RPG_2019_STRUCTS_H
#define MUL_MY_RPG_2019_STRUCTS_H

typedef struct hud_s {
    sfSprite *hb_black;
    sfSprite *hb_red;
    sfSprite *hb_frame;
    sfTexture *hb_black_t;
    sfTexture *hb_red_t;
    sfTexture *hb_frame_t;
    char *level_string;
    char *xp_string;
    sfSprite *xp_frame;
    sfTexture *xp_frame_t;
    sfSprite *xp_blue;
    sfTexture *xp_blue_t;
    sfSprite *player;
    sfTexture *player_t;
    int layer;
    sfSprite *icons;
    sfTexture *icons_t;
    sfTexture *cooldown_box;
    sfSprite *cd_one;
    sfSprite *cd_two;
    sfSprite *cd_three;
} hud_t;

typedef struct effect_s {
    sfTexture *texture_1;
    sfTexture *texture_1_back;
    sfTexture *texture_2;
    sfTexture *texture_2_back;
    sfTexture *texture_3;
    sfSprite *sprite_1;
    sfSprite *sprite_1_back;
    sfSprite *sprite_2;
    sfSprite *sprite_2_back;
    sfSprite *sprite_3;
    sfClock *clocky;
    sfTime last;
} effect_t;

typedef struct enemy_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *life_texture;
    sfSprite *life_sprite;
    int type;
    float hp;
    int damage;
    int anim;
    sfClock *clock;
    sfClock *move_clock;
    sfTime last_hit;
    struct enemy_s *next;
} enemy_t;

typedef struct boss_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *life_texture;
    sfSprite *life_sprite;
    float hp;
    int anim;
    int damage;
    int is_active;
    sfClock *teleport;
    sfClock *move_clock;
    sfClock *animator;
    int is_destroyed;
} boss_t;

typedef struct intro_s {
    char *s;
    double size;
    double x;
    double y;
    struct intro_s *next;
} intro_t;

typedef struct player_s {
    int move; //cur moving index -> welche pos im movement array
    int dir; //direction 1 = up, 2 = right, 3 = down, 4 = left
    int level; //0 - 2
    int is_acting;
    int choice;
    sfVector2f move_vec;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    int index;
    int hp;
    int xp;
    float damage;
    int item_is_found;
    int gender;
    sfClock *hp_generator_clock;
    sfTime hp_creator_time;
    int xp_level;
    int max_hp;
    //0 = male(default) 1 = female
} player_t;

typedef struct settings_s {
    int music; //0-100 in %
    char *music_string;
    int sounds; //0-100 in %
    char *sound_string;
    int right;
    char *right_string;
    int left;
    char *left_string;
    int up;
    char *up_string;
    int down;
    char *down_string;
    int pause;
    int attack_one;
    int attack_two;
    int attack_three;
    int fps;
    char *fps_string;
    sfTexture *grey_bar_t;
    sfTexture *red_bar_t;
    sfTexture *black_bar_t;
    sfSprite *grey_bar_mus;
    sfSprite *red_bar_mus;
    sfSprite *black_bar_mus;
    sfSprite *grey_bar_sound;
    sfSprite *red_bar_sound;
    sfSprite *black_bar_sound;
    sfSprite *grey_bar_fps;
    sfSprite *red_bar_fps;
    sfSprite *black_bar_fps;
} settings_t;

typedef struct inventory_s
{
    sfTexture *inv_tex;
    sfSprite *inv_sp;
    sfSprite *inv_frame;
    sfTexture *inv_frame_t;
    sfSprite *quest_items;
    sfTexture *quest_items_t;
    sfSprite *inv_poke;
    sfTexture *inv_poke_t;

} inventory_t;

typedef struct item_s
{
    sfSprite *fire_item1;
    sfSprite *fire_item2;
    sfSprite *water_item1;
    sfSprite *water_item2;
    sfSprite *grass_item1;
    sfSprite *grass_item2;
    sfTexture *fire_item1_t;
    sfTexture *fire_item2_t;
    sfTexture *water_item1_t;
    sfTexture *water_item2_t;
    sfTexture *grass_item1_t;
    sfTexture *grass_item2_t;
} item_t;

typedef struct projectile_s
{
    int hit;
    int type;
    sfVector2f move;
    sfVector2f scale;
    sfSprite *sprite;
    sfClock *clock;
    sfClock *destroy;
    struct projectile_s *next;
} projectile_t;

typedef struct text_s
{
    sfFont *font;
    sfVector2f pos;
    sfText *text;
    int size;
} ui_text;

typedef struct tile_s
{
    sfVector2f pos;
    int type;
    int isCollider;
    sfSprite *sprite;
    sfTexture *texture;
} tile;

typedef struct gender_s {
    sfSprite *male;
    sfSprite *female;
    sfTexture *male_t;
    sfTexture *female_t;
    sfSprite *female_pokemon;
    sfTexture *female_pokemon_t;
    sfSprite *male_pokemon;
    sfTexture *male_pokemon_t;
} gender_t;

typedef struct objects_s
{
    sfRenderWindow *window;
    ui_text text;
    projectile_t *projectile;
    sfEvent event;
    sfClock *clock;
    sfTime gametime;
    sfTime tmtime;
    sfMusic **musics;
    sfSound **sounds;
    sfSoundBuffer **soundsbuf;
    player_t *player;
    enemy_t *enemy;
    sfSprite *map_sprite;
    sfSprite *foreground_sprite;
    sfTexture *map_texture;
    sfTexture *foreground_texture;
    settings_t *settings;
    inventory_t *inventory;
    item_t *items;
    hud_t *hud;
    int is_hud_set;
    int skill_index;
    int is_chatting;
    sfTime chat_time;
    sfTime continue_time;
    sfTime play_hit;
    sfTime change_skill;
    char ***map_names;
    int map_x;
    int map_y;
    int map_type;
    int max_skill;
    sfSprite *stone;
    int stone_destroyed;
    int hit_stone;
    sfClock *stone_clock;
    sfTexture *stone_t;
    int ****map_col;
    int ****map_link;
    boss_t boss;
    gender_t *gender;
    int play_game_over_music;
    effect_t effect;
    float beamcd;
    sfTime inventory_time;
    sfTime continue_time2;
} objects;

#endif //MUL_MY_RPG_2019_STRUCTS_H
