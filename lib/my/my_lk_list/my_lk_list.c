/*
** EPITECH PROJECT, 2022
** my_lk_list
** File description:
** linked list utils
*/

#include "my_stdlib.h"
#include "my_string.h"
#include "my_lk_list.h"
#include "my_lk_list_utils.h"

static lk_node_t *lk_list_pop(lk_list_t *this)
{
    lk_node_t *first = this->first_node;

    if (first == NULL) return NULL;

    this->length--;
    this->first_node = this->first_node->next;

    first->next = NULL;

    return first;
}

static void lk_list_append(lk_list_t *this, lk_node_t *node)
{
    this->length++;

    if (this->first_node == NULL) {
        this->first_node = node;
        this->last_node = node;
    } else {
        this->last_node->next = node;
        this->last_node = node;
    }
}

static void lk_list_delete(
    lk_list_t *this, void *del_value,
    int (*cmp)(), void (*delete_fn)()
)
{
    lk_node_t *prev = NULL;
    lk_node_t *curr = this->first_node;
    while (curr != NULL) {
        if ((*cmp)(curr->value, del_value) != 0) {
            prev = curr;
            curr = curr->next;
            continue;
        }
        this->length--;
        if (prev == NULL) {
            this->first_node = curr->next;
            (*delete_fn)(curr);
            curr = this->first_node;
            continue;
        }
        prev->next = curr->next;
        (*delete_fn)(curr);
        curr = prev->next;
    }
    this->last_node = prev;
}

static lk_node_t *lk_list_get(lk_list_t *this, int index)
{
    lk_node_t *curr = this->first_node;
    int idx = 0;

    while (curr != NULL) {
        if (idx == index) {
            return curr;
        }

        idx++;
        curr = curr->next;
    }

    return NULL;
}

lk_list_t *lk_list_create(void)
{
    lk_list_t *lk_list = malloc(sizeof(lk_list_t));

    lk_list->first_node = NULL;
    lk_list->last_node = NULL;
    lk_list->length = 0;

    lk_list->add = &lk_list_add;
    lk_list->insert = &lk_list_insert;
    lk_list->append = &lk_list_append;
    lk_list->pop = &lk_list_pop;
    lk_list->delete = &lk_list_delete;
    lk_list->get = &lk_list_get;

    return lk_list;
}
