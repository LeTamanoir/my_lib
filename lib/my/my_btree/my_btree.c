/*
** EPITECH PROJECT, 2022
** my_btree
** File description:
** binary tree class
*/

#include "my_stdlib.h"
#include "my_btree.h"

btree_t *btree_create_node(void)
{
    btree_t *new = malloc(sizeof(btree_t));

    new->data = NULL;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void btree_insert(btree_t **root, void *data, int (*cmp_fn)(void *, void *))
{
    if (*root == NULL) {
        *root = btree_create_node();
        (*root)->data = data;
        return;
    }

    if (cmp_fn((*root)->data, data) <= 0)
        btree_insert_data(&(*root)->right, data, cmp_fn);
    else
        btree_insert_data(&(*root)->left, data, cmp_fn);
}

void *btree_search(btree_t *root, void *data, int (*cmp_fn)(void *, void *))
{
    if (root == NULL)
        return NULL;

    if (cmp_fn(root->data, data))
        return root->data;

    return (
        btree_search(root->left, data, cmp_fn) ||
        btree_search(root->right, data, cmp_fn)
    );
}
