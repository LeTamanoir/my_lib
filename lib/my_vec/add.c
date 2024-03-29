/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** setters
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_insert(void *v, void *elem, size_t idx)
{
    vec_t **vec = (vec_t**)v;

    if (idx >= (*vec)->capacity)
        vec_resize(vec, idx + 1);

    my_memcpy(vec_at(*vec, idx), elem, (*vec)->__elem_size);
    (*vec)->size++;
}

void vec_pushback(void *v, void *elem)
{
    vec_t **vec = (vec_t**)v;

    if ((*vec)->size + 1 >= (*vec)->capacity)
        vec_resize(vec, (*vec)->size + 1);

    my_memcpy(vec_at(*vec, (*vec)->size), elem, (*vec)->__elem_size);
    (*vec)->size++;
}
