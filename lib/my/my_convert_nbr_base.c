/*
** EPITECH PROJECT, 2022
** convert_base.c
** File description:
** displays the content of an array of words
*/

#include "my_string.h"
#include "my_base.h"

static int get_new_nbr_length(int nbr, int base)
{
    int new_length = 0;

    while (nbr != 0) {
        new_length++;
        nbr = nbr / base;
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

static char *my_putnbr_base_into_str(int nbr, char const *base)
{
    int base_len = my_strlen(base);
    if (nbr == 0) return "0";

    int new_length = get_new_nbr_length(nbr, base_len);
    if (nbr < 0) new_length++;
    int utils[] = { new_length - 1, nbr, base_len };
    char *nbr_pointer;
    nbr_pointer = malloc(sizeof(char) * (new_length + 1));
    nbr_pointer[new_length] = '\0';

    if (nbr < 0) {
        nbr_pointer[0] = '-';
        utils[1] = -nbr;
    }

    compute_number(nbr_pointer, base, utils);

    return nbr_pointer;
}

char *my_convert_base(
    char const *nbr,
    char const *base_from,
    char const *base_to
)
{
    if (my_strlen(base_from) <= 1 || my_strlen(base_to) <= 1) return '\0';

    int nbr_from_base = my_getnbr_base(nbr, base_from);
    char *nbr_to_base = my_putnbr_base_into_str(nbr_from_base, base_to);

    return nbr_to_base;
}
