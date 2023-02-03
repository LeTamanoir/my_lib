/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** filter
*/

#include "my_stdlib.h"
#include "my_vec.h"
#include "my_obj.h"

vec_t *vec_filter(vec_t *vec, int (*keep_fn)(vec_t *, size_t))
{
    vec_t *new = vec_create(vec->size, vec->__elem_size);

    if (new == NULL)
        return NULL;

    for (size_t i = 0; i < vec->size; ++i)
        if (keep_fn(vec, i))
            vec_pushback(&new, vec->data + i * vec->__elem_size);

    return new;
}
