/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** puts every letter in uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_islower(str, i))
            str[i] = str[i] - ('a' - 'A');
        i++;
    }

    return str;
}
