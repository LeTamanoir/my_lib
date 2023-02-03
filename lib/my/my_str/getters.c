/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** getters
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_vec.h"
#include "my_obj.h"

vec_str_t *str_split(str_t *str, str_t *delims)
{
    vec_str_t *arr = (vec_str_t*)vec_create(8, sizeof(str_t*));
    obj_set_destructor(arr, (void (*)(void*))&vec_free);
    size_t last_idx = 0;
    str_t *temp = NULL;

    for (size_t i = 0; i <= str->length; i++) {
        if (i == str->length || str_contains(delims, str->data[i])) {
            temp = str_create("");
            str_nadd(&temp, str->data + last_idx, i - last_idx);
            vec_pushback((vec_t**)&arr, &temp);
            last_idx = i + 1;
        }
    }
    return arr;
}
