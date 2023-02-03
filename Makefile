##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for [PROJECT-NAME]
##

CC = gcc

SRC_DIR	=	./src
INCLUDE_DIR	=	./include

LIB	=	-L./lib/my -lmy

SRC	=	$(SRC_DIR)/main.c

INCLUDE	=	-I$(INCLUDE_DIR)

CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += $(INCLUDE)
LDDFLAGS += $(LIB)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(SRC:.c=.o)

NAME	=	[PROJECT-NAME]

all:	$(NAME)

$(NAME):	lib	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDDFLAGS)

tests_run:
	make -C ./tests/unit_tests

lib:
	make -C ./lib/my

clean_lib:
	make -C ./lib/my fclean

clean:
	rm -f $(OBJ)
	./clean.sh

fclean:	clean clean_lib
	rm -f $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re clean_lib
