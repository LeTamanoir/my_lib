/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** recursive implementation of math pow
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{

    if (p < 0)
        return 0;
    else if ((p == 0 && nb == 0) || p == 0)
        return 1;

    int res = my_compute_power_rec(nb, p - 1);

    if (my_detect_overflow(res, nb))
        return 0;

    return res * nb;
}
