/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** find
*/

#include "my_stdlib.h"
#include "my_vec.h"

void *vec_find(vec_t *vec, int (*find_fn)(void *))
{
    for (size_t i = 0; i < vec->size; ++i) {
        if (find_fn(vec_at(vec, i))) {
            return vec_at(vec, i);
        }
    }

    return NULL;
}
