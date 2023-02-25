/*
** EPITECH PROJECT, 2022
** antman
** File description:
** checks
*/

#include "my_str.h"

int str_contains(str_t *str, char c)
{
    for (size_t i = 0; i < str->length; ++i)
        if (str->data[i] == c)
            return 1;

    return 0;
}

int str_startswith(str_t *str, str_t *start)
{
    int status = str_ncompare(str, start, start->length) == 0;

    return status;
}

int str_endswith(str_t *str, str_t *end)
{
    size_t i = str->length - end->length - 1;

    while (i < str->length - 1 && str->data[i] == end->data[i])
        i++;

    return i == str->length;
}

int str_isalpha(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_isalpha(str->data[i]))
            return 0;

    return 1;
}

int str_isnum(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_isnum(str->data[i]))
            return 0;

    return 1;
}
