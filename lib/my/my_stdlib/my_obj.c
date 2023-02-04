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
    void *obj = my_malloc(sizeof(obj_meta_t) + size);

    obj_set_destructor(obj + sizeof(obj_meta_t), NULL);

    return obj + sizeof(obj_meta_t);
}

void *obj_realloc(void *obj, size_t size)
{
    void *new = my_realloc(
        obj - sizeof(obj_meta_t),
        sizeof(obj_meta_t) + size
    );

    return new + sizeof(obj_meta_t);
}

void obj_free(void *obj)
{
    void (*destructor)(void *) = NULL;

    destructor = ((obj_meta_t *)(obj - sizeof(obj_meta_t)))->destructor;

    if (destructor != NULL)
        destructor(obj);

    my_free(obj - sizeof(obj_meta_t));
}

void obj_vfree(int argc, ...)
{
    va_list ap;

    va_start(ap, argc);
    while (argc--)
        obj_free(va_arg(ap, void *));
    va_end(ap);
}
