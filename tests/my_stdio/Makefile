##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for compiling my lib
##

CC = gcc

TESTS	=	./test_compute_spec_c.c				\
			./test_compute_spec_e.c				\
			./test_compute_spec_g.c				\
			./test_compute_spec_o.c				\
			./test_compute_spec_u.c				\
			./test_compute_spec_b.c				\
			./test_compute_spec_d.c				\
			./test_compute_spec_f.c				\
			./test_compute_spec_n.c				\
			./test_compute_spec_p.c				\
			./test_compute_spec_s.c				\
			./test_compute_spec_x.c				\
			./test_compute_spec_percent.c		\
			./test_my_printf_flags_p_l.c		\
			./test_my_printf_flag_space.c		\
			./test_my_printf_flag_htag.c		\
			./test_my_printf_flag_zero.c		\
			./test_my_printf_precision.c		\
			./test_my_printf_width.c			\
			./test_my_printf.c					\
			./test_my_printf_length.c


INCLUDE	=	-I../../include -I../../lib/my/my_stdio/include

LIB	=	-L../../ -lmy

CFLAGS += -Werror -Wextra -Wall -pedantic $(INCLUDE)

TEST_NAME	=	unit_tests

all: tests_run

unit_tests:
	cd ../../lib/my && \
	make && \
	cd ../../tests/my_stdio && \
	gcc -o $(TEST_NAME) $(TESTS) $(LIB) $(INCLUDE) \
	--coverage -lcriterion

tests_run:
	make unit_tests && ./$(TEST_NAME)

clean:
	rm -f $(OBJ)
	../../clean.sh

fclean:	clean
	rm -f $(TEST_NAME)

.PHONY: tests_run unit_tests clean fclean
