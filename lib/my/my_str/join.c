/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** join
*/

#include "my_vec.h"
#include "my_str.h"

str_t *str_join(vec_str_t *vec, str_t *delim)
{
    str_t *new = str_create("");

    for (size_t i = 0; i < vec->base.size; ++i) {
        if (i != 0)
            str_stradd(&new, delim);
        str_stradd(&new, vec->data[i]);
    }

    return new;
}