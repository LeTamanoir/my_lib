/*
** EPITECH PROJECT, 2022
** navy
** File description:
** convert
*/

#include "my_stdlib.h"
#include "my_str.h"

long int str_toint(str_t *str)
{
    char *tmp = str_tocstr(str);
    long int nb = my_atoi(tmp);

    my_free(tmp);
    return nb;
}

double str_tofloat(str_t *str)
{
    char *tmp = str_tocstr(str);
    double nb = my_atof(tmp);

    my_free(tmp);
    return nb;
}

char *str_tocstr(str_t *str)
{
    char *new = my_malloc(sizeof(char) * (str->length + 1));
    my_memcpy(new, str->data, str->length);
    new[str->length] = '\0';

    return new;
}
