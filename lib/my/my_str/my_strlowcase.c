/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** puts every letter in lowercase
*/

#include "my_str.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (my_isupper(str[i]))
            str[i] = str[i] - ('A' - 'a');
    }

    return str;
}
