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

int main(void)
{
    map_t *map = yaml_parse("./test.yaml");

    vec_void_t *keys = map_get_keys(map);
    char *key;
    yaml_elem_t *temp;

    for (int i = 0; i < keys->base.size; i++) {
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

    vec_void_free(keys, &free);
    map_free(map);

    return 0;
}
