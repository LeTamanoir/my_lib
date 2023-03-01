/*
** EPITECH PROJECT, 2023
** my_str
** File description:
** str case functions
*/

#include "my_str.h"

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

str_t *str_tolowcase(str_t *str)
{
    for (size_t i = 0; i < str->length; ++i)
        str->data[i] = my_lowcase(str->data[i]);

    return str;
}

str_t *str_toupcase(str_t *str)
{
    for (size_t i = 0; i < str->length; ++i)
        str->data[i] = my_upcase(str->data[i]);

    return str;
}
