/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** getters
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_str.h"

static int count_elems(char *content, char delim)
{
    int can_inc = 1;
    int length = 0;

    for (int i = 0; content[i] != '\0'; i++) {
        if (content[i] != delim && can_inc) {
            length++;
            can_inc = 0;
        }
        if (content[i] == delim) can_inc = 1;
    }

    return length;
}

char **str_split(str_t *str, char delim)
{
    int elems_len = count_elems(str->content, delim);
    char **arr = my_calloc(0, sizeof(char *) * (elems_len + 1));
    int len_arr_i = 0;
    int arr_i = 0;
    int inc_last;
    char *ct = str->content;

    for (int i = 0; ct[i] != '\0'; i++) {
        if (ct[i] != delim && ct[i + 1] != '\0') {
            len_arr_i++;
            continue;
        }
        inc_last = ct[i + 1] == '\0' && my_isalphanum(ct[i]);
        len_arr_i += (inc_last) ? 1 : 0;
        if (len_arr_i == 0) continue;
        arr[arr_i] = my_calloc(0, sizeof(char) * (len_arr_i + 1));
        my_strncat(arr[arr_i++], &(ct[(i + inc_last) - len_arr_i]), len_arr_i);
        len_arr_i = 0;
    }
    return arr;
}
