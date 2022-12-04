/*
** EPITECH PROJECT, 2022
** my_lk_list
** File description:
** linked_list declarations
*/

#pragma once

typedef struct lk_node_s lk_node_t;
typedef struct lk_node_s {
    void *value;
    lk_node_t *next;
} lk_node_t;

typedef struct lk_list_s lk_list_t;
typedef struct lk_list_s {
    lk_node_t *first_node;
    lk_node_t *last_node;

    int length;

    void (*add)(lk_list_t *this, void *value);
    void (*insert)(lk_list_t *this, lk_node_t *node);
    void (*append)(lk_list_t *this, lk_node_t *node);
    lk_node_t *(*pop)(lk_list_t *this);

    lk_node_t *(*get)(lk_list_t *this, int index);
    void (*delete)(
        lk_list_t *this, void *del_value,
        int (*cmp)(), void (*delete_fn)()
    );
} lk_list_t;

lk_list_t *lk_list_create(void);

void lk_list_free(lk_list_t *list, void (*free_fn)());
void lk_list_free_node(lk_node_t *node);
