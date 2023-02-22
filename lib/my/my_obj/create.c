/*
** EPITECH PROJECT, 2022
** my_obj
** File description:
** allocator
*/

#include "my_stdlib.h"
#include "my_obj.h"

void *obj_alloc(size_t size)
{
    void *obj = my_malloc(sizeof(obj_meta_t) + size);

    if (obj == NULL)
        return NULL;

    obj_get_meta(obj + sizeof(obj_meta_t))->destructor = NULL;

    return obj + sizeof(obj_meta_t);
}

void *obj_realloc(void *obj, size_t size)
{
    void *new = my_realloc(
        obj - sizeof(obj_meta_t),
        sizeof(obj_meta_t) + size
    );

    if (new == NULL)
        return NULL;

    return new + sizeof(obj_meta_t);
}
