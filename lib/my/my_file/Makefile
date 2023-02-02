##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_file
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_file.c 			\
		./getters.c 			\
		./setters.c				\
		./get_line_utils.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -I$(INCLUDE_DIR)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_file.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	../../../clean.sh

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
