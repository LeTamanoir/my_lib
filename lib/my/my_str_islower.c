/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** returns 1 if every chars of the string is lower
*/

#include "my.h"

int my_str_islower(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;

    while (str[i] != '\0') {
        if (!my_islower(str, i))
            return 0;
        i++;
    }

    return 1;
}
