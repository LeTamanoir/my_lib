/*
** EPITECH PROJECT, 2022
** navy
** File description:
** convert
*/

#include "my_stdlib.h"
#include "my_str.h"

long str_toint(str_t const *str)
{
    char *temp = str_tocstr(str);
    long nb = my_atoi(temp);

    free(temp);
    return nb;
}

double str_tofloat(str_t const *str)
{
    char *temp = str_tocstr(str);
    double nb = my_atof(temp);

    free(temp);
    return nb;
}

char *str_tocstr(str_t const *str)
{
    char *cstr = malloc(sizeof(char) * (str->length + 1));

    if (cstr == NULL)
        return NULL;
    my_strncpy(cstr, str->data, str->length);

    return cstr;
}
