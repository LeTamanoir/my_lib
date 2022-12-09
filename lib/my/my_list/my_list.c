/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** linked list
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_list.h"

node_t *node_create(void)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = NULL;

    return new_node;
}

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->first = NULL;
    list->last = NULL;
    list->length = 0;

    return list;
}

void node_free(node_t *node)
{
    free(node->value);
    free(node);
}

void list_free(list_t *list)
{
    node_t *temp = list->first;
    node_t *old = list->first;

    while (temp != NULL) {
        old = temp;
        temp = temp->next;
        node_free(old);
    }

    free(list);
}
