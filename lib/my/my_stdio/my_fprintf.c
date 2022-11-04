/*
** EPITECH PROJECT, 2022
** my_fprintf
** File description:
** fprintf clone
*/

#include <stdio.h>
#include <stdarg.h>

#include "my.h"
#include "core.h"
#include "buffer.h"

int my_fprintf(FILE *stream, const char *format, ...)
{
    va_list ap;
    buffer_t *buffer = create_buffer();

    va_start(ap, format);
    compute_char(ap, buffer, format);
    va_end(ap);

    print_buffer(buffer, stream->_fileno);

    return get_buffer_length(buffer);
}
