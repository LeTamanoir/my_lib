/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** setters
*/

#include "my_stdlib.h"
#include "my_vec.h"
#include "my_obj.h"

vec_t **vec_resize(vec_t **vec, size_t new_size)
{
    vec_t *old = *vec;
    *vec = vec_create(new_size, old->__elem_size);

    if (*vec == NULL)
        return NULL;

    obj_set_destructor(*vec, obj_get_destructor(old));
    my_memcpy((*vec)->data, old->data, old->size * old->__elem_size);
    (*vec)->size = old->size;
    obj_set_destructor(old, NULL);
    obj_free(old);
    return vec;
}

void vec_remove(vec_t *vec, size_t idx)
{
    my_memset(vec->data + idx * vec->__elem_size, 0, vec->__elem_size);

    if (idx < vec->size - 1) {
        my_memcpy(
            vec->data + idx * vec->__elem_size,
            vec->data + (idx + 1) * vec->__elem_size,
            (vec->size - idx) * vec->__elem_size
        );
    }

    vec->size--;
}

void vec_insert(vec_t **vec, void *elem, size_t idx)
{
    if (idx >= (*vec)->capacity)
        vec_resize(vec, idx + 1);

    my_memcpy(
        (*vec)->data + idx * (*vec)->__elem_size,
        elem, (*vec)->__elem_size
    );
    (*vec)->size++;
}

void vec_clear(vec_t *vec)
{
    my_memset(vec->data, 0, vec->size * vec->__elem_size);
    vec->size = 0;
}

void vec_push_back(vec_t **vec, void *elem)
{
    if ((*vec)->size + 1 >= (*vec)->capacity)
        vec_resize(vec, (*vec)->size + 1);

    my_memcpy(
        (*vec)->data + (*vec)->size * (*vec)->__elem_size,
        elem, (*vec)->__elem_size
    );
    (*vec)->size++;
}
