/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** iterators
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_foreach(void *v, void (*fn)(void *, size_t, void *), void *data)
{
    vec_t *vec = (vec_t*)v;

    for (size_t i = 0; i < vec->size; i++)
        fn(vec_at(vec, i), i, data);
}
