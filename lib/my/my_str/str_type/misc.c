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

str_t **str_clear(str_t **str)
{
    if ((*str)->length == 0)
        return str;

    for (size_t i = 0; i < (*str)->length; i++)
        (*str)->data[i] = '\0';
    (*str)->length = 0;

    return str;
}

str_t **str_resize(str_t **str, size_t new_len)
{
    size_t new_cap = get_padded_size(new_len);
    str_t *old = *str;
    *str = malloc(sizeof(str_t) + sizeof(char) * (new_cap + 1));

    my_memcpy((*str)->data, old->data, old->length);
    (*str)->length = old->length;
    (*str)->capacity = new_cap;

    free(old);

    return str;
}

void str_print(str_t *str)
{
    write(1, str->data, str->length);
}

str_t **str_trim(str_t **str)
{
    size_t start = 0;
    size_t end = (*str)->length - 1;

    while ((*str)->data[start] == ' ')
        start++;
    while ((*str)->data[end] == ' ')
        end--;

    str_slice(str, start, end + 1);

    return str;
}

str_t **str_slice(str_t **str, size_t start, size_t end)
{
    size_t i;

    for (i = 0; i < end - start; i++)
        (*str)->data[i] = (*str)->data[start + i];

    (*str)->data[i] = '\0';
    (*str)->length = end - start;

    return str;
}
