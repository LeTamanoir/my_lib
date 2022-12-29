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

#include <time.h>



int main(void)
{

    // vec_int_t *test = (vec_int_t*)vec_create(10, sizeof(int));

    // time_t t;
    // srand(time(&t));

    // for (int i = 0; i < 1000000; i++) {
    //     int temp = rand() % 100000;
    //     vec_push_back((vec_t*)test, &temp);
    // }

    // my_puts("flag 1\n");
    // vec_sort((vec_t*)test, NULL);
    // my_puts("flag 2\n");

    // vec_free((vec_t*)test);

    // map_t *map = yaml_parse("./test.yaml");

    // vec_void_t *keys = map_get_keys(map);
    // char *key;
    // yaml_elem_t *temp;

    // for (int i = 0; i < keys->base.size; i++) {
    //     key = keys->data[i];
    //     temp = yaml_get(map, key);

    //     switch (temp->type) {
    //         case YAML_INT:
    //             my_printf("map[%s] = %i\n", key, *(int*)temp->data);
    //             break;
    //         case YAML_DOUBLE:
    //             my_printf("map[%s] = %f\n", key, *(double*)temp->data);
    //             break;
    //         case YAML_STR:
    //             my_printf("map[%s] = %s\n", key, (char*)temp->data);
    //             break;
    //     }
    // }

    // vec_void_free(keys, &free);
    // map_free(map);

    // my_printf("a: %d\n", my_atoi("12313"));
    // my_printf("a: %d\n", my_atoi("-21312313"));
    // my_printf("a: %d\n", my_atoi("-21d312313"));
    // my_printf("a: %d\n", my_atoi("a-21d312313"));

    // my_printf("a: %f\n", my_atof("21.312313"));
    // my_printf("a: %f\n", my_atof("-21.312313"));

    // my_printf("a: %s\n", my_itoa(-12345789));
    // my_printf("a: %s\n", my_itoa(-12313));

    return 0;
}
