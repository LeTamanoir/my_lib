/*
** EPITECH PROJECT, 2023
** my_itoa.c
** File description:
** converts a number to a string
*/

#include "my_stdlib.h"
#include "my_math.h"

char *my_itoa(long int nb)
{
    int is_neg = nb < 0;
    int len = my_nbrlen(nb, 10) + is_neg;
    char *res = my_malloc(sizeof(char) * (len + 1));
    int i = len - 1;

    res[len] = '\0';
    nb = MY_ABS(nb);
    res[0] = (is_neg) ? '-' : '0';

    while (nb) {
        res[i--] = (nb % 10) + '0';
        nb /= 10;
    }
    return res;
}
