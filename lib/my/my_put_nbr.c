/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** displays the number giben as param
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }

    int pow_10 = my_pow(10, my_nbr_length(nb) - 1);

    while (pow_10 > 0) {
        my_putchar((nb / pow_10) % 10 + '0');
        pow_10 /= 10;
    }

    return 0;
}
