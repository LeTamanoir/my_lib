/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** displays the characters of a string
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));

    return 0;
}
