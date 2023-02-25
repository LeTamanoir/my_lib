/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** list free
*/

#include <stdlib.h>

#include "my_list.h"

void list_free(list_t *list)
{
    node_t *temp = list->front;
    node_t *old = NULL;

    while (temp != NULL) {
        old = temp;
        temp = temp->next;
        free(old->data);
        free(old);
    }
    free(list);
}
