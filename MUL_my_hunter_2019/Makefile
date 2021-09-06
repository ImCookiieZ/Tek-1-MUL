##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC	    =	src/main.c \
		src/main2.c \
		src/no_sfml.c \
		src/birds_movement.c \
		src/additional_functions.c \
		src/start_manu.c \
		src/end_manu.c \
		src/option_menu.c \
		src/my_getnbr.c \
		src/hightscore.c

OBJ	    =	$(SRC:.c=.o)

NAME	    =	my_hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g3 -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME) $(MAIN) $(TEST)

re:	fclean all

.PHONY: all clean fclean re
