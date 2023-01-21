/*
** EPITECH PROJECT, 2022
** my_set
** File description:
** set class
*/

#include "my_stdlib.h"
#include "my_btree.h"
#include "my_obj.h"
#include "my_vec.h"

typedef struct set_s {
    btree_t *root;
    void (*cmp_fn)(void *, void *);
    size_t size;
} set_t;

set_t *set_create(void (*cmp_fn)(void *, void *))
{
    set_t *set = obj_alloc(sizeof(set_t));

    // obj_set_destructor

    set->root = btree_create_node();
    set->cmp_fn = cmp_fn;
    set->size = 0;

    return set;
}

void *set_find(set_t *set, void *data)
{
    return btree_search(set->root, data, set->cmp_fn);
}

void set_insert(set_t *set, void *data)
{
    if (set_find(set, data) == NULL)
        return;

    btree_insert(&set->root, data, set->cmp_fn);
}

static void insert_in_set_from_vec(void *elem, void *set_)
{
    set_t *set = set_;
    set_insert(set, elem);
}

set_t *set_insert_vector(set_t *set, vec_t *vec)
{
    vec_for_each(vec, &insert_in_set_from_vec, set);
}
