/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** list utils
*/

#include "my_stdlib.h"
#include "my_list.h"

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
