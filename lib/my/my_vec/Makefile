##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_vec
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_vec.c			\
		./setters.c			\
		./find.c			\
		./misc.c			\
		./filter.c			\
		./iterators.c		\
		./sort.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -I$(INCLUDE_DIR)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_vec.a

all:	$(NAME)

$(NAME):	$(OBJ)
	echo $$USED
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
