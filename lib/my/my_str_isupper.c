/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** returns 1 if every chars of the string is upper
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;

    while (str[i] != '\0') {
        if (!my_isupper(str, i))
            return 0;
        i++;
    }

    return 1;
}
