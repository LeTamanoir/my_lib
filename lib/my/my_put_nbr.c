/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** displays the number giben as param
*/

#include "my.h"

static long int my_long_pow(long int number, int power)
{
    long int num = 1;

    for (int i = 0; i < power; i++) {
        num = num * number;
    }

    return num;
}

static int my_get_digit(long number, int index)
{
    return ((number % my_long_pow(10, index)) / my_long_pow(10, index - 1));
}

static int my_nbr_length(long nb)
{
    int nb_digit = 0;

    while (nb) {
        nb = nb / 10;
        nb_digit++;
    }

    return nb_digit;
}

int my_put_nbr(int nb)
{
    long int number;

    number = nb;

    if (number == 0) {
        my_putchar('0');
        return 0;
    }
    if (number < 0) {
        my_putchar('-');
        number = -number;
    }

    for (int i = my_nbr_length(number); i > 0; i--) {
        my_putchar('0' + my_get_digit(number, i));
    }

    return 0;
}
