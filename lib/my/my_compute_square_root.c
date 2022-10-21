/*
** EPITECH PROJECT, 2022
** my_compute_square_root.c
** File description:
** returns the sqrt of a given number if the sqrt is whole
** else returns 0
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int sqrt_try = 0;
    int index = 0;

    if (nb <= 0)
        return 0;
    if (nb % 2 != 0)
        index = 1;

    while (sqrt_try < nb) {
        sqrt_try = index * index;
        index += 2;

        if (index > 46341 + 2)
            return 0;
    }

    if (sqrt_try == nb)
        return index - 2;

    return 0;
}
