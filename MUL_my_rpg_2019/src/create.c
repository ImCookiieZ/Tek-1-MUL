/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "../include/all_includes.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode, "my_rpg", sfDefaultStyle,
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

objects get_objects(objects *object)
{
    (*object).foreground_sprite = NULL;
    (*object).map_sprite = NULL;
    (*object).foreground_texture = NULL;
    (*object).map_texture = NULL;
    (*object).window = create_window();
    (*object).clock = sfClock_create();
    (*object).gametime = sfTime_Zero;
    (*object).tmtime = sfTime_Zero;
    (*object).text = create_text();
    (*object).projectile = NULL;
    (*object).player = NULL;
    (*object).skill_index = 1;
    (*object).is_chatting = 0;
    (*object).chat_time = sfTime_Zero;
    (*object).continue_time = sfTime_Zero;
    (*object).map_y = 0;
    (*object).map_x = 0;
    (*object).enemy = NULL;
    (*object).play_hit = sfTime_Zero;
    (*object).beamcd = 0;
    return (*object);
}

objects init_effects(objects *object)
{
    (*object).effect.texture_1_back = sfTexture_createFromFile
        ("assets/inventory/transparent.png", NULL);
    (*object).effect.texture_2_back = sfTexture_createFromFile
        ("assets/inventory/transparent_white.png", NULL);
    (*object).effect.sprite_1_back =
        create_my_sprite((*object).effect.sprite_1_back,
            (*object).effect.texture_1_back);
    (*object).effect.sprite_2_back =
        create_my_sprite((*object).effect.sprite_2_back,
        (*object).effect.texture_2_back);
    (*object).effect.texture_1 = sfTexture_createFromFile
        ("karl/rain.png", NULL);
    (*object).effect.texture_2 = sfTexture_createFromFile
        ("karl/snow.png", NULL);
    (*object).effect.sprite_1 =
        create_my_sprite((*object).effect.sprite_1,
            (*object).effect.texture_1);
    (*object).effect.sprite_2 = create_my_sprite((*object).effect.sprite_2,
        (*object).effect.texture_2);
    return (*object);
}

objects build_game(void)
{
    sfVector2f scale = {5 , 5};
    objects object;
    object = get_objects(&object);
    object.change_skill = sfTime_Zero;
    object.max_skill = 3;
    get_cols(&object);
    object = init_effects(&object);
    sfSprite_setScale(object.effect.sprite_1, scale);
    sfSprite_setScale(object.effect.sprite_2, scale);
    object.effect.clocky = sfClock_create();
    object.effect.last = sfTime_Zero;
    init_stone(&object);
    return (object);
}

sfSprite *create_my_sprite(sfSprite *sprite, sfTexture *texture)
{
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}