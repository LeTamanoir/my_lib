/*
** EPITECH PROJECT, 2023
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include <time.h>

#include "my_str.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"
#include "my_map.h"
#include "my_list.h"
#include "my_fmt.h"
#include "my_obj.h"

int *alloc_int(int data)
{
    int *ptr = obj_alloc(sizeof(int));
    *ptr = data;
    return ptr;
}

void print_list(list_t *l)
{
    for (node_t *n = l->front; n != NULL; n = n->next)
        my_printf("%d\n", *(int*)n->data);
}

int main(void)
{
    SMART list_t *l = list_create();

    srand(time(NULL));

    for (int i = 0; i < 100; i++)
        list_pushback(l, alloc_int(rand() % 1000));

    list_sort(l, NULL);

    print_list(l);

    return 0;
}
