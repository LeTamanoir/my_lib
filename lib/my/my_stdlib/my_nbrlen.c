/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** my_nbr_len
*/

int my_nbrlen(long int nb, int base)
{
    int nb_digit = 0;

    if (nb == 0)
        return 1;

    while (nb) {
        nb_digit++;
        nb /= base;
    }

    return nb_digit;
}
