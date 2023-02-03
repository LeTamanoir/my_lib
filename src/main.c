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

int main(void)
{
    SMART vec_int_t *test = (vec_int_t*)vec_create(20, sizeof(int));

    for (size_t i = 10; i < 20; ++i)
        vec_push_back((vec_t**)&test, &i);

    for (size_t i = 0; i < test->size; ++i)
        my_printf("test[%d] = %d\n", i, test->data[i]);

    return 0;
}
