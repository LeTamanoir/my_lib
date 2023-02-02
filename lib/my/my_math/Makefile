##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_math
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_pow.c			\
		./my_matrix.c 		\
		./advanced_op.c		\
		./simple_op.c		\
		./inverse.c			\
		./determinant.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -I$(INCLUDE_DIR)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_math.a

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
