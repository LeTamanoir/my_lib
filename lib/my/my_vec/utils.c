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

void *vec_at(void *v, size_t idx)
{
    vec_t *vec = (vec_t*)v;

    return vec->data + idx * vec->__elem_size;
}
