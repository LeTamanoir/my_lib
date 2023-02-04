/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** setters
*/

#include "my_map.h"
#include "my_vec.h"
#include "my_obj.h"
#include "my_str.h"

static int overwrite_if_in_map(vec_void_t *cands, str_t *key, void *data)
{
    for (size_t i = 0; i < cands->size; i++) {
        if (str_eq(((map_elem_t*)cands->data[i])->key, key)) {
            ((map_elem_t*)cands->data[i])->data = data;
            return 1;
        }
    }

    return 0;
}

map_elem_t *map_elem_create(str_t *key, void *data)
{
    map_elem_t *elem = obj_alloc(sizeof(map_elem_t));

    if (elem == NULL)
        return NULL;

    obj_set_destructor(elem, (void (*)(void *))&map_elem_free);
    elem->key = str_dup(key);
    elem->data = data;

    return elem;
}

void map_set(map_t *map, str_t *key, void *data)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    map_elem_t *elem = NULL;

    if (map->elems->data[hash_idx] == NULL) {
        vec_void_t *temp = (vec_void_t*)vec_create(10, sizeof(void*));
        vec_insert((vec_t**)&map->elems, &temp, hash_idx);
    }
    if (overwrite_if_in_map(map->elems->data[hash_idx], key, data))
        return;

    elem = map_elem_create(key, data);
    vec_pushback((vec_t**)map->elems->data + hash_idx, &elem);
}

void map_del(map_t *map, str_t *key)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    vec_void_t *cands = NULL;

    if (map->elems->data[hash_idx] == NULL)
        return;

    cands = map->elems->data[hash_idx];

    for (size_t i = 0; i < cands->size; i++) {
        if (str_eq(((map_elem_t*)cands->data[i])->key, key)) {
            map_elem_free((map_elem_t*)cands->data[i]);
            vec_remove((vec_t *)cands, i);
        }
    }
}
