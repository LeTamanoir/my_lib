/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include "my_stdlib.h"
#include "my_str.h"

char *my_revstr(char *str)
{
    size_t length = my_strlen(str);
    size_t idx = 0;
    char temp = '\0';

    while (idx < length / 2) {
        temp = str[idx];
        str[idx] = str[length - idx - 1];
        str[length - idx - 1] = temp;
        idx++;
    }

    return str;
}

int my_str_isint(char const *str)
{
    if (str[0] == '\0')
        return 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if (!my_isnum(str[i]))
            return 0;
    }

    return 1;
}

int my_str_isfloat(char const *str)
{
    int float_pt = 0;

    if (str[0] == '\0')
        return 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (!my_isnum(str[i]) && str[i] != '.')
            return 0;
        if (str[i] == '.')
            float_pt++;
    }

    return (float_pt <= 1);
}
