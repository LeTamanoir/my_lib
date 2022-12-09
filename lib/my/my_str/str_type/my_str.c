/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string class
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_stdio.h"

str_t *str_create(char *init)
{
    str_t *str = malloc(sizeof(str_t));

    str->content = my_strdup(init);
    str->length = my_strlen(init);

    return str;
}

void str_free(str_t *str)
{
    free(str->content);
    free(str);
}
