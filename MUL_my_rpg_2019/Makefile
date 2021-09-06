##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC     =   src/text.c\
		src/create.c\
		src/random.c\
		src/music.c\
		src/music_next.c\
		src/main.c\
		src/event.c\
		src/stone.c\
		src/menus.c\
		src/player.c\
		src/gameloop.c\
		src/choice_animation.c\
		src/destroy.c\
		src/projectile.c\
		src/projectile_init.c\
		src/projectile_types.c\
		src/projectile_collider.c\
		src/projectile_controller.c\
		src/projectile_map_collider.c \
        src/settings.c\
        src/settings_next.c\
		src/settings_init.c\
		src/settings_keymap.c\
		src/settings_init_strings.c\
		src/settings_destroy.c\
		src/settings_num_to_string.c\
		src/settings_music_sound.c\
		src/settings_fps.c\
		src/hud.c\
		src/hud_init.c\
		src/hud_init_two.c\
		src/hud_destroy.c\
		src/chat_box.c\
		src/change_map.c\
		src/my_strdup.c\
		src/npcs.c\
		src/enemy_init.c\
		src/enemy_spawn.c\
		src/enemy_textures.c\
		src/enemy_controller.c\
		src/enemy_move.c\
		src/inventory.c	\
		src/init_inv.c \
		src/save_game.c \
		src/lib_func.c  \
		src/intro.c \
		src/intro_get_input.c \
		src/intro_move.c\
		src/game_over.c \
		src/gender.c \
		src/gender_init.c \
		src/init_collisions.c \
		src/boss.c \
		src/boss_collider.c \
		src/boss_fight.c \
		src/new_word_array.c\
		src/init_items.c\
		src/item_collidor.c \
		src/item_collidor_next.c\
		src/add_to_menus.c \
		src/change.c \
		src/check_collisions.c \
		src/check_link.c \
		src/display_inventory.c \
		src/do_libs.c \
		src/draw.c \
		src/get_player_funcs.c \
		src/init_boss.c \
		src/init_change_map.c \
		src/init_player.c \
		src/load_game.c \
		src/init_links.c \
		src/get_seconds.c \
		src/trigger_evolution.c\
		src/win_screen.c \
		src/npc_quest_text.c

CFLAGS  += -W -Wall -Wextra -Werror -g3 -pedantic

TESTS	=	$(SRC)

OBJ	=	$(SRC:.c=.o)

OBJ_TESTS =	$(TESTS:.c=.o)

NAME	=	my_rpg

RM	=	rm -f

VALGRIND    =   -g3

TEST_NAME =	unit_tests

all:		$(NAME)

$(NAME):	$(OBJ)
	python3 karl/jsons/test.py
	gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window \
	$(VALGRIND)
	./random.sh > seed

tests_run:	$(OBJ_TESTS)
	gcc -o $(TEST_NAME) $(OBJ_TESTS) -lcriterion --coverage
	./unit_tests

tclean:
	$(RM) $(OBJ_TESTS) $(TEST_NAME)

clean:
	$(RM) $(OBJ) seed my_save.txt

fclean: clean tclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
