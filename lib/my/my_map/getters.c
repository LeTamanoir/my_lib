/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** getters
*/

#include "my_vec.h"
#include "my_str.h"
#include "my_stdlib.h"
#include "my_map.h"

void *map_get(map_t *map, char *key)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;

    if (map->elems->data[hash_idx] == NULL)
        return NULL;

    vec_void_t *cands = map->elems->data[hash_idx];

    if (cands->base.size == 1)
        return ((map_elem_t*)cands->data[0])->data;

    for (int i = 0; i < cands->base.size; i++)
        if (my_strcmp(((map_elem_t*)cands->data[i])->key, key) == 0)
            return ((map_elem_t*)cands->data[i])->data;

    return NULL;
}
