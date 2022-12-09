/*
** EPITECH PROJECT, 2022
** my_puts.c
** File description:
** displays the characters of a string
*/

#include "my_stdio.h"

int my_puts(char const *str)
{
    my_putstr(str);
    my_putchar('\n');

    return 0;
}
