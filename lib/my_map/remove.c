/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** remove elem from map
*/

#include "my_list.h"
#include "my_str.h"
#include "my_map.h"

void map_del(map_t *map, str_t const *key)
{
    size_t idx = map_hash_key(key) % map->capacity;
    list_t *cands = map->elems->data[idx];

    if (cands == NULL || cands->size == 0)
        return;

    for (node_t *n = cands->front; n != NULL; n = n->next) {
        if (str_eq(((map_elem_t *)n->data)->key, key)) {
            list_remove(cands, n);
            return;
        }
    }
}
