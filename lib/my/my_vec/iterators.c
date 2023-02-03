/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** iterators
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_foreach(vec_t *vec, void (*fn)(void *, size_t, void *), void *data)
{
    for (size_t i = 0; i < vec->size; i++)
        fn(vec_at(vec, i), i, data);
}
