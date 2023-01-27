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
    vec_t *new = vec_create(vec->base.size, vec->base.el_size);

    if (new == NULL)
        return NULL;

    for (size_t i = 0; i < vec->base.size; ++i)
        if (keep_fn(vec, i))
            vec_push_back(&new, vec->data + i * vec->base.el_size);

    return new;
}
