/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** linked list
*/

#include <stdlib.h>
#include "my_list.h"

node_t *new_node(void)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return NULL;

    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->data = NULL;

    return new_node;
}

list_t *new_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;

    list->front = NULL;
    list->back = NULL;
    list->size = 0;

    return list;
}
