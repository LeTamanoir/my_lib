/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** content check
*/

#include "my_str.h"

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

int str_islower(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_islower(str->data[i]))
            return 0;

    return 1;
}

int str_isupper(str_t const *str)
{
    if (str->length == 0)
        return 0;

    for (size_t i = 0; i < str->length; ++i)
        if (!my_isupper(str->data[i]))
            return 0;

    return 1;
}
