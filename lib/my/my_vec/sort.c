/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vec sort
*/

#include "my_stdlib.h"
#include "my_vec.h"

static int default_key(vec_t *v, int i)
{
    return ((vec_int_t*)v)->data[i];
}

static int partition(vec_t *v, int (*key)(vec_t *, int), int start, int end)
{
    int pivot = key(v, end);
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (key(v, j) < pivot) {
            i++;
            vec_swap(v, i, j);
        }
    }
    i++;
    vec_swap(v, i, end);

    return i;
}

static void quick_sort(vec_t *v, int (*key)(vec_t *, int), int start, int end)
{
    if (start >= end)
        return;

    int center = partition(v, key, start, end);

    quick_sort(v, key, start, center - 1);
    quick_sort(v, key, center + 1, end);
}

void vec_sort(vec_t *vec, int (*key)(vec_t *, int))
{
    if (key == NULL)
        key = &default_key;

    quick_sort(vec, key, 0, vec->base.size - 1);
}
