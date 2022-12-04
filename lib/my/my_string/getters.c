/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** getters
*/

#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_string.h"

static int count_elems(char *content, char delim)
{
    int elems = 0;
    int last_delim = 0;

    for (int i = 0; content[i] != '\0'; i++) {
        if ((content[i] == delim || content[i + 1] == '\0') &&
            last_delim + 1 != i) {
            elems++;
        }
        if (content[i] == delim) {
            last_delim = i;
        }
    }
    return elems;
}

char **string_split(string_t *this, char delim)
{
    int elems = count_elems(this->content, delim);
    char **arr = my_calloc(0, sizeof(char *) * (elems + 1));
    int last_delim = -1;
    int elem_len = 0;
    int arr_i = 0;

    for (int i = 0; this->content[i] != '\0'; i++) {
        if ((this->content[i] == delim || this->content[i + 1] == '\0') &&
            last_delim + 1 != i) {
            elem_len = i - last_delim - (this->content[i + 1] != '\0');
            arr[arr_i] = my_calloc(0, sizeof(char) * (elem_len + 1));
            my_strncat(arr[arr_i], &(this->content[last_delim + 1]), elem_len);
            arr_i++;
        }
        if (this->content[i] == delim) {
            last_delim = i;
        }
    }
    return arr;
}
