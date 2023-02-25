/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** map free
*/

#include <stdlib.h>

#include "my_list.h"
#include "my_map.h"

void map_elem_free(map_elem_t *elem)
{
    free(elem->data);
    free(elem->key);
}

void map_free(void *ptr)
{
    map_t *map = (map_t*)ptr;
    list_t *col = NULL;

    for (size_t i = 0; i < map->capacity; ++i) {
        col = map->elems->data[i];
        if (col == NULL)
            continue;
        list_free_fn(col, (void (*)(void*))&map_elem_free);
    }
    free(map->elems);
    free(map);
}
