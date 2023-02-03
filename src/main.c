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
    SMART vec_int_t *test = (vec_int_t*)vec_create(20, sizeof(int));
    int temp = 0;

    for (size_t i = 0; i < 10; ++i) {
        temp = rand() % 100 * i;
        vec_pushback((vec_t**)&test, &temp);
    }

    vec_sort((vec_t*)test, NULL);

    for (size_t i = 0; i < test->size; ++i) {
        my_printf("%d\n", test->data[i]);
    }

    return 0;
}
