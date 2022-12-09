/*
** EPITECH PROJECT, 2022
** my_lk_list
** File description:
** linked_list declarations
*/

#pragma once

typedef struct node_s {
    void *value;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *first;
    node_t *last;
    int length;
} list_t;

list_t *list_create(void);
void list_free(list_t *list);

void list_push_front(list_t *list, void *value);
void list_push_back(list_t *list, void *value);
void list_pop_front(list_t *list);
void list_pop_back(list_t *list);

void node_free(node_t *node);
node_t *node_create(void);
