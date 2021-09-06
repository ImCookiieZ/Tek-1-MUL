/*
** EPITECH PROJECT, 2020
** MAIN
** File description:
** MAIN
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include ".collision.c"

// --- Some define

#define C_SPEED 2 // HERE you can change the character speed.
#define C_HALF_SIZE 8 // Here the half of an 16*16 tile.
#define MAP_PATH "test_map.png" // HERE replace the actual PATH by your new map
#define MAP_PATH2 "foregound.png"
// PATH
#define C_PATH "character.png" // HERE replace the actual PATH by your new character PATH

// --- Enumaration for the differents movement direction

typedef enum E_DIRECTION {
    UP,
    DOWN,
    RIGHT,
    LEFT
} E_DIRECTION;

// --- Program

int isCollision(E_DIRECTION direction, sfVector2f pos)
{

    // --- Here a simple calculation to know where you are in your const int **array :
    // --> ((Sprite Position -/+ Your speed) + The half size of your character) / size of a tile.

    switch (direction) {
        case UP:
            if (collision[(int)(((pos.y - C_SPEED) + C_HALF_SIZE) / 16)][
                (int)(pos.x + C_HALF_SIZE) / 16] != 0)
                return 1;
            break;
        case DOWN:
            if (collision[(int)(((pos.y + C_SPEED) + C_HALF_SIZE) / 16)][
                (int)(pos.x + C_HALF_SIZE) / 16] != 0)
                return 1;
            break;
        case RIGHT:
            if (collision[(int)(pos.y + C_HALF_SIZE) / 16][(int)(((pos.x +
            C_SPEED) + C_HALF_SIZE) / 16)] != 0)
                return 1;
            break;
        case LEFT:
            if (collision[(int)(pos.y + C_HALF_SIZE) / 16][(int)(((pos.x -
            C_SPEED) + C_HALF_SIZE) / 16)] != 0)
                return 1;
            break;
        default: return 0; break;
    }
    return 0;
}

void character_interaction(sfSprite *sprite, sfVector2f *pos)
{
    // --- Here we check if the player can move.

    if (sfKeyboard_isKeyPressed(sfKeyUp) && isCollision(UP, *pos) == 0)
        pos->y -= C_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && isCollision(DOWN, *pos) == 0)
        pos->y += C_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && isCollision(RIGHT, *pos) == 0)
        pos->x += C_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && isCollision(LEFT, *pos) == 0)
        pos->x -= C_SPEED;
    sfSprite_setPosition(sprite, *pos);
}


int main(void)
{

    // --- Set window

    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;

    video_mode.width = 800;
    video_mode.height = 800;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Tiled tutorial", sfDefaultStyle , NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    // --- Set map

    sfTexture *texture_map;
    sfSprite *sprite_map;
    texture_map = sfTexture_createFromFile(MAP_PATH, NULL);
    sprite_map = sfSprite_create();
    sfTexture *texture_map2;
    sfSprite *sprite_map2;
    texture_map2 = sfTexture_createFromFile(MAP_PATH2, NULL);
    sprite_map2 = sfSprite_create();
    sfSprite_setTexture(sprite_map, texture_map, sfTrue);
    sfSprite_setTexture(sprite_map2, texture_map2, sfTrue);
    sfSprite_setPosition(sprite_map, (sfVector2f){0 ,0});
    
    // Set character

    sfTexture *texture_char;
    sfSprite *sprite_char;
    sfVector2f char_pos = {150, 150};
    texture_char = sfTexture_createFromFile(C_PATH, NULL);
    sprite_char = sfSprite_create();
    sfSprite_setTexture(sprite_char, texture_char, sfTrue);
    sfSprite_setPosition(sprite_char, char_pos);

    // --- main loop

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            // --- Escape is going to stop the game.
            if (event.key.code == sfKeyEscape) {
                free(texture_map);
                free(sprite_map);
                free(texture_char);
                free(sprite_char);
                free(window);
                return 0;
            }
        }
        character_interaction(sprite_char, &char_pos);
        sfRenderWindow_drawSprite(window, sprite_map, NULL);
        sfRenderWindow_drawSprite(window, sprite_char, NULL);
        sfRenderWindow_drawSprite(window, sprite_map2, NULL);
        sfRenderWindow_display(window);
    }

    free(texture_map);
    free(sprite_map);
    free(texture_char);
    free(sprite_char);
    free(window);
    return 0;
}