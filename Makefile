##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for compiling my lib
##

CC = gcc

LIB_DIR	=	./lib/my
INCLUDE_DIR	=	./include
STDIO_DIR	=	./lib/my/my_stdio
INCLUDE_STDIO_DIR	=	./lib/my/my_stdio/include

LIB	=	$(LIB_DIR)/my_int_sqrt.c 			\
		$(LIB_DIR)/my_detect_overflow.c		\
		$(LIB_DIR)/my_find_prime_sup.c		\
		$(LIB_DIR)/my_getnbr_base.c			\
		$(LIB_DIR)/my_getnbr.c				\
		$(LIB_DIR)/my_isalpha.c				\
		$(LIB_DIR)/my_isalphanum.c			\
		$(LIB_DIR)/my_islower.c				\
		$(LIB_DIR)/my_isnum.c				\
		$(LIB_DIR)/my_is_prime.c			\
		$(LIB_DIR)/my_isprintable.c			\
		$(LIB_DIR)/my_isupper.c				\
		$(LIB_DIR)/my_nbr_length.c			\
		$(LIB_DIR)/my_pow.c					\
		$(LIB_DIR)/my_putchar.c				\
		$(LIB_DIR)/my_putnbr_base.c			\
		$(LIB_DIR)/my_put_nbr.c				\
		$(LIB_DIR)/my_putstr.c				\
		$(LIB_DIR)/my_revstr.c				\
		$(LIB_DIR)/my_showmem.c				\
		$(LIB_DIR)/my_showstr.c				\
		$(LIB_DIR)/my_show_word_array.c		\
		$(LIB_DIR)/my_sort_int_array.c		\
		$(LIB_DIR)/my_strcapitalize.c		\
		$(LIB_DIR)/my_swap.c				\
		$(LIB_DIR)/my_str_isalpha.c			\
		$(LIB_DIR)/my_str_islower.c			\
		$(LIB_DIR)/my_str_isnum.c			\
		$(LIB_DIR)/my_str_isprintable.c		\
		$(LIB_DIR)/my_str_isupper.c			\
		$(LIB_DIR)/my_strlowcase.c			\
		$(LIB_DIR)/my_strupcase.c			\
		$(LIB_DIR)/my_strcat.c				\
		$(LIB_DIR)/my_strcmp.c				\
		$(LIB_DIR)/my_strcpy.c				\
		$(LIB_DIR)/my_strdup.c				\
		$(LIB_DIR)/my_strlen.c				\
		$(LIB_DIR)/my_strncat.c				\
		$(LIB_DIR)/my_strncmp.c				\
		$(LIB_DIR)/my_strncpy.c				\
		$(LIB_DIR)/my_strstr.c				\
		$(LIB_DIR)/my_str_to_word_array.c 	\
		$(LIB_DIR)/my_calloc.c 				\
		$(LIB_DIR)/my_putstderr.c			\
		$(LIB_DIR)/my_ll_pow.c				\
		$(LIB_DIR)/my_itoa.c				\


MY_STDIO	=	$(STDIO_DIR)/my_printf.c								\
				$(STDIO_DIR)/my_sprintf.c								\
				$(STDIO_DIR)/my_fprintf.c								\
				$(STDIO_DIR)/my_dprintf.c								\
				$(STDIO_DIR)/src/core.c    								\
				$(STDIO_DIR)/src/parser.c								\
				$(STDIO_DIR)/src/buffer.c								\
				$(STDIO_DIR)/src/exec_specifier.c						\
				$(STDIO_DIR)/src/post_processor.c						\
				$(STDIO_DIR)/src/state.c								\
				$(STDIO_DIR)/src/utils/buffer_utils.c					\
				$(STDIO_DIR)/src/utils/exec_specifiers_utils.c			\
				$(STDIO_DIR)/src/utils/post_processor_utils.c			\
				$(STDIO_DIR)/src/utils/post_processor_extractors.c		\
				$(STDIO_DIR)/src/specifiers/compute_spec_a.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_c.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_e.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_g.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_o.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_u.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_b.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_d.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_f.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_n.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_p.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_s.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_x.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_percent.c		\
				$(STDIO_DIR)/src/specifiers/utils/spec_int_utils.c		\
				$(STDIO_DIR)/src/specifiers/utils/str_operations.c		\
				$(STDIO_DIR)/src/specifiers/utils/float_utils.c			\
				$(STDIO_DIR)/src/specifiers/utils/round_float.c			\
				$(STDIO_DIR)/src/specifiers/utils/spec_e_utils.c		\
				$(STDIO_DIR)/src/specifiers/utils/spec_a_utils.c


INCLUDE	=	-I$(INCLUDE_DIR) -I$(INCLUDE_STDIO_DIR)

CFLAGS += -Werror -Wextra -Wall -pedantic -std=c99 $(INCLUDE)

OBJ	=	$(MY_STDIO:.c=.o) $(LIB:.c=.o)

NAME	=	libmy.a

all:	$(NAME)


$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find \( -name "*.gcda" -or -name "*.gcno" -or -name "vgcore*" \) -delete


fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
