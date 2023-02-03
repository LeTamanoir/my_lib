##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_str
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_str.c				\
		./join.c				\
		./adders.c				\
		./content_check.c		\
		./convert.c				\
		./compare.c				\
		./checks.c				\
		./trim.c				\
		./print.c				\
		./str_temp.c			\
		./modifiers.c			\
		./format.c				\
		./misc.c				\
		./getters.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -I$(INCLUDE_DIR)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar cq $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	../../../clean.sh

fclean:	clean

re:	fclean all

.PHONY: all clean fclean re
