/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** vector
*/

#include "my_stdlib.h"
#include "my_vec.h"
#include "my_obj.h"

void *vec_create(size_t nb_data, size_t elem_size)
{
    if (elem_size > MAX_SWAP_SIZE)
        return NULL;

    size_t capacity = get_padded_size(nb_data);
    vec_t *vec = obj_alloc(sizeof(vec_t) + elem_size * capacity);

    if (vec == NULL)
        return NULL;

    vec->size = 0;
    vec->capacity = capacity;
    vec->__elem_size = elem_size;

    return vec;
}
