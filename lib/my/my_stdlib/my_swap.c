/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** generic swap
*/

#include "my_stdlib.h"

void my_swap(void *a, void *b, size_t el_size)
{
    static char temp[MAX_SWAP_SIZE] = {0};

    if (el_size > MAX_SWAP_SIZE)
        return;

    my_memcpy(temp, b, el_size);
    my_memcpy(b, a, el_size);
    my_memcpy(a, temp, el_size);
}
