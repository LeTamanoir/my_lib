/*
** EPITECH PROJECT, 2022
** my_nbr_length.c
** File description:
** returns the length of a number
*/

int my_nbr_length(long long nb)
{
    int nb_digit = 0;

    while (nb) {
        nb = nb / 10;
        nb_digit++;
    }

    return nb_digit;
}
