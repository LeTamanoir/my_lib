##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_lib
##

LIB	=	my_cstr my_file my_fmt \
		my_list my_map my_math \
		my_network my_stdio my_stdlib \
		my_str my_vec

USED	=	-DUSE_MY_STR -DUSE_MY_VEC

all:
	@for i in $(LIB); do make -C $$i; done

clean:
	@for i in $(LIB); do make -C $$i clean; done

fclean:	clean
	@for i in $(LIB); do make -C $$i fclean; done

re:	fclean all

.PHONY: all clean fclean re
