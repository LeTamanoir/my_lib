/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** map implementation
*/

#include "my_map.h"
#include "my_vec.h"
#include "my_str.h"

// from some gourou lol

static unsigned int hash_key(char *key)
{
    unsigned h = 0x811c9dc5;

    for (int i = 0; key[i] != '\0'; i++) {
        h = (h ^ key[i]) * 0x01000193;
    }

    return h;
}

void map_set(map_t *map, char *key, void *data)
{
    unsigned int hash_idx = hash_key(key) % map->capacity;
    map_elem_t *elem = malloc(sizeof(map_elem_t));
    elem->key = my_strdup(key);
    elem->data = data;

    if (map->elems->data[hash_idx] == NULL) {
        vec_void_t *temp = (vec_void_t*)vec_create(1, sizeof(void*));
        vec_insert((vec_t*)map->elems, &temp, hash_idx);
    }

    vec_push_back((vec_t*)map->elems->data[hash_idx], &elem);
}

void *map_get(map_t *map, char *key)
{
    unsigned int hash_idx = hash_key(key) % map->capacity;

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

map_t *map_create(int capacity)
{
    map_t *map = malloc(sizeof(map_t));

    map->capacity = capacity;
    map->elems = (vec_void_t*)vec_create(capacity, sizeof(void*));

    return map;
}
