/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** remove from vector
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_remove(void *v, size_t idx)
{
    vec_t *vec = (vec_t*)v;

    my_memset(vec_at(vec, idx), 0, vec->__elem_size);
    if (idx < vec->size - 1) {
        my_memcpy(
            vec_at(vec, idx), vec_at(vec, idx + 1),
            (vec->size - idx) * vec->__elem_size
        );
    }
    vec->size--;
}

void vec_clear(void *v)
{
    vec_t *vec = (vec_t*)v;

    my_memset(vec->data, 0, vec->size * vec->__elem_size);
    vec->size = 0;
}

void vec_popback(void *v)
{
    vec_t *vec = (vec_t*)v;

    if (vec->size == 0)
        return;

    my_memset(vec_at(vec, vec->size - 1), 0, vec->__elem_size);
    vec->size--;
}
