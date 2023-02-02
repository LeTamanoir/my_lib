##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_stdlib
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_atoi.c			\
		./my_itoa.c			\
		./my_atof.c			\
		./my_ftoa.c			\
		./my_ftoa_utils.c	\
		./my_fftoa.c		\
		./my_nbrlen.c		\
		./my_calloc.c		\
		./my_memcpy.c		\
		./my_memset.c		\
		./my_memcmp.c		\
		./auto_free.c		\
		./my_swap.c			\
		./vfree.c			\
		./my_obj.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -I$(INCLUDE_DIR)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy_stdlib.a

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
