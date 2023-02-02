/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** calloc small clone
*/

#include "my_stdlib.h"

void *my_calloc(size_t count, size_t elem_size)
{
    void *temp = malloc(count * elem_size);

    if (temp == NULL)
        return NULL;

    my_memset(temp, 0, count * elem_size);

    return temp;
}
