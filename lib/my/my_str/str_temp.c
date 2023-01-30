/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** str_temp
*/

#include "my_str.h"

str_t *str_temp(char const *init)
{
    return str_ntemp(init, my_strlen(init));
}

str_t *str_ntemp(char const *init, size_t n)
{
    static struct {
        size_t length;
        size_t capacity;
        char data[MAX_SWAP_SIZE];
    } temp_str = {0};

    temp_str.capacity = MAX_SWAP_SIZE;
    temp_str.length = n;
    my_memcpy(temp_str.data, init, n);

    return (str_t*)&temp_str;
}

