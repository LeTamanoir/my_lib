/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** calloc small clone
*/

#include "my_stdlib.h"

void *my_malloc(size_t size)
{
    void *temp = malloc(sizeof(alloc_meta_t) + size);

    if (temp == NULL)
        return NULL;

    ((alloc_meta_t*)temp)->size = size;

    return temp + sizeof(alloc_meta_t);
}

void *my_realloc(void *ptr, size_t size)
{
    size_t old_size = ((alloc_meta_t*)(ptr - sizeof(alloc_meta_t)))->size;
    void *temp = my_malloc(size);

    if (temp == NULL)
        return NULL;

    my_memcpy(temp, ptr, old_size);
    my_free(ptr);

    return temp;
}

void *my_calloc(size_t count, size_t elem_size)
{
    void *temp = my_malloc(count * elem_size);

    if (temp == NULL)
        return NULL;

    my_memset(temp, 0, count * elem_size);

    return temp;
}
