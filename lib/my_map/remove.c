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
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    list_t *cands = NULL;
    map_elem_t *elem = NULL;

    if ((cands = map->elems->data[hash_idx]) == NULL)
        return;

    for (node_t *temp = cands->front; temp != NULL; temp = temp->next) {
        elem = temp->data;
        if (str_eq(elem->key, key)) {
            list_remove(cands, temp);
            return;
        }
    }
}
