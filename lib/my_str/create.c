/*
** EPITECH PROJECT, 2023
** my_str
** File description:
** string class
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_vec.h"
#include "my_obj.h"

str_t *str_screate(size_t n)
{
    size_t capacity = get_padded_size(n);
    str_t *str = obj_alloc(sizeof(str_t) + sizeof(char) * capacity);

    if (str == NULL)
        return NULL;

    str->length = 0;
    str->capacity = capacity;

    return str;
}

str_t *str_ncreate(char const *init, size_t n)
{
    str_t *str = str_screate(n);

    if (str == NULL)
        return NULL;

    str->length = n;
    my_memcpy(str->data, init, sizeof(char) * n);

    return str;
}

str_t *str_create(char const *init)
{
    size_t len = my_strlen(init);

    return str_ncreate(init, len);
}

str_t *str_dup(str_t const *old)
{
    str_t *new = str_ncreate(old->data, old->length);

    return new;
}

str_t *str_substr(str_t const *str, size_t start, size_t end)
{
    str_t *new = str_screate(end - start);

    str_nadd(&new, str->data + start, end - start);

    return new;
}
