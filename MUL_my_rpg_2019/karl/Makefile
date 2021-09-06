##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

NAME	= Tiled_tutorial

CC	= gcc

RM	= rm -f

SRCS	= main.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include_rpg/
CFLAGS += -Wall -Wextra -lm -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
