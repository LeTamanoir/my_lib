/*
** EPITECH PROJECT, 2023
** my_stdio
** File description:
** list utils
*/

#include "my_list.h"

void list_insert(list_t *list, node_t *after, void *data)
{
    if (after == NULL || after == list->back) {
        list_pushback(list, data);
        return;
    }
    node_t *new = node_create();
    new->data = data;
    new->next = after->next;
    new->prev = after;
    after->next->prev = new;
    after->next = new;
    list->size++;
}

void list_pushfront(list_t *list, void *data)
{
    node_t *new_node = node_create();
    new_node->data = data;
    list->size++;

    if (list->front == NULL && list->back == NULL) {
        list->front = new_node;
        list->back = new_node;
    } else {
        new_node->next = list->front;
        list->front->prev = new_node;
        list->front = new_node;
    }
}

void list_pushback(list_t *list, void *data)
{
    node_t *new_node = node_create();
    new_node->data = data;
    list->size++;

    if (list->front == NULL && list->back == NULL) {
        list->front = new_node;
        list->back = new_node;
    } else {
        list->back->next = new_node;
        new_node->prev = list->back;
        list->back = new_node;
    }
}
