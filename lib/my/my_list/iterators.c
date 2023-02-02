/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** iterators
*/

#include "my_stdlib.h"
#include "my_list.h"

void list_for_each(list_t *list, int (*fn)(void *, void *), void *data)
{
    node_t *temp = list->front;

    while (temp != NULL) {
        if (fn(temp->data, data))
            return;
        temp = temp->next;
    }
}
