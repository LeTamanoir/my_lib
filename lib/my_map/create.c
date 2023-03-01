/*
** EPITECH PROJECT, 2023
** my_map
** File description:
** map implementation
*/

#include "my_map.h"
#include "my_list.h"
#include "my_obj.h"

map_t *map_create(size_t capacity)
{
    map_t *map = obj_alloc(sizeof(map_t));

    if (map == NULL)
        return NULL;

    obj_get_meta(map)->destructor = &map_free;
    map->capacity = capacity;
    map->elems = vec_create(capacity, sizeof(node_t *));
    my_memset(map->elems->data, 0, sizeof(void *) * map->capacity);

    return map;
}
