/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** misc
*/

#include "my_stdlib.h"
#include "my_vec.h"

size_t get_padded_size(size_t size)
{
    size_t size_pad = 1;

    while (size_pad < size)
        size_pad *= 2;

    return size_pad;
}

void *vec_at(vec_t *vec, size_t idx)
{
    return vec->data + idx * vec->__elem_size;
}

void vec_popback(vec_t *vec)
{
    if (vec->size == 0)
        return;

    my_memset(vec_at(vec, vec->size), 0, vec->__elem_size);
    vec->size--;
}
