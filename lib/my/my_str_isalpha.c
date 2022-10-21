/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** returns 1 if every chars of the string is alpha
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;

    while (str[i] != '\0') {
        if (!my_isalpha(str, i))
            return 0;
        i++;
    }

    return 1;
}
