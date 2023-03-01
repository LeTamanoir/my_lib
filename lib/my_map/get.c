/*
** EPITECH PROJECT, 2023
** my_map
** File description:
** getters
*/

#include "my_vec.h"
#include "my_list.h"
#include "my_str.h"
#include "my_obj.h"
#include "my_stdlib.h"
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
    vec_str_t *keys = vec_create(map->capacity, sizeof(str_t*));
    list_t *col = NULL;
    str_t *key = NULL;

    obj_get_meta(keys)->destructor = &vec_free;
    for (size_t i = 0; i < map->capacity; i++) {
        col = map->elems->data[i];
        if (col == NULL)
            continue;
        for (node_t *temp = col->front; temp != NULL; temp = temp->next) {
            key = str_dup(((map_elem_t*)temp->data)->key);
            vec_pushback(&keys, &key);
        }
    } return keys;
}
