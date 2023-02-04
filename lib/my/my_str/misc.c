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

void str_replace(str_t **str, str_t const *old, str_t const *new)
{
    str_t *new_str = str_screate((*str)->length);

    for (size_t i = 0, j = 0; i < (*str)->length; ++i) {
        if ((*str)->data[i] != old->data[j]) {
            j = 0;
            str_cadd(&new_str, (*str)->data[i]);
            continue;
        }
        ++j;
        if (j == old->length) {
            str_stradd(&new_str, new);
            j = 0;
        }
    }
    obj_free(*str);
    *str = new_str;
}
