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

str_t **str_slice(str_t **str, size_t start, size_t end)
{
    for (size_t i = 0; i < end - start; i++)
        (*str)->data[i] = (*str)->data[start + i];

    (*str)->length = end - start;

    return str;
}

str_t *str_reverse(str_t *str)
{
    size_t len = str->length;
    size_t idx = 0;
    char temp;

    while (idx < len / 2) {
        temp = str->data[idx];
        str->data[idx] = str->data[len - idx - 1];
        str->data[len - idx - 1] = temp;
        idx++;
    }

    return str;
}
