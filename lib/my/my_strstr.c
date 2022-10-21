/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** finds first occurence of to_find in str
*/

#include <stddef.h>

static char *find_str(char *str, const char *to_find, int idx, int *find_idx)
{
    if (str[idx] == to_find[*find_idx]) {
        if (to_find[*find_idx + 1] == '\0') {
            return &(str[idx - *find_idx]);
        }
        (*find_idx)++;
    } else {
        *find_idx = 0;
    }

    return NULL;
}

char *my_strstr(char *str, char const *to_find)
{
    int index = 0;
    int find_index = 0;

    if (to_find[0] == '\0')
        return str;

    while (str[index] != '\0') {
        char *first_occ = find_str(str, to_find, index, &find_index);

        if (first_occ != NULL)
            return first_occ;

        index++;
    }

    return '\0';
}
