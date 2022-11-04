/*
** EPITECH PROJECT, 2022
** my_dprintf
** File description:
** dprintf clone
*/

#include <stdarg.h>

#include "my.h"
#include "core.h"
#include "buffer.h"

int my_dprintf(int fd, const char * format, ...)
{
    va_list ap;
    buffer_t *buffer = create_buffer();

    va_start(ap, format);
    compute_char(ap, buffer, format);
    va_end(ap);

    print_buffer(buffer, fd);

    return get_buffer_length(buffer);
}
