/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** linked list
*/

#include "my_stdlib.h"
#include "my_list.h"
#include "my_obj.h"

node_t *node_create(void)
{
    node_t *new_node = my_malloc(sizeof(node_t));

    if (new_node == NULL)
        return NULL;

    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->data = NULL;

    return new_node;
}

list_t *list_create(void)
{
    list_t *list = obj_alloc(sizeof(list_t));

    if (list == NULL)
        return NULL;

    obj_get_meta(list)->destructor = &list_free;
    list->front = NULL;
    list->back = NULL;
    list->size = 0;

    return list;
}
