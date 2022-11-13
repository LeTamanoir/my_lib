/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** converts a number to a string
*/

#include <stdio.h>

#include "my_stdlib.h"
#include "my_math.h"

char *my_itoa(long long nb)
{
    int is_neg = nb < 0;
    int len = my_nbr_length(nb);
    char *res = my_calloc('\0', sizeof(char) * (len + is_neg + 1));
    int i = 0;
    long long pow_10 = my_ll_pow(10, len - 1);

    if (is_neg) {
        nb *= -1;
        res[i++] = '-';
    }
    while (pow_10) {
        res[i] = (nb / pow_10) % 10 + '0';
        pow_10 /= 10;
        i++;
    }

    return res;
}
