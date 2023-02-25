/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** getters
*/

#include "my_vec.h"
#include "my_list.h"
#include "my_str.h"
#include "my_map.h"

void *map_get(map_t const *map, str_t const *key)
{
    size_t idx = map_hash_key(key) % map->capacity;
    list_t *cands = map->elems->data[idx];

    if (cands == NULL || cands->size == 0)
        return NULL;

    for (node_t *n = cands->front; n != NULL; n = n->next)
        if (str_eq(((map_elem_t*)n->data)->key, key))
            return ((map_elem_t*)n->data)->data;

    return NULL;
}

vec_str_t *map_get_keys(map_t const *map)
{
    vec_str_t *keys = vec_create(map->capacity, sizeof(str_t *));
    list_t *col = NULL;
    str_t *key = NULL;

    for (size_t i = 0; i < map->capacity; i++) {
        col = map->elems->data[i];
        if (col == NULL || col->size == 0)
            continue;
        for (node_t *n = col->front; n != NULL; n = n->next) {
            key = str_dup(((map_elem_t*)n->data)->key);
            vec_pushback(&keys, &key);
        }
    } return keys;
}
