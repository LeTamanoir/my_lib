/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** setters
*/

#include "my_map.h"
#include "my_vec.h"
#include "my_str.h"

void map_set(map_t *map, char *key, void *data)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    map_elem_t *elem = malloc(sizeof(map_elem_t));
    elem->key = my_strdup(key);
    elem->data = data;

    if (map->elems->data[hash_idx] == NULL) {
        vec_void_t *temp = (vec_void_t*)vec_create(10, sizeof(void*));
        vec_insert((vec_t**)&map->elems, &temp, hash_idx);
    }

    vec_push_back((vec_t**)map->elems->data + hash_idx, &elem);
}
