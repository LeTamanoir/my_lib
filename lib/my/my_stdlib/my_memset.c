/*
** EPITECH PROJECT, 2022
** my_memcpy
** File description:
** memcpy
*/

#include "my_stdlib.h"

void *my_memset(void *dest, unsigned char c, size_t len)
{
    uint32_t *dest_int = dest;
    uint8_t *dest_chr = NULL;
    uint32_t to_copy = c << 24 | c << 16 | c << 8 | c;

    size_t len_int = len / 4;
    size_t len_chr = len % 4;

    while (len_int--)
        *dest_int++ = to_copy;

    dest_chr = (uint8_t *)dest_int;

    while (len_chr-- > 0)
        *dest_chr++ = c;

    return dest;
}
