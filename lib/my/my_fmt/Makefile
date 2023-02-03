##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_fmt
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_fmt.c			\
		./add_base.c		\
		./add_join.c		\
		./add_float.c		\
		./adders.c


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
