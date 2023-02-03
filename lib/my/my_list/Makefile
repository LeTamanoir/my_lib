##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_list
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./my_list.c		\
		./setters.c		\
		./iterators.c

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
