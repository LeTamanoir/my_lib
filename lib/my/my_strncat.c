/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** concats the two given strings until it reaches nb
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int str_len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[str_len + i] = src[i];

    dest[str_len + i] = '\0';

    return dest;
}
