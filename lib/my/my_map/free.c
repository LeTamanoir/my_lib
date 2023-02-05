/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** map free
*/

#include "my_obj.h"
#include "my_list.h"
#include "my_map.h"

void map_elem_free(void *ptr)
{
    map_elem_t *elem = (map_elem_t*)ptr;

    obj_free(elem->data);
    obj_free(elem->key);
}

void map_free(void *ptr)
{
    map_t *map = (map_t*)ptr;
    vec_void_t *elem_col = NULL;

    for (size_t i = 0; i < map->capacity; ++i) {
        elem_col = map->elems->data[i];
        if (elem_col == NULL)
            continue;
        obj_free(elem_col);
    }
    obj_free(map->elems);
}
