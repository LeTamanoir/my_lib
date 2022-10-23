/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** prints number into a given base
*/

#include "my.h"

static int get_new_nbr_length(int nbr, int base)
{
    int new_length = 0;

    while (nbr != 0) {
        nbr = nbr / base;
        new_length++;
    }

    return new_length;
}

static void compute_number(char *arr, char const *base, int *utils)
{
    int len = utils[0];
    int nbr = utils[1];
    int base_len = utils[2];

    while (nbr != 0) {
        arr[len] = base[nbr % base_len];
        nbr = nbr / base_len;
        len--;
    }
}

static void populate_array(char *arr, int new_length)
{
    for (int i = 0; i < new_length; i++) arr[i] = ' ';
    arr[new_length] = '\0';
}

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen(base);
    if (base_len <= 1) return 0;
    if (nbr == 0) {
        my_putchar(base[0]);
        return 1;
    }
    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    int new_length = get_new_nbr_length(nbr, base_len);
    int utils[] = { new_length - 1, nbr, base_len };
    char arr[new_length + 1];

    populate_array(arr, new_length);
    compute_number(arr, base, utils);
    for (int i = 0; arr[i] != '\0'; i++)
        my_putchar(arr[i]);
    return 1;
}
