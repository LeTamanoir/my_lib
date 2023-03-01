/*
** EPITECH PROJECT, 2023
** my_str
** File description:
** misc
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_obj.h"

str_t **str_resize(str_t **str, size_t new_size)
{
    size_t new_cap = get_padded_size(new_size);
    str_t *old = *str;

    *str = obj_realloc(old, sizeof(str_t) + sizeof(char) * new_cap);
    (*str)->capacity = new_cap;

    return str;
}
