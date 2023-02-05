/*
** EPITECH PROJECT, 2022
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include "my_str.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"
#include "my_map.h"
#include "my_yaml.h"
#include "my_fmt.h"
#include "my_obj.h"

int main(void)
{
    SMART vec_str_t *vec = vec_create(1, sizeof(str_t *));

    for (size_t i = 0; i < 10; ++i)
        vec_pushback(&vec, &(str_t*){str_create("Hello")});

    for (size_t i = 0; i < vec->size; ++i)
        str_println(vec->data[i]);

    return 0;
}

