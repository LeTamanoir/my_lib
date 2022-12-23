/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vector
*/

#include "my_stdlib.h"
#include "my_vec.h"

vec_t *vec_create(int nb_data, int el_size)
{
    vec_t *vec = malloc(sizeof(vec_t));

    vec->base.size = 0;
    vec->base.el_size = el_size;
    vec->base.capacity = get_padded_size(nb_data, VEC_SIZE);
    vec->data = my_calloc(0, el_size * vec->base.capacity);

    return vec;
}

void vec_void_free(vec_void_t *vec)
{
    for (int i = 0; i < vec->base.size; i++) {
        free(vec->data[i]);
    }
    free(vec->data);
    free(vec);
}

void vec_free(vec_t *vec)
{
    free(vec->data);
    free(vec);
}
