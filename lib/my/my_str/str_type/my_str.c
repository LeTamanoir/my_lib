/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string class
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_stdio.h"
#include "my_vec.h"

str_t *str_create(char const *init)
{
    str_t *str = malloc(sizeof(str_t));
    int str_len = my_strlen(init);
    int capacity = get_padded_size(str_len);

    str->data = malloc(sizeof(char) * (capacity + 1));
    str->length = str_len;
    str->capacity = capacity;

    my_strcpy(str->data, init);

    return str;
}

void str_free(str_t *str)
{
    free(str->data);
    free(str);
}
