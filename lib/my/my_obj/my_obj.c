/*
** EPITECH PROJECT, 2022
** my_obj
** File description:
** allocator
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_obj.h"

void *obj_alloc(size_t size)
{
    void *obj = malloc(sizeof(obj_meta_t) + size);

    obj_set_destructor(obj + sizeof(obj_meta_t), NULL);

    return obj + sizeof(obj_meta_t);
}

void obj_set_destructor(void *obj, void (*destructor)(void *))
{
    obj_meta_t *meta = obj - sizeof(obj_meta_t);
    meta->destructor = destructor;
}

void *obj_get_destructor(void *obj)
{
    obj_meta_t *meta = obj - sizeof(obj_meta_t);
    return meta->destructor;
}

void obj_free(void *obj)
{
    void *obj_start = obj - sizeof(obj_meta_t);
    obj_meta_t *meta = obj_start;

    if (meta->destructor != NULL)
        meta->destructor(obj);

    free(obj_start);
}

void obj_vfree(int argc, ...)
{
    va_list ap;

    va_start(ap, argc);
    while (argc--)
        obj_free(va_arg(ap, void *));
    va_end(ap);
}
