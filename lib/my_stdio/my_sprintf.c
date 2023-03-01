/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** clone of sprintf
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_fmt.h"

char *my_sprintf(const char *fmt, ...)
{
    va_list ap;
    SMART str_t *buff = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    return str_tocstr(buff);
}
