##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_math
##

CC = gcc

INCLUDE	=	-I../../include


SRC	=	./my_pow.c					\
		./matrix/create.c 			\
		./matrix/dot.c	 			\
		./matrix/inverse.c 			\
		./matrix/operation.c		\
		./matrix/transp.c 			\
		./matrix/utils.c

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += $(INCLUDE)

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
