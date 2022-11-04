/*
** EPITECH PROJECT, 2022
** my_sprintf
** File description:
** sprintf clone
*/

#include <stddef.h>
#include <stdarg.h>

#include "my.h"
#include "core.h"
#include "buffer.h"

static void add_buffer_to_str(buffer_t *buffer, char *dest)
{
    while (buffer != NULL) {
        my_strcat(dest, buffer->content);
        buffer = buffer->next;
    }
}

int my_sprintf(char *str, const char *format, ...)
{
    va_list ap;
    buffer_t *buffer = create_buffer();

    va_start(ap, format);
    compute_char(ap, buffer, format);
    va_end(ap);

    add_buffer_to_str(buffer, str);

    return get_buffer_length(buffer);
}
