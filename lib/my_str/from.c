/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** str from type
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_str.h"

str_t *my_itostr(long int nb)
{
    char *tmp = NULL;
    asprintf(&tmp, "%ld", nb);
    str_t *new = str_create(tmp);
    free(tmp);

    return new;
}

str_t *my_ftostr(double nb, int precision)
{
    char *tmp = NULL;
    asprintf(&tmp, "%.*f", precision, nb);
    str_t *new = str_create(tmp);
    free(tmp);

    return new;
}
