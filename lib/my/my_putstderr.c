/*
** EPITECH PROJECT, 2022
** my_putstderr.c
** File description:
** printfs a string to the error output
*/

#include <unistd.h>
#include "my.h"

int my_putstderr(char const *str)
{
    write(2, str, my_strlen(str));

    return 0;
}
