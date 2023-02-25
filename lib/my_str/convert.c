/*
** EPITECH PROJECT, 2022
** navy
** File description:
** convert
*/

#include <stdlib.h>
#include <string.h>

#include "my_str.h"

long int str_toint(str_t *str)
{
    char *tmp = str_tocstr(str);
    long int nb = atol(tmp);
    free(tmp);
    return nb;
}

double str_tofloat(str_t *str)
{
    char *tmp = str_tocstr(str);
    double nb = atof(tmp);
    free(tmp);
    return nb;
}

char *str_tocstr(str_t *str)
{
    char *new = malloc(sizeof(char) * (str->length + 1));
    memcpy(new, str->data, str->length);
    new[str->length] = '\0';

    return new;
}
