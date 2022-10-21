/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** returns 1 if every chars of the string is printable
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;

    while (str[i] != '\0') {
        if (!my_isprintable(str, i))
            return 0;
        i++;
    }

    return 1;
}
