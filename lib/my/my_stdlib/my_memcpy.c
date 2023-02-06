/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** memcpy
*/

#include "my_stdlib.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    uint32_t *dest_int = dest;
    uint32_t const *src_int = src;
    uint8_t *dest_chr = NULL;
    uint8_t const *src_chr = NULL;

    size_t len_int = n / 4;
    size_t len_chr = n % 4;

    while (len_int--)
        *dest_int++ = *src_int++;

    dest_chr = (uint8_t *)dest_int;
    src_chr = (uint8_t *)src_int;

    while (len_chr-- > 0)
        *dest_chr++ = *src_chr++;

    return dest;
}
