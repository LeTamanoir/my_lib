/*
** EPITECH PROJECT, 2023
** my_str
** File description:
** str from type
*/

#include "my_stdlib.h"
#include "my_str.h"

str_t *my_itostr(long int nb)
{
    char *str = my_itoa(nb);
    str_t *new = str_create(str);

    my_free(str);
    return new;
}

str_t *my_ftostr(double nb, int precision)
{
    char *str = my_ftoa(nb, precision);
    str_t *new = str_create(str);

    my_free(str);
    return new;
}
