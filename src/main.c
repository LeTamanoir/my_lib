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

void print_number(void *vec_item, void *ext_data)
{
    (void)ext_data;
    my_printf("%d\t", *(int*)vec_item);
}

int main(void)
{
    vec_int_t *test = (vec_int_t*)vec_create(10, sizeof(int));

    time_t t;
    srand(time(&t));

    for (int i = 0; i < 100; i++) {
        int temp = rand() % 100000;
        vec_push_back((vec_t**)&test, &temp);
    }

    vec_for_each((vec_t*)test, &print_number, NULL);
    my_puts("\n=======\n");

    vec_sort((vec_t*)test, NULL);

    vec_for_each((vec_t*)test, &print_number, NULL);
    my_puts("\n=======\n");

    free(test);

    map_t *map = yaml_parse("./test.yaml");

    vec_void_t *keys = map_get_keys(map);
    char *key;
    yaml_elem_t *temp;

    for (size_t i = 0; i < keys->base.size; i++) {
        key = keys->data[i];
        temp = yaml_get(map, key);

        switch (temp->type) {
            case YAML_INT:
                my_printf("map[%s] = %i\n", key, *(int*)temp->data);
                break;
            case YAML_DOUBLE:
                my_printf("map[%s] = %f\n", key, *(double*)temp->data);
                break;
            case YAML_STR:
                my_printf("map[%s] = %s\n", key, (char*)temp->data);
                break;
        }
    }

    vec_free((vec_t*)keys, &free);
    map_free(map);


    return 0;
}
