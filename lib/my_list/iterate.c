/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** iterators
*/

#include "my_list.h"

void list_foreach(list_t *list, void (*fn)(void *, void *), void *data)
{
    node_t *temp = list->front;

    while (temp != NULL) {
        fn(temp->data, data);
        temp = temp->next;
    }
}
