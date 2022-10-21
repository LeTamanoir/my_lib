/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** puts every letter in lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_isupper(str, i))
            str[i] = str[i] - ('A' - 'a');
        i++;
    }

    return str;
}
