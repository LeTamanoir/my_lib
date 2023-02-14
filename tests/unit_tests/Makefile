##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for compiling my lib
##

CC = gcc

SRC	=

TESTS	=

INCLUDE	=	-I../../include

LIB	=	-L../../ -lmy

CFLAGS += -Werror -Wextra -Wall $(INCLUDE)

TEST_NAME	=	unit_tests

all: tests_run

unit_tests:
	@../../scripts/clean.sh
	make -C ../../lib/my
	$(CC) -o $(TEST_NAME) $(SRC) $(TESTS) $(LIB) $(INCLUDE) \
	--coverage -lcriterion

tests_run: unit_tests
	./$(TEST_NAME)

clean:
	@../../scripts/clean.sh

fclean:	clean
	@rm -f $(TEST_NAME)

.PHONY: tests_run unit_tests clean fclean
