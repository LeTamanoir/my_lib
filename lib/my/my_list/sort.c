/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** sort
*/

#include "my_list.h"
#include "my_stdlib.h"

static int default_compare(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

static node_t *partition(
    int (*cmp_fn)(void *, void *),
    node_t *start, node_t *end
)
{
    node_t *pivot = end;
    node_t *i = start->prev;
 
    for (node_t *j = start; j != end; j = j->next) {
        if (cmp_fn(j->data, pivot->data) <= 0) {
            i = (i != NULL) ? i->next : start;
            my_swap(&i->data, &j->data, sizeof(void *));
        }
    }

    i = (i == NULL) ? start : i->next;
    my_swap(&i->data, &end->data, sizeof(void *));
    return i;
}

static void quicksort(
    int (*cmp_fn)(void *, void *),
    node_t* start, node_t *end)
{
    if (end == NULL || end == start || start == end->next)
        return;

    node_t *center = partition(cmp_fn, start, end);
    quicksort(cmp_fn, start, center->prev);
    quicksort(cmp_fn, center->next, end);
}

void list_sort(list_t *list, int (*cmp_fn)(void *, void *))
{
    if (cmp_fn == NULL)
        cmp_fn = &default_compare;

    quicksort(cmp_fn, list->front, list->back);
}
