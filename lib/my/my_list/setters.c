/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** lk_list utils
*/

#include "my_stdlib.h"
#include "my_list.h"

void list_push_front(list_t *list, void *value)
{
    node_t *new_node = node_create();
    new_node->value = value;
    list->length++;

    if (list->first == NULL && list->last == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        new_node->next = list->first;
        list->first = new_node;
    }
}

void list_push_back(list_t *list, void *value)
{
    node_t *new_node = node_create();
    new_node->value = value;
    list->length++;

    if (list->first == NULL && list->last == NULL) {
        list->first = new_node;
        list->last = new_node;
    } else {
        list->last->next = new_node;
        list->last = new_node;
    }
}

void list_pop_front(list_t *list)
{
    node_t *first = list->first;
    node_t *temp = first;

    if (first == NULL) return;

    list->first = list->first->next;
    list->length--;

    node_free(temp);
}

void list_pop_back(list_t *list)
{
    node_t *last = list->last;
    node_t *temp = last;

    if (last == NULL) return;

    list->last = list->last->prev;
    list->length--;

    node_free(temp);
}
