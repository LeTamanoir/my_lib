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

void str_add(str_t *str, char *new)
{
    char *tmp = my_calloc(0, sizeof(char) *
        (my_strlen(str->content) + my_strlen(new) + 1)
    );

    my_strcat(tmp, str->content);
    my_strcat(tmp, new);

    free(str->content);

    str->content = tmp;
    str->length = my_strlen(tmp);
}

void str_nadd(str_t *str, char *new, int n)
{
    char *tmp = my_calloc(0, sizeof(char) *
        (my_strlen(str->content) + n + 1)
    );

    my_strcat(tmp, str->content);
    my_strncat(tmp, new, n);

    free(str->content);

    str->content = tmp;
    str->length = my_strlen(tmp);
}

void str_fadd(str_t *str, char *fmt, ...)
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
    char *tmp = my_calloc(0, sizeof(char) *
        (end - start + 1)
    );

    my_strncat(tmp, &(str->content[start]), end - start);

    free(str->content);

    str->content = tmp;
    str->length = my_strlen(tmp);
}
