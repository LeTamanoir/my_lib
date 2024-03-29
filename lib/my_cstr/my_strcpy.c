/*
** EPITECH PROJECT, 2023
** my_str
** File description:
** strcpy and strncpy
*/

#include "my_cstr.h"

char *my_strcpy(char *dest, char const *src)
{
    char *start = dest;

    while (*src)
        *dest++ = *src++;
    *dest = '\0';

    return start;
}

char *my_strncpy(char *dest, char const *src, size_t n)
{
    char *start = dest;

    while (n-- && *src)
        *dest++ = *src++;
    while (n-- > 0)
        *dest++ = '\0';

    return start;
}
