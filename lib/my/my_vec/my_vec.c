/*
** EPITECH PROJECT, 2022
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

    obj_set_destructor(vec, NULL);
    vec->size = 0;
    vec->capacity = capacity;
    vec->__elem_size = elem_size;

    return vec;
}

void vec_free(void *ptr)
{
    vec_void_t *vec = (vec_void_t*)ptr;

    for (size_t i = 0; i < vec->size; i++)
        obj_free(vec->data[i]);
}
