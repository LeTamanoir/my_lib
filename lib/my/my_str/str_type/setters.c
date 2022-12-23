/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string setters
*/

#include <stdarg.h>

#include "my_stdlib.h"
#include "my_stdio.h"
#include "my_str.h"
#include "my_vec.h"

void str_add(str_t *str, char const *new)
{
    int new_len = my_strlen(new);

    if (str->length + new_len >= str->capacity)
        str_resize(str, str->length + new_len);

    my_strcat(str->data, new);
    str->length += new_len;
}

void str_nadd(str_t *str, char const *new, int n)
{
    if (str->length + n >= str->capacity)
        str_resize(str, str->length + n);

    my_strncat(str->data, new, n);
    str->length += n;
}

void str_fadd(str_t *str, char const *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    str_add(str, dest);

    free(dest);
}

void str_slice(str_t *str, int start, int end)
{
    int i;

    for (i = 0; i < end - start; i++) {
        str->data[i] = str->data[start + i];
    }

    str->data[i] = '\0';
    str->length = end - start;
}
