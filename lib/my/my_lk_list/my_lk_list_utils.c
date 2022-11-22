/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** lk_list utils
*/

#include "my_stdlib.h"
#include "my_lk_list.h"

void lk_list_free_simple_node(lk_list_elem_t *node)
{
    free(node->value);
    free(node);
}

lk_list_elem_t *create_new_node(void)
{
    lk_list_elem_t *new_node = malloc(sizeof(lk_list_elem_t));

    new_node->next = NULL;
    new_node->value = NULL;

    return new_node;
}

void lk_list_free(lk_list_t *list, void (*free_fn)())
{
    lk_list_elem_t *temp = list->first_node;
    lk_list_elem_t *old = list->first_node;

    while (temp != NULL) {
        old = temp;
        temp = temp->next;
        (*free_fn)(old);
    }

    free(list);
}
