/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** my_memcmp
*/

#include "my_stdlib.h"
#include "my_str.h"

int my_memcmp(void const *m1, void const *m2, size_t el)
{
    char *m1_char = (char *)m1;
    char *m2_char = (char *)m2;

    return my_strncmp(m1_char, m2_char, el);
}
