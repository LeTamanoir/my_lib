/*
** EPITECH PROJECT, 2022
** my_lk_list
** File description:
** linked list utils
*/

#include <stdlib.h>

#include "my.h"
#include "my_lk_list.h"
#include "my_lk_list_utils.h"

static void lk_list_add(struct lk_list_s *this, void *value)
{
    lk_list_elem_t *new_node = create_new_node();

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

static void lk_list_delete(
    struct lk_list_s *this, void *del_value,
    int (*cmp)(), int delete_all
)
{
    lk_list_elem_t *prev = this->first_node;
    lk_list_elem_t *curr = this->first_node;
    lk_list_elem_t *temp = this->first_node;
    int idx = -1;
    while (curr != NULL) {
        idx++;
        if ((*cmp)(curr->value, del_value) != 0) {
            prev = curr;
            curr = curr->next;
            continue;
        } if (idx == 0) {
            this->first_node = curr->next;
        } else {
            prev->next = curr->next;
        } temp = curr->next;
        free_node(curr);
        curr = temp;
        this->length--;
        if (!delete_all) return;
    }
}

static lk_list_elem_t *lk_list_get(struct lk_list_s *this, int index)
{
    lk_list_elem_t *curr = this->first_node;
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
    lk_list->last_node = lk_list->first_node;
    lk_list->length = 0;

    lk_list->add = &lk_list_add;
    lk_list->delete = &lk_list_delete;
    lk_list->get = &lk_list_get;

    return lk_list;
}
