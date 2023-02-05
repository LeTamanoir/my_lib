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
    SMART map_t *map = map_create(100);
    str_t *str = NULL;

    for (size_t i = 0; i < 10; ++i) {
        str = my_itostr(i + 10);
        map_set(map, str, str_dup(str));
        obj_free(str);
    }

    SMART vec_str_t *keys = map_get_keys(map);

    for (size_t i = 0; i < keys->size; ++i) {
        my_printf("%S: %S\n", keys->data[i], map_get(map, keys->data[i]));
    }

    return 0;
}
