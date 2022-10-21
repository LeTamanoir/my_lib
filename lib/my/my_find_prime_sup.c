/*
** EPITECH PROJECT, 2022
** my_find_prime_sup.c
** File description:
** returns the smallest prime number that is greater than the given number
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int max_int = 2147483647;

    if (nb <= 2)
        nb = 2;

    for (int i = nb; i < max_int; i++) {
        if (my_is_prime(i))
            return i;
    }

    return max_int;
}
