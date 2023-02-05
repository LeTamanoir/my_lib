/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** remove elem from map
*/

#include "my_list.h"
#include "my_str.h"
#include "my_map.h"

void map_del(map_t *map, str_t *key)
{
    unsigned int hash_idx = map_hash_key(key) % map->capacity;
    list_t *cands = NULL;
    node_t *temp = NULL;
    map_elem_t *elem = NULL;

    if ((cands = map->elems->data[hash_idx]) == NULL)
        return;

    temp = cands->front;
    while (temp != NULL) {
        elem = temp->data;
        if (str_eq(elem->key, key)) {
            map_elem_free(elem);
            list_remove(cands, temp);
            return;
        }
        temp = temp->next;
    }
}
