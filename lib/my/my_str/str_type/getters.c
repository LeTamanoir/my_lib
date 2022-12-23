/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** getters
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"

vec_void_t *str_split(str_t *str, char delim)
{
    vec_void_t *arr = (vec_void_t*)vec_create(10, sizeof(char *));
    int last_idx = 0;
    char *temp = NULL;

    for (int i = 0; str->data[(i > 0) ? (i - 1) : 0] != '\0'; i++) {
        if (str->data[i] == '\0' || str->data[i] == delim) {
            temp = my_calloc(0, sizeof(char) * (i - last_idx + 1));
            my_strncat(temp, str->data + last_idx, i - last_idx);
            vec_push_back((vec_t*)arr, &temp);
            last_idx = i + 1;
        }
    }

    return arr;
}
