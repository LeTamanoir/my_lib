##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_ls
##

CC = gcc

INCLUDE_DIR	=	../../include

NETWORK_DIR	=	./my_network
FMT_DIR		=	./my_fmt
OBJ_DIR		=	./my_obj
YAML_DIR	=	./my_yaml
MAP_DIR		=	./my_map
VEC_DIR		=	./my_vec
MATH_DIR	=	./my_math
STDLIB_DIR	=	./my_stdlib
STR_DIR		=	./my_str
FILE_DIR	=	./my_file
STDIO_DIR	=	./my_stdio
LIST_DIR	=	./my_list
MATRIX_DIR	=	./my_matrix
ARRAY_DIR	=	./my_array

INCLUDE_FILE_DIR	=	$(FILE_DIR)/include
INCLUDE_STDIO_DIR	=	$(STDIO_DIR)/include
INCLUDE_LIST_DIR	=	$(LIST_DIR)/include
INCLUDE_MATRIX_DIR	=	$(MATRIX_DIR)/include


MY_NETWORK	=	$(NETWORK_DIR)/create.c 	\
				$(NETWORK_DIR)/run.c 		\
				$(NETWORK_DIR)/accept.c		\
				$(NETWORK_DIR)/utils.c 		\

MY_OBJ		=	$(OBJ_DIR)/my_obj.c

MY_FMT		=	$(FMT_DIR)/my_fmt.c			\
				$(FMT_DIR)/add_base.c		\
				$(FMT_DIR)/add_join.c		\
				$(FMT_DIR)/adders.c


MY_YAML		=	$(YAML_DIR)/my_yaml.c


MY_VEC		=	$(VEC_DIR)/my_vec.c			\
				$(VEC_DIR)/setters.c		\
				$(VEC_DIR)/find.c			\
				$(VEC_DIR)/misc.c			\
				$(VEC_DIR)/filter.c			\
				$(VEC_DIR)/iterators.c		\
				$(VEC_DIR)/sort.c


MY_MAP		=	$(MAP_DIR)/my_map.c				\
				$(MAP_DIR)/getters.c			\
				$(MAP_DIR)/setters.c			\
				$(MAP_DIR)/utils.c


MY_MATH		=	$(MATH_DIR)/my_int_sqrt.c			\
				$(MATH_DIR)/my_pow.c	 			\
				$(MATH_DIR)/my_is_prime.c


MY_STDLIB	=	$(STDLIB_DIR)/my_atoi.c		\
				$(STDLIB_DIR)/my_itoa.c		\
				$(STDLIB_DIR)/my_atof.c		\
				$(STDLIB_DIR)/my_ftoa.c		\
				$(STDLIB_DIR)/my_nbrlen.c	\
				$(STDLIB_DIR)/my_calloc.c	\
				$(STDLIB_DIR)/my_memcpy.c	\
				$(STDLIB_DIR)/my_memset.c	\
				$(STDLIB_DIR)/my_memcmp.c	\
				$(STDLIB_DIR)/auto_free.c	\
				$(STDLIB_DIR)/my_swap.c		\
				$(STDLIB_DIR)/vfree.c


MY_MATRIX	=	$(MATRIX_DIR)/my_matrix.c 	\
				$(MATRIX_DIR)/advanced_op.c	\
				$(MATRIX_DIR)/simple_op.c	\
				$(MATRIX_DIR)/inverse.c		\
				$(MATRIX_DIR)/determinant.c


MY_ARRAY 	=	$(ARRAY_DIR)/array.c


MY_LIST		=	$(LIST_DIR)/my_list.c		\
				$(LIST_DIR)/setters.c		\
				$(LIST_DIR)/iterators.c


MY_STR		=	$(STR_DIR)/my_str.c						\
				$(STR_DIR)/join.c						\
				$(STR_DIR)/adders.c						\
				$(STR_DIR)/content_check.c				\
				$(STR_DIR)/convert.c					\
				$(STR_DIR)/compare.c					\
				$(STR_DIR)/checks.c						\
				$(STR_DIR)/trim.c						\
				$(STR_DIR)/print.c						\
				$(STR_DIR)/str_temp.c					\
				$(STR_DIR)/modifiers.c					\
				$(STR_DIR)/format.c						\
				$(STR_DIR)/misc.c						\
				$(STR_DIR)/getters.c					\
				$(STR_DIR)/c_string/char_infos.c 		\
				$(STR_DIR)/c_string/char_modifiers.c 	\
				$(STR_DIR)/c_string/misc.c 				\
				$(STR_DIR)/c_string/my_strcat.c 		\
				$(STR_DIR)/c_string/my_strcpy.c 		\
				$(STR_DIR)/c_string/my_strcmp.c 		\
				$(STR_DIR)/c_string/my_strdup.c 		\
				$(STR_DIR)/c_string/my_strlen.c 		\
				$(STR_DIR)/c_string/str_infos.c 		\
				$(STR_DIR)/c_string/str_modifiers.c 	\
				$(STR_DIR)/c_string/char_infos.c


MY_FILE		=	$(FILE_DIR)/my_file.c 			\
				$(FILE_DIR)/getters.c 			\
				$(FILE_DIR)/setters.c			\
				$(FILE_DIR)/get_line_utils.c


MY_STDIO	=	$(STDIO_DIR)/my_printf.c								\
				$(STDIO_DIR)/my_dprintf.c								\
				$(STDIO_DIR)/my_put.c


INCLUDE	=	-I$(INCLUDE_STDIO_DIR) -I$(INCLUDE_LIST_DIR) -I$(INCLUDE_DIR) \
			-I$(INCLUDE_FILE_DIR) -I$(INCLUDE_MATRIX_DIR)


CFLAGS += -Werror -Wextra -Wall
CPPFLAGS += $(INCLUDE)

ifeq ($(DEBUG),1)
	CFLAGS += -g3
endif

OBJ	=	$(MY_STDIO:.c=.o) $(MY_LIST:.c=.o) $(MY_STR:.c=.o)		\
		$(MY_FILE:.c=.o) $(MY_MATRIX:.c=.o) $(MY_ARRAY:.c=.o)	\
		$(MY_STDLIB:.c=.o) $(MY_MATH:.c=.o) $(MY_VEC:.c=.o)		\
		$(MY_MAP:.c=.o) $(MY_YAML:.c=.o) $(MY_OBJ:.c=.o)		\
		$(MY_FMT:.c=.o) $(MY_NETWORK:.c=.o)

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
