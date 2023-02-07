##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_math
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_pow.c					\
		./my_matrix/create.c 		\
		./my_matrix/dot.c	 		\
		./my_matrix/inverse.c 		\
		./my_matrix/operation.c		\
		./my_matrix/transp.c 		\
		./my_matrix/utils.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += -I$(INCLUDE_DIR)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy.a

all:	$(OBJ)
	@ar cq $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

re:	clean all

.PHONY: all clean re
