/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** returns 1 if every chars of the string is digit
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;

    while (str[i] != '\0') {
        if (!my_isnum(str, i))
            return 0;
        i++;
    }

    return 1;
}
