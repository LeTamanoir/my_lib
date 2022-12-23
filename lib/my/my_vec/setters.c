/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** setters
*/

#include "my_stdlib.h"
#include "my_vec.h"

void vec_resize(vec_t *vec, int new_size)
{
    int new_cap = get_padded_size(new_size, VEC_SIZE);
    char *data = my_calloc(0, vec->base.el_size * new_cap);

    my_memcpy(data, vec->data, vec->base.capacity * vec->base.el_size);

    free(vec->data);

    vec->base.capacity = new_cap;
    vec->data = data;
}

void vec_remove(vec_t *vec, int idx)
{
    int temp = 0;
    my_memcpy(&(vec->data[idx * vec->base.el_size]), &temp, vec->base.el_size);
    vec->base.size--;
}

void vec_insert(vec_t *vec, void *elem, int idx)
{
    if (idx >= vec->base.capacity) {
        vec_resize(vec, idx + 1);
    }

    my_memcpy(&(vec->data[idx * vec->base.el_size]), elem, vec->base.el_size);
    vec->base.size++;
}

void vec_clear(vec_t *vec)
{
    int temp = 0;
    my_memcpy(vec->data, &temp, vec->base.size * vec->base.el_size);
    vec->base.size = 0;
}

void vec_push_back(vec_t *vec, void *elem)
{
    int size = vec->base.size;

    if (size + 1 >= vec->base.capacity) {
        vec_resize(vec, size + 1);
    }

    my_memcpy(&(vec->data[size * vec->base.el_size]), elem, vec->base.el_size);
    vec->base.size++;
}
