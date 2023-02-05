/*
** EPITECH PROJECT, 2022
** antman
** File description:
** format utils
*/

#include <stdarg.h>
#include "my_fmt.h"
#include "my_stdlib.h"
#include "my_str.h"

str_t **str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;
    SMART str_t *buff = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    str_stradd(str, buff);
    return str;
}
