/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** setters
*/

#include "my_stdlib.h"
#include "my_vec.h"
#include "my_obj.h"

vec_t **vec_resize(vec_t **vec, size_t new_cap)
{
    vec_t *old = *vec;
    *vec = obj_realloc(old, sizeof(vec_t) + new_cap * old->__elem_size);

    return vec;
}

void vec_remove(vec_t *vec, size_t idx)
{
    my_memset(vec_at(vec, idx), 0, vec->__elem_size);

    if (idx < vec->size - 1) {
        my_memcpy(
            vec_at(vec, idx), vec_at(vec, idx + 1),
            (vec->size - idx) * vec->__elem_size
        );
    }

    vec->size--;
}

void vec_insert(vec_t **vec, void *elem, size_t idx)
{
    if (idx >= (*vec)->capacity)
        vec_resize(vec, idx + 1);

    my_memcpy(vec_at(*vec, idx), elem, (*vec)->__elem_size);
    (*vec)->size++;
}

void vec_clear(vec_t *vec)
{
    my_memset(vec->data, 0, vec->size * vec->__elem_size);
    vec->size = 0;
}

void vec_pushback(vec_t **vec, void *elem)
{
    if ((*vec)->size + 1 >= (*vec)->capacity)
        vec_resize(vec, (*vec)->size + 1);

    my_memcpy(vec_at(*vec, (*vec)->size), elem, (*vec)->__elem_size);
    (*vec)->size++;
}
