/*
** EPITECH PROJECT, 2022
** my_showstr.c
** File description:
** prints a string and returns 0
*/

#include "my.h"

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~') {
            my_putchar(str[i]);
            continue;
        }

        my_putchar('\\');

        if (str[i] >= '\0' && str[i] <= '\x0F')
            my_putchar('0');

        my_putnbr_base(str[i], "0123456789abcdef");
    }

    return 0;
}
