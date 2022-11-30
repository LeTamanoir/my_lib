/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** string setters
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_stdio.h"

#include "my_string.h"

void string_add(string_t *this, char *new)
{
    char *tmp = my_calloc(0, sizeof(char) *
        (my_strlen(this->content) + my_strlen(new) + 1)
    );

    my_strcat(tmp, this->content);
    my_strcat(tmp, new);

    free(this->content);

    this->content = tmp;
    this->length = my_strlen(tmp);
}

void string_nadd(string_t *this, char *new, int n)
{
    char *tmp = my_calloc(0, sizeof(char) *
        (my_strlen(this->content) + n + 1)
    );

    my_strcat(tmp, this->content);
    my_strncat(tmp, new, n);

    free(this->content);

    this->content = tmp;
    this->length = my_strlen(tmp);
}

void string_fadd(string_t *this, char *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    (*this->add)(this, dest);

    free(dest);
}

void string_slice(string_t *this, int start, int end)
{
    char *tmp = my_calloc(0, sizeof(char) *
        (end - start + 1)
    );

    my_strncat(tmp, &(this->content[start]), end - start);

    free(this->content);

    this->content = tmp;
    this->length = my_strlen(tmp);
}
