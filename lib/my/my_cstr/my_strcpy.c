/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** strcpy and strncpy
*/

#include "my_cstr.h"

void my_strcpy(char *dest, char const *src)
{
    size_t i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];

    dest[i] = '\0';
}

char *my_strncpy(char *dest, char const *src, size_t n)
{
    size_t i = 0;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];

    for (; i <= n; i++)
        dest[i] = '\0';

    return dest;
}
