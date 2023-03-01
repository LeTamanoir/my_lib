/*
** EPITECH PROJECT, 2023
** my_map
** File description:
** setters
*/

#include "my_map.h"
#include "my_list.h"
#include "my_vec.h"
#include "my_obj.h"
#include "my_str.h"

static int overwrite_if_in_map(list_t *cands, str_t const *key, void *data)
{
    map_elem_t *elem = NULL;

    for (node_t *temp = cands->front; temp != NULL; temp = temp->next) {
        elem = temp->data;
        if (str_eq(elem->key, key)) {
            elem->data = data;
            return 1;
        }
    }
    return 0;
}

map_elem_t *map_elem_create(str_t const *key, void *data)
{
    map_elem_t *elem = obj_alloc(sizeof(map_elem_t));

    if (elem == NULL)
        return NULL;

    obj_get_meta(elem)->destructor = &map_elem_free;
    elem->key = str_dup(key);
    elem->data = data;

    return elem;
}

void map_set(map_t *map, str_t const *key, void *data)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    map_elem_t *elem = NULL;
    list_t *temp = NULL;

    if (map->elems->data[hash_idx] == NULL) {
        temp = list_create();
        vec_insert(&map->elems, &temp, hash_idx);
    }
    if (overwrite_if_in_map(map->elems->data[hash_idx], key, data))
        return;

    elem = map_elem_create(key, data);
    list_pushback(map->elems->data[hash_idx], elem);
}
