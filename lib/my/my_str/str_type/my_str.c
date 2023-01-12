/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** string class
*/

#include "my_str.h"
#include "my_stdlib.h"
#include "my_vec.h"

str_t *str_create(char const *init)
{
    size_t str_len = my_strlen(init);
    size_t capacity = get_padded_size(str_len);
    str_t *str = malloc(sizeof(str_t) + sizeof(char) * (capacity + 1));

    if (str == NULL)
        return NULL;

    str->length = str_len;
    str->capacity = capacity;

    my_memcpy(str->data, init, sizeof(char) * str_len);
    str->data[str->length] = '\0';

    return str;
}
