/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier %c
*/

#include "my.h"

char *compute_spec_c(void *ptr)
{
    char c = *(char *)ptr;
    char *res = my_calloc('\0', sizeof(char) * 2);
    res[0] = c;
    return res;
}
