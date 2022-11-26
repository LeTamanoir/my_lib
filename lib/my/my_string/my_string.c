/*
** EPITECH PROJECT, 2022
** my_string.c
** File description:
** string class
*/

#include <stdarg.h>

#include "my_string.h"
#include "my_stdlib.h"
#include "my_stdio.h"

static void string_add(string_t *this, char *new)
{
    char *tmp = my_calloc(0, sizeof(char) *
        (my_strlen(this->content) + my_strlen(new) + 1)
    );

    my_strcat(tmp, this->content);
    my_strcat(tmp, new);

    free(this->content);

    this->content = tmp;
}

static void string_fadd(string_t *this, char *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, ap);
    va_end(ap);

    (*this->add)(this, dest);

    free(dest);
}

string_t *string_create(char *init)
{
    string_t *string = malloc(sizeof(string_t));

    string->content = my_strdup(init);

    string->add = &string_add;
    string->fadd = &string_fadd;

    return string;
}
