/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string class
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_vec.h"
#include "my_obj.h"

str_t *str_ncreate(char const *init, size_t n)
{
    size_t capacity = get_padded_size(n);
    str_t *str = obj_alloc(sizeof(str_t) + sizeof(char) * capacity);

    if (str == NULL)
        return NULL;

    str->length = n;
    str->capacity = capacity;

    my_memcpy(str->data, init, sizeof(char) * n);

    return str;
}

str_t *str_create(char const *init)
{
    size_t len = my_strlen(init);

    return str_ncreate(init, len);
}

str_t *str_dup(str_t *old)
{
    str_t *new = str_ncreate(old->data, old->length);

    return new;
}

str_t *str_substr(str_t *str, size_t start, size_t end)
{
    str_t *new = str_create("");

    str_stradd(&new, str);
    str_slice(&new, start, end);

    return new;
}
