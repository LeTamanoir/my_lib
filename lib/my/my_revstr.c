/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int index = 0;
    int length = my_strlen(str);
    char temp;

    while (index < length / 2) {
        temp = str[index];
        str[index] = str[length - index - 1];
        str[length - index - 1] = temp;
        index++;
    }

    return str;
}
