/*
** EPITECH PROJECT, 2022
** antman
** File description:
** auto_free
*/

#include "my_stdlib.h"
#include "my_obj.h"

void auto_free(void *ptr)
{
    void *obj = *(void **)ptr;

    if (obj == NULL)
        return;

    obj_free(obj);
}
