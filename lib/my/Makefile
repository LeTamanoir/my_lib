##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_ls
##

CC = gcc

INCLUDE_DIR	=	../../include

STRING_DIR	=	./my_string

STDIO_DIR	=	./my_stdio
INCLUDE_STDIO_DIR	=	$(STDIO_DIR)/include

LK_LIST_DIR	=	./my_lk_list
INCLUDE_LK_LIST_DIR	=	$(LK_LIST_DIR)/include


LIB	=	./my_int_sqrt.c 			\
		./my_find_prime_sup.c		\
		./my_getnbr_base.c			\
		./my_atoi.c					\
		./my_isalpha.c				\
		./my_isalphanum.c			\
		./my_islower.c				\
		./my_isnum.c				\
		./my_is_prime.c				\
		./my_isprintable.c			\
		./my_isupper.c				\
		./my_nbr_length.c			\
		./my_pow.c					\
		./my_putchar.c				\
		./my_putnbr_base.c			\
		./my_put_nbr.c				\
		./my_putstr.c				\
		./my_puts.c					\
		./my_revstr.c				\
		./my_showmem.c				\
		./my_showstr.c				\
		./my_show_word_array.c		\
		./my_sort_int_array.c		\
		./my_strcapitalize.c		\
		./my_swap.c					\
		./my_str_isalpha.c			\
		./my_str_islower.c			\
		./my_str_isnum.c			\
		./my_str_isprintable.c		\
		./my_str_isupper.c			\
		./my_strlowcase.c			\
		./my_lowcase.c				\
		./my_upcase.c				\
		./my_strupcase.c			\
		./my_strcat.c				\
		./my_strcmp.c				\
		./my_strcpy.c				\
		./my_strdup.c				\
		./my_strlen.c				\
		./my_strncat.c				\
		./my_strncmp.c				\
		./my_strncpy.c				\
		./my_strstr.c				\
		./my_str_to_word_array.c 	\
		./my_calloc.c 				\
		./my_putstderr.c			\
		./my_ll_pow.c				\
		./my_itoa.c


MY_LK_LIST	=	$(LK_LIST_DIR)/my_lk_list.c				\
				$(LK_LIST_DIR)/my_lk_list_utils.c

MY_STRING	=	$(STRING_DIR)/my_string.c


MY_STDIO	=	$(STDIO_DIR)/my_printf.c								\
				$(STDIO_DIR)/my_sprintf.c								\
				$(STDIO_DIR)/my_dprintf.c								\
				$(STDIO_DIR)/my_vasprintf.c								\
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
				$(STDIO_DIR)/src/specifiers/compute_spec_t.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_s.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_x.c			\
				$(STDIO_DIR)/src/specifiers/compute_spec_percent.c		\
				$(STDIO_DIR)/src/specifiers/utils/spec_int_utils.c		\
				$(STDIO_DIR)/src/specifiers/utils/str_operations.c		\
				$(STDIO_DIR)/src/specifiers/utils/float_utils.c			\
				$(STDIO_DIR)/src/specifiers/utils/round_float.c			\
				$(STDIO_DIR)/src/specifiers/utils/spec_e_utils.c		\
				$(STDIO_DIR)/src/specifiers/utils/spec_a_utils.c


INCLUDE	=	-I$(INCLUDE_STDIO_DIR) -I$(INCLUDE_LK_LIST_DIR) -I$(INCLUDE_DIR)


CFLAGS += -Werror -Wextra -Wall -pedantic $(INCLUDE)

OBJ	=	$(MY_STDIO:.c=.o) $(LIB:.c=.o) $(MY_LK_LIST:.c=.o) $(MY_STRING:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../

clean:
	rm -f $(OBJ)
	../../clean.sh

fclean:	clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all

.PHONY: all clean fclean re
