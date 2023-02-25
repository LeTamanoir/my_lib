##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_lib
##

# Modules available:
# my_map my_list my_btree my_vec my_str

# Modules to use:
LIB	=	my_map my_list my_vec my_btree my_str

NAME	=	libmy.a

all:
	@for i in $(LIB); do make -C $$i; done

clean:
	@for i in $(LIB); do make -C $$i clean >/dev/null; done

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
