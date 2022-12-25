##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for [PROJECT-NAME]
##

CC = gcc

LIB_DIR	=	./lib/my
SRC_DIR	=	./src
INCLUDE_DIR	=	./include

LIB_MATH	=	-lm
LIB_MY	=	-L.	-lmy

SRC	=	$(SRC_DIR)/main.c

INCLUDE	=	-I$(INCLUDE_DIR)

CFLAGS += -Werror -Wextra -Wall $(INCLUDE)

OBJ	=	$(SRC:.c=.o)

NAME	=	[PROJECT-NAME]

all:	$(NAME)

$(NAME):	lib	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)	$(LIB_MY) $(LIB_MATH)

lib:
	cd ./lib/my && make && cd ../../

clean_lib:
	cd ./lib/my && make fclean && cd ../../

clean:
	rm -f $(OBJ)
	./clean.sh

fclean:	clean clean_lib
	rm -f $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re clean_lib
