/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** modifiers
*/

#include "my_str.h"

str_t *str_lowcase(str_t *str)
{
    for (size_t i = 0; i < str->length; ++i)
        str->data[i] = my_lowcase(str->data[i]);

    return str;
}

str_t *str_upcase(str_t *str)
{
    for (size_t i = 0; i < str->length; ++i)
        str->data[i] = my_upcase(str->data[i]);

    return str;
}
