/*
** EPITECH PROJECT, 2022
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

void *map_get(map_t *map, str_t *key)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    list_t *cands = NULL;
    node_t *temp = NULL;

    if ((cands = map->elems->data[hash_idx]) == NULL)
        return NULL;
    temp = cands->front;
    while (temp != NULL) {
        if (str_eq(((map_elem_t*)temp->data)->key, key))
            return ((map_elem_t*)temp->data)->data;
        temp = temp->next;
    }
    return NULL;
}

vec_str_t *map_get_keys(map_t *map)
{
    vec_str_t *keys = vec_create(map->capacity, sizeof(str_t*));
    list_t *elem_col = NULL;
    node_t *temp = NULL;
    str_t *key = NULL;

    obj_get_meta(keys)->destructor = &vec_free;
    for (size_t i = 0; i < map->capacity; i++) {
        elem_col = map->elems->data[i];
        if (elem_col == NULL)
            continue;
        temp = elem_col->front;
        while (temp != NULL) {
            key = str_dup(((map_elem_t*)temp->data)->key);
            vec_pushback(&keys, &key);
            temp = temp->next;
        }
    } return keys;
}
