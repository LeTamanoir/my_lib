/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

void str_clear(str_t *str)
{
    if (str->length == 0)
        return;

    for (int i = 0; i < str->length; i++)
        str->data[i] = '\0';
    str->length = 0;
}

void str_resize(str_t *str, int new_len)
{
    int new_cap = get_padded_size(new_len, STR_SIZE);
    char *old = str->data;

    str->data = malloc(sizeof(char) * (new_cap + 1));
    str->data[0] = '\0';

    my_strcat(str->data, old);
    str->capacity = new_cap;
    free(old);
}
