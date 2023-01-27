/*
** EPITECH PROJECT, 2022
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include "my_str.h"
#include "my_stdio.h"
#include "my_vec.h"
#include "my_map.h"
#include "my_yaml.h"
#include "my_fmt.h"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    SMART vec_int_t *arr = (vec_int_t*)vec_create(10, sizeof(int));

    for (int i = 0; i < 10; ++i) {
        vec_push_back((vec_t**)&arr, &i);
    }

    vec_remove((vec_t*)arr, 6);
    vec_remove((vec_t*)arr, 2);
    vec_remove((vec_t*)arr, 3);
    vec_remove((vec_t*)arr, 4);
    vec_remove((vec_t*)arr, 5);

    for (size_t i = 0; i < arr->base.size; ++i) {
        my_printf("arr[%d] = %d\n", i, arr->data[i]);
    }

    return 0;
}
