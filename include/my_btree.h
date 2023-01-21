/*
** EPITECH PROJECT, 2022
** my_btree
** File description:
** binary tree declarations
*/

#ifndef INCLUDE_MY_BTREE_
    #define INCLUDE_MY_BTREE_


typedef struct btree_s {
    void *data;

    struct btree_s *left;
    struct btree_s *right;
} btree_t;

/**
 * @brief creates a new btree node
 *
 * @return the created node
 */
btree_t *btree_create_node(void);

/**
 * @brief inserts data into a binary tree
 *
 * @param root  the root of the btree
 * @param data  the data to insert
 * @param cmp_fn  the function to know weather to go right or left during
 *                insertion (expected behaviour of strmp)
 */
void btree_insert(btree_t **root, void *data, int (*cmp_fn)(void *, void *));

/**
 * @brief searchs a btree for specific data
 *
 * @param root  the root of the btree
 * @param data  the data to find
 * @param cmp_fn    the function to find the data
 * @return the data if found or NULL
 */
void *btree_search(btree_t *root, void *data, int (*cmp_fn)(void *, void *));


#endif /* INCLUDE_MY_BTREE_ */
