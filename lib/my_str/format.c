/*
** EPITECH PROJECT, 2022
** antman
** File description:
** format utils
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_str.h"

str_t **str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    size_t len = vsnprintf(NULL, 0, fmt, ap);
    va_end(ap);

    str_resize(str, (*str)->length + len + 1);

    va_start(ap, fmt);
    vsnprintf((*str)->data + (*str)->length, len, fmt, ap);
    va_end(ap);
    (*str)->length += len;

    return str;
}
