/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** calloc clone
*/

#include <stdlib.h>

void *my_calloc(char pad, size_t size)
{
    void *temp = malloc(size);

    if (temp == NULL) return NULL;

    for (size_t i = 0; i < size; i++) {
        ((char *)temp)[i] = pad;
    }

    return temp;
}
