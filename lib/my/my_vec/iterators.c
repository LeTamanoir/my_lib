/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** iterators
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_for_each(vec_t *vec, int (*fn)(void *, void *), void *data)
{
    for (size_t i = 0; i < vec->base.size; i++) {
        if (fn(vec->data + i * vec->base.el_size, data))
            return;
    }
}
