/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** misc
*/

#include "my_vec.h"

size_t get_padded_size(size_t size)
{
    size_t size_pad = 1;

    while (size_pad < size)
        size_pad *= 2;

    return size_pad;
}
