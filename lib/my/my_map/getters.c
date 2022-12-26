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

vec_void_t *map_get_keys(map_t *map)
{
    vec_void_t *keys = (vec_void_t*)vec_create(map->capacity, sizeof(char*));
    vec_void_t *elem_col = NULL;
    char *temp = NULL;

    for (int i = 0; i < map->elems->base.capacity; i++) {
        elem_col = map->elems->data[i];
        if (elem_col == NULL)
            continue;
        for (int j = 0; j < elem_col->base.size; j++) {
            temp = my_strdup(((map_elem_t*)elem_col->data[j])->key);
            vec_push_back((vec_t*)keys, &temp);
        }
    }

    return keys;
}
