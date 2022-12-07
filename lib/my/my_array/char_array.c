/*
** EPITECH PROJECT, 2022
** my_array
** File description:
** array utils
*/

#include "my_stdlib.h"

int char_arr_len(char **arr)
{
    int len = 0;

    while (*arr++ != NULL) {
        len++;
    }

    return len;
}

void char_arr_free(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }

    free(arr);
}
