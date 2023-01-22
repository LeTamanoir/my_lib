/*
** EPITECH PROJECT, 2022
** my_dprintf
** File description:
** dprintf clone
*/

#include <stdarg.h>
#include "my_str.h"
#include "my_fmt.h"

int my_dprintf(int fd, const char *fmt, ...)
{
    va_list ap;
    SMART str_t *buff = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    str_dprint(fd, buff);

    return buff->length;
}
