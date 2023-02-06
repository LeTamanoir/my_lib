/*
** EPITECH PROJECT, 2022
** navy
** File description:
** convert
*/

#include "my_stdlib.h"
#include "my_str.h"

long int str_toint(str_t **str)
{
    long int nb = my_atoi(str_tocstr(str));

    return nb;
}

double str_tofloat(str_t **str)
{
    double nb = my_atof(str_tocstr(str));

    return nb;
}

char *str_tocstr(str_t **str)
{
    str_cadd(str, '\0');

    return (*str)->data;
}
