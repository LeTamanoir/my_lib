/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** clone of sprintf
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_fmt.h"

str_t *my_sprintf(const char *fmt, ...)
{
    va_list ap;
    str_t *buff = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    return buff;
}
