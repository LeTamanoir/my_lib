/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_obj.h"

str_t **str_clear(str_t **str)
{
    my_memset((*str)->data, 0, sizeof(char) * (*str)->capacity);
    (*str)->length = 0;

    return str;
}

str_t **str_resize(str_t **str, size_t new_len)
{
    size_t new_cap = get_padded_size(new_len);
    str_t *old = *str;

    *str = obj_realloc(old, sizeof(str_t) + sizeof(char) * new_cap);

    return str;
}
