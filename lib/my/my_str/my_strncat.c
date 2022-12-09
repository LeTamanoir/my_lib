/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** concats the two given strings until it reaches nb
*/

#include "my_str.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int str_len = my_strlen(dest);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[str_len + i] = src[i];

    dest[str_len + i] = '\0';

    return dest;
}
