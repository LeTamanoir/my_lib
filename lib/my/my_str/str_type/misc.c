/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** misc
*/

#include <unistd.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

void str_clear(str_t *str)
{
    if (str->length == 0)
        return;

    for (size_t i = 0; i < str->length; i++)
        str->data[i] = '\0';
    str->length = 0;
}

void str_resize(str_t **str, size_t new_len)
{
    size_t new_cap = get_padded_size(new_len);
    str_t *old = *str;
    *str = malloc(sizeof(str_t) + sizeof(char) * (new_cap + 1));

    my_strcpy((*str)->data, old->data);
    (*str)->length = old->length;
    (*str)->capacity = new_cap;

    free(old);
}

void str_print(str_t *str)
{
    write(1, str->data, str->length);
}
