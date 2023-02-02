/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** clone of printf
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_fmt.h"

int my_printf(const char *fmt, ...)
{
    va_list ap;
    SMART str_t *buff = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    str_print(buff);

    return buff->length;
}
