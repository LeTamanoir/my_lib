/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** strcmp and strncmp
*/

#include "my_stdlib.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int my_strncmp(char const *s1, char const *s2, size_t n)
{
    while (*s1 && *s2 && n-- && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
