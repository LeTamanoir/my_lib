/*
** EPITECH PROJECT, 2022
** navy
** File description:
** convert
*/

#include "my_str.h"

int str_atoi(str_t const *str)
{
    size_t i = 0;
    int nb = 0;
    int sign = 1;

    if (str->data[i] == '-') {
        sign = -1;
        i++;
    }

    while (i < str->length && my_isnum(str->data[i])) {
        nb = nb * 10 + (str->data[i] - '0');
        i++;
    }

    return nb * sign;
}

double str_atof(str_t const *str)
{
    size_t i = 0;
    double sign = 1;
    double nb = 0;
    double offset = 1;
    int found_dot = 0;

    if (str->data[i] == '-') {
        sign = -1;
        i++;
    }
    while (i < str->length && (my_isnum(str->data[i]) ||
        (str->data[i] == '.' && !found_dot))) {
        if (str->data[i] == '.') {
            found_dot = 1;
        } else {
            nb = nb * 10 + (str->data[i] - '0');
            offset *= ((found_dot) ? 10 : 1);
        }
        i++;
    } return sign * (nb / offset);
}
