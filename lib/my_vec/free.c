/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** free vector
*/

#include "my_obj.h"
#include "my_vec.h"

void vec_free(void *ptr)
{
    vec_void_t *vec = (vec_void_t*)ptr;

    for (size_t i = 0; i < vec->size; i++)
        obj_free(vec->data[i]);
}
