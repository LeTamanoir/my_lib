/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** splits a str into an array of words
*/

#include <stdlib.h>
#include "my.h"

static void populate_word(
    char const *str, char *arr_at_i,
    int str_i, int length
)
{
    for (int i = 0; i < length; i++) {
        arr_at_i[i] = str[(str_i - length) + i];
    }
    arr_at_i[length] = '\0';
}

static int compute_arr_length(char const *str)
{
    int can_inc = 1;
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isalphanum(str, i) && can_inc) {
            length++;
            can_inc = 0;
        }
        if (!my_isalphanum(str, i)) can_inc = 1;
    }

    return length;
}

static void convert_to_words(char const *str, char **arr)
{
    int length_arr_i = 0;
    int arr_i = 0;

    for (int i = 0; str[i] != '\0'; i++) {

        if (my_isalphanum(str, i) && str[i + 1] != '\0') {
            length_arr_i++;
            continue;
        }
        int include_last = str[i + 1] == '\0' && my_isalphanum(str, i);
        if (include_last) length_arr_i++;
        if (length_arr_i == 0) continue;

        arr[arr_i] = malloc(sizeof(char) * (length_arr_i + 1));
        populate_word(str, arr[arr_i], i + include_last, length_arr_i);
        arr_i++;
        length_arr_i = 0;
    }
}

char **my_str_to_word_array(char const *str)
{
    int length_arr = compute_arr_length(str);
    char **arr;
    arr = malloc(sizeof(arr) * (length_arr + 1));
    if (arr == NULL)
        return NULL;

    convert_to_words(str, arr);
    arr[length_arr] = 0;
    return arr;
}
