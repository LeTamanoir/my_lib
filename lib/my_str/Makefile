##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_str
##

CC = gcc

INCLUDE_DIR	=	../../../include


SRC	=	./add.c 		\
		./case.c 		\
		./checks.c 		\
		./compare.c		\
		./convert.c 	\
		./from.c 		\
		./create.c 		\
		./format.c 		\
		./join.c 		\
		./modify.c 		\
		./print.c 		\
		./split.c 		\
		./trim.c 		\
		./utils.c 		\

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


fclean:	clean

re:	fclean all

.PHONY: all clean re
