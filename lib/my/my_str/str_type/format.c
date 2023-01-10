/*
** EPITECH PROJECT, 2022
** antman
** File description:
** format utils
*/

#include <stdarg.h>

#include "my_stdio.h"
#include "my_str.h"

str_t **str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    str_add(str, dest);

    free(dest);

    return str;
}
