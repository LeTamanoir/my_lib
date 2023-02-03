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

NAME	=	../libmy.a

all:	$(OBJ)
	@ar cq $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

re:	clean all

.PHONY: all clean re
