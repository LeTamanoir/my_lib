/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** map implementation
*/

#ifndef INCLUDE_MY_MAP_
    #define INCLUDE_MY_MAP_
    #include "my_vec.h"


typedef struct map_elem_s {
    char *key;
    void *data;
} map_elem_t;

typedef struct map_s {
    vec_void_t *elems;
    int capacity;
} map_t;

void map_set(map_t *map, char *key, void *data);
void *map_get(map_t *map, char *key);
map_t *map_create(int capacity);
void map_free(map_t *map);
void map_elem_free(void *elem);
unsigned int map_hash_key(char *key);


#endif /* INCLUDE_MY_MAP_ */
