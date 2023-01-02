/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string setters
*/

#include <stdarg.h>

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

void str_add(str_t **str, char const *new)
{
    int new_len = my_strlen(new);

    if ((*str)->length + new_len >= (*str)->capacity)
        str_resize(str, (*str)->length + new_len);

    my_strcpy((*str)->data + (*str)->length, new);
    (*str)->length += new_len;
}

void str_nadd(str_t **str, char const *new, size_t n)
{
    if ((*str)->length + n >= (*str)->capacity)
        str_resize(str, (*str)->length + n);

    my_strncpy((*str)->data + (*str)->length, new, n);
    (*str)->length += n;
}

void str_fadd(str_t **str, char const *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    str_add(str, dest);

    free(dest);
}

void str_slice(str_t *str, size_t start, size_t end)
{
    size_t i;

    for (i = 0; i < end - start; i++)
        str->data[i] = str->data[start + i];

    str->data[i] = '\0';
    str->length = end - start;
}

void str_trim(str_t *str)
{
    size_t start = 0;
    size_t end = str->length - 1;

    while (str->data[start] == ' ')
        start++;
    while (str->data[end] == ' ')
        end--;

    str_slice(str, start, end + 1);
}
