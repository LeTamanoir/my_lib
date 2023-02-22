/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** list free
*/

#include "my_obj.h"
#include "my_list.h"

void list_free(void *ptr)
{
    list_t *list = (list_t*)ptr;
    node_t *temp = list->front;
    node_t *old = NULL;

    while (temp != NULL) {
        old = temp;
        temp = temp->next;
        node_free(old);
    }
}

void node_free(node_t *node)
{
    obj_free(node->data);
    my_free(node);
}
