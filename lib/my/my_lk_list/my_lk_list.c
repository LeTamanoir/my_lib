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

static void lk_list_add(lk_list_t *this, void *value)
{
    lk_list_elem_t *new_node = create_new_node();

    new_node->value = value;
    this->length++;

    if (*this->first_node == NULL) {
        *this->first_node = new_node;
        *this->last_node = new_node;
    } else {
        (*this->last_node)->next = new_node;
        *this->last_node = new_node;
    }
}

static void lk_list_delete(
    lk_list_t *this, void *del_value,
    int (*cmp)(), void (*delete_fn)()
)
{
    lk_list_elem_t *prev = NULL;
    lk_list_elem_t *curr = *this->first_node;
    while (curr != NULL) {
        if ((*cmp)(curr->value, del_value) != 0) {
            prev = curr;
            curr = curr->next;
            continue;
        }
        this->length--;
        if (prev == NULL) {
            *this->first_node = curr->next;
            (*delete_fn)(curr);
            curr = *this->first_node;
            continue;
        }
        prev->next = curr->next;
        (*delete_fn)(curr);
        curr = prev->next;
    } *this->last_node = prev;
}

static lk_list_elem_t *lk_list_get(lk_list_t *this, int index)
{
    lk_list_elem_t *curr = *this->first_node;
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

    lk_list->first_node = my_calloc(0, sizeof(lk_list_elem_t *));
    lk_list->last_node = my_calloc(0, sizeof(lk_list_elem_t *));
    lk_list->length = 0;

    lk_list->add = &lk_list_add;
    lk_list->delete = &lk_list_delete;
    lk_list->get = &lk_list_get;

    return lk_list;
}
