/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates memory and copies the string given in argument in it
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int length = my_strlen(src);
    char *dest;
    dest = malloc(sizeof(char) * (length + 1));
    if (dest == NULL)
        return NULL;

    my_strcpy(dest, src);

    return dest;
}
