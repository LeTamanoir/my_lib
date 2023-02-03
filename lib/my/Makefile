##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## the makefile for my_lib
##

# Modules available:
ALL_LIB = 	my_network my_file my_math my_map \
			my_list my_stdio my_fmt \
			my_stdlib my_vec my_str my_cstr

# Modules to use:
USE_LIB	=	my_math my_fmt my_stdio my_stdlib my_vec my_str my_cstr

NAME	=	libmy.a

all:
	@for i in $(USE_LIB); do make -C $$i; done

clean:
	@for i in $(ALL_LIB); do make -C $$i clean; done

fclean:	clean
	@for i in $(ALL_LIB); do make -C $$i fclean; done
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
