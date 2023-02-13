/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** remove elements
*/

#include "my_stdlib.h"
#include "my_list.h"

void list_remove(list_t *list, node_t *elem)
{
    if (elem->prev != NULL) {
        elem->prev->next = elem->next;
    } else {
        list->front = elem->next;
    }

    if (elem->next != NULL) {
        elem->next->prev = elem->prev;
    } else {
        list->back = elem->prev;
    }

    node_free(elem);
    list->size--;
}

void list_popfront(list_t *list)
{
    if (list->front == NULL && list->back == NULL) {
        return;
    }

    node_t *temp = list->front;
    list->size--;

    list->front = list->front->next;
    if (list->front == NULL)
        list->back = NULL;
    else
        list->front->prev = NULL;

    node_free(temp);
}

void list_popback(list_t *list)
{
    if (list->front == NULL && list->back == NULL) {
        return;
    }

    node_t *temp = list->back;
    list->size--;

    list->back = list->back->prev;
    if (list->back == NULL)
        list->front = NULL;
    else
        list->back->next = NULL;

    node_free(temp);
}
