/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** lk_list utils
*/

#include "my_stdlib.h"
#include "my_lk_list.h"
#include "my_lk_list_utils.h"

void lk_list_insert(lk_list_t *this, lk_node_t *node)
{
    lk_node_t *temp = this->first_node;
    this->length++;

    this->first_node = node;
    node->next = temp;
}

void lk_list_add(lk_list_t *this, void *value)
{
    lk_node_t *new_node = create_new_node();

    new_node->value = value;
    this->length++;

    if (this->first_node == NULL) {
        this->first_node = new_node;
        this->last_node = new_node;
    } else {
        this->last_node->next = new_node;
        this->last_node = new_node;
    }
}

void lk_list_free_node(lk_node_t *node)
{
    free(node->value);
    free(node);
}

lk_node_t *create_new_node(void)
{
    lk_node_t *new_node = malloc(sizeof(lk_node_t));

    new_node->next = NULL;
    new_node->value = NULL;

    return new_node;
}

void lk_list_free(lk_list_t *list, void (*free_fn)())
{
    lk_node_t *temp = list->first_node;
    lk_node_t *old = list->first_node;

    while (temp != NULL) {
        old = temp;
        temp = temp->next;
        (*free_fn)(old);
    }

    free(list);
}
