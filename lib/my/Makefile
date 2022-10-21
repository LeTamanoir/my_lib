##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for compiling my lib
##

LIB_DIR	=	../

INCLUDE_DIR	=	../../include


SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c \
		my_detect_overflow.c	\
		my_find_prime_sup.c	\
		my_getnbr_base.c	\
		my_getnbr.c	\
		my_isalpha.c	\
		my_isalphanum.c	\
		my_islower.c	\
		my_isneg.c	\
		my_isnum.c	\
		my_is_prime.c	\
		my_isprintable.c	\
		my_isupper.c	\
		my_pow.c	\
		my_putchar.c	\
		my_putnbr_base.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_show_word_array.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_swap.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlowcase.c	\
		my_strupcase.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c \
		my_calloc.c \
		my_putstderr.c


CFLAGS += -Werror -Wextra -Wall -pedantic -std=c99


OBJ	=	$(SRC:.c=.o)


NAME	=	libmy.a


all:	$(NAME)


$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) $(LIB_DIR)
	if [[ !(( -d $(INCLUDE_DIR) )) ]]; then mkdir $(INCLUDE_DIR); fi
	cp my.h $(INCLUDE_DIR)


clean:
	rm -f $(OBJ)


fclean:	clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)$(NAME)
	
re:	fclean all
