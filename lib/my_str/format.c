/*
** EPITECH PROJECT, 2022
** antman
** File description:
** format utils
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_str.h"

str_t **str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;
    char *new = NULL;

    va_start(ap, fmt);
    vasprintf(&new, fmt, ap);
    va_end(ap);

    str_add(str, new);
    free(new);
    return str;
}
