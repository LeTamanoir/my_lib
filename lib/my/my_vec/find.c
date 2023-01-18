/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** find
*/

#include "my_stdlib.h"
#include "my_vec.h"

void *vec_find(vec_t *vec, void *to_find)
{
    for (size_t i = 0; i < vec->base.size; ++i) {
        if (my_memcmp(
            vec->data + i * vec->base.el_size,
            to_find, vec->base.el_size
            ) == 0) {
            return vec->data + i * vec->base.el_size;
        }
    }

    return NULL;
}

void *vec_find_fn(vec_t *vec, int (*find_fn)(vec_t *, size_t))
{
    for (size_t i = 0; i < vec->base.size; ++i) {
        if (find_fn(vec, i)) {
            return vec->data + i * vec->base.el_size;
        }
    }

    return NULL;
}
