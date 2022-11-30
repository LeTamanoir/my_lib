/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** string class
*/

#include "my_string.h"
#include "my_stdlib.h"
#include "my_stdio.h"

#include "./include/setters.h"

string_t *string_create(char *init)
{
    string_t *string = malloc(sizeof(string_t));

    string->content = my_strdup(init);
    string->length = my_strlen(init);

    string->add = &string_add;
    string->nadd = &string_nadd;
    string->fadd = &string_fadd;
    string->slice = &string_slice;

    return string;
}

void string_free(string_t *string)
{
    free(string->content);
    free(string);
}
