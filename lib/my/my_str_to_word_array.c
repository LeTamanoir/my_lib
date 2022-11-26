/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** splits a str into an array of words
*/

#include "my_string.h"
#include "my_stdlib.h"

static int compute_arr_length(char const *str)
{
    int can_inc = 1;
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanum(str[i]) && can_inc) {
            length++;
            can_inc = 0;
        }
        if (!my_isalphanum(str[i])) can_inc = 1;
    }

    return length;
}

static void convert_to_words(char const *str, char **arr)
{
    int len_arr_i = 0;
    int arr_i = 0;
    int inc_last;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanum(str[i]) && str[i + 1] != '\0') {
            len_arr_i++;
            continue;
        }

        inc_last = str[i + 1] == '\0' && my_isalphanum(str[i]);
        if (inc_last) len_arr_i++;
        if (len_arr_i == 0) continue;

        arr[arr_i] = my_calloc(0, sizeof(char) * (len_arr_i + 1));
        my_strncat(arr[arr_i], &(str[(i + inc_last) - len_arr_i]), len_arr_i);
        arr_i++;
        len_arr_i = 0;
    }
}

char **my_str_to_word_array(char const *str)
{
    int length_arr = compute_arr_length(str);
    char **arr = my_calloc(0, sizeof(char *) * (length_arr + 1));

    convert_to_words(str, arr);

    return arr;
}
