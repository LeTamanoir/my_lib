/*
** EPITECH PROJECT, 2022
** my_lk_list
** File description:
** linked_list declarations
*/

#pragma once

typedef struct lk_list_elem_s {
    void *value;
    struct lk_list_elem_s *next;
} lk_list_elem_t;

typedef struct lk_list_s {
    lk_list_elem_t *first_node;
    lk_list_elem_t *last_node;

    int length;

    void (*add)(struct lk_list_s *this, void *value);

    void (*delete)(
        struct lk_list_s *this, void *del_value,
        int (*cmp)(), int delete_all
    );

    // void (*sort)(struct lk_list_s *this);

    lk_list_elem_t *(*get)(struct lk_list_s *this, int index);
} lk_list_t;

lk_list_t *lk_list_create(void);

void lk_list_free(lk_list_t *list);
