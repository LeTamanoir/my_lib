/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** misc
*/

#include "my_obj.h"
#include "my_vec.h"

size_t get_padded_size(size_t size)
{
    size_t size_pad = 128;

    while (size_pad < size)
        size_pad *= 2;

    return size_pad;
}

void *vec_at(void *v, size_t idx)
{
    vec_t *vec = (vec_t*)v;

    return vec->data + idx * vec->__elem_size;
}

vec_t **vec_resize(vec_t **vec, size_t new_size)
{
    size_t new_cap = get_padded_size(new_size);
    vec_t *old = *vec;

    *vec = obj_realloc(old, sizeof(vec_t) + new_cap * old->__elem_size);
    (*vec)->capacity = new_cap;

    return vec;
}
