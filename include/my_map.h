/*
** EPITECH PROJECT, 2023
** my_map
** File description:
** map implementation
*/

#ifndef INCLUDE_MY_MAP_
    #define INCLUDE_MY_MAP_

    #include "my_list.h"
    #include "my_vec.h"
    #include "my_str.h"

typedef struct map_elem_s {
    str_t *key;
    void *data;
} map_elem_t;

typedef struct map_s {
    size_t capacity;
    vec_list_t *elems;
} map_t;

/**
 * @brief get the keys of a map
 *
 * @param map   the map to get the keys from
 * @return a vector of the keys stored in strings
 */
vec_str_t *map_get_keys(map_t const *map);

/**
 * @brief set a value in a map, it will overwrite if it already exists
 *
 * @param map   the map to add the new entry
 * @param key   the key of the entry
 * @param data  the data of the entry
 */
void map_set(map_t *map, str_t const *key, void *data);

/**
 * @brief get the value from a map with a given key
 *
 * @param map   the map to get the key from
 * @param key   the key as a string
 * @return the element assiciated with the key, or NULL if undefined
 */
void *map_get(map_t const *map, str_t const *key);

/**
 * @brief create a new map
 *
 * @param capacity  for better efficiency this value must be as large as the
 *                  number of elements in the map
 * @return a new map
 */
map_t *map_create(size_t capacity);

/**
 * @brief frees a map along with all its elements
 *        the element with be freeable with only free
 * @param ptr   the map to free
 */
void map_free(void *ptr);

/**
 * @brief helper function used by map_free to free a map element
 *        normally you shouldn't have use it
 *
 * @param ptr  the element to free
 */
void map_elem_free(void *ptr);

/**
 * @brief hash a key to find its index in the map
 *        normally you shouldn't have use it
 *
 * @param key   the string of key to hash
 * @return the index of where the data is in the map
 */
size_t map_hash_key(str_t const *key);

/**
 * @brief deletes a key from a map
 *
 * @param map   the map to delete the key from
 * @param key   the key to delete
 */
void map_del(map_t *map, str_t const *key);


#endif /* INCLUDE_MY_MAP_ */
