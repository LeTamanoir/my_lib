/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** strcat and strncat
*/

#include "my_cstr.h"

char *my_strcat(char *dest, char const *src)
{
    size_t str_len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[str_len + i] = src[i];

    dest[str_len + i] = '\0';

    return dest;
}

char *my_strncat(char *dest, char const *src, size_t n)
{
    size_t dest_len = my_strlen(dest);
    size_t i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}
