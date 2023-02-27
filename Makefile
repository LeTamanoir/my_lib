##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for [PROJECT-NAME]
##

CC = gcc

SRC_DIR	=	./src
INCLUDE_DIR	=	./include

LIB	=	-L./lib -lmy

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

all:	lib $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDDFLAGS)

tests_run:
	make -C ./tests/unit_tests

lib:
	make -C ./lib

clean:
	rm -f $(OBJ)
	@./scripts/clean.sh

fclean:	clean
	make -C ./lib fclean
	make -C ./tests/unit_tests fclean
	rm -f $(NAME)

re:	fclean lib all

.PHONY: all lib clean fclean re
