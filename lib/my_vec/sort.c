/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vec sort
*/

#include <string.h>

#include "my_vec.h"

static int default_compare(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

static void swap(void *a, void *b, size_t size)
{
    char tmp[size];

    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

static size_t partition(
    vec_t *v, int (*cmp)(void *, void *),
    size_t start, size_t end
)
{
    size_t pivot = end;
    size_t i = start - 1;

    for (size_t j = start; j < end; ++j) {
        if (cmp(vec_at(v, j), vec_at(v, pivot)) <= 0) {
            i++;
            swap(vec_at(v, i), vec_at(v, j), v->_elem_size);
        }
    }
    i++;
    swap(vec_at(v, i), vec_at(v, end), v->_elem_size);
    return i;
}

static void quick_sort(
    vec_t *v, int (*cmp)(void *, void *),
    size_t start, size_t end
)
{
    if (start >= end)
        return;

    size_t center = partition(v, cmp, start, end);

    quick_sort(v, cmp, start, center - 1);
    quick_sort(v, cmp, center + 1, end);
}

void vec_sort(void *v, int (*cmp)(void *, void *))
{
    vec_t *vec = (vec_t*)v;

    if (cmp == NULL)
        cmp = &default_compare;

    quick_sort(vec, cmp, 0, vec->size - 1);
}
