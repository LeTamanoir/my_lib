/*
** EPITECH PROJECT, 2022
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include <stdio.h>
#include <stdlib.h>

#include "my_list.h"
#include "my_map.h"
#include "my_str.h"
#include "my_vec.h"

int main(void)
{
    vec_int_t *temp = vec_create(100, sizeof(int));

    for (int i = 0; i < 100; i++)
        vec_pushback(&temp, &(int){rand() % 1000});

    for (size_t i = 0; i < temp->size; i++)
        printf("%d - ", temp->data[i]);

    puts("\n\n");

    vec_sort(temp, NULL);

    for (size_t i = 0; i < temp->size; i++)
        printf("%d - ", temp->data[i]);

    free(temp);
    return 0;
}
