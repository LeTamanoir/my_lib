/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** capitalizes the first letter of each word
*/

#include "my_stdio.h"
#include "my_str.h"

static int is_first(char *str, int i)
{
    if (my_islower(str[i]) && (
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
        return NULL;

    if (my_islower(str[0]))
        str[0] = str[0] - ('a' - 'A');

    for (i = 1; str[i] != '\0'; i++) {
        if (my_isupper(str[i]))
            str[i] = str[i] - ('A' - 'a');
        if (is_first(str, i))
            str[i] = str[i] - ('a' - 'A');
    }

    return str;
}
