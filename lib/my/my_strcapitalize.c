/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** capitalizes the first letter of each word
*/

#include "my.h"

static int is_first(char *str, int i)
{
    if (my_islower(str, i) && (
        str[i - 1] == '-' ||
        str[i - 1] == '+' ||
        str[i - 1] == ' ')) {
        return 1;
    }

    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str[0] == '\0')
        return '\0';

    if (my_islower(str, 0))
        str[0] = str[0] - ('a' - 'A');

    while (str[i] != '\0') {
        if (my_isupper(str, i))
            str[i] = str[i] - ('A' - 'a');
        if (is_first(str, i))
            str[i] = str[i] - ('a' - 'A');
        i++;
    }

    return str;
}
