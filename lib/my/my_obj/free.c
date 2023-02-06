/*
** EPITECH PROJECT, 2022
** my_obj
** File description:
** free
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_obj.h"

void obj_free(void *obj)
{
    obj_meta_t *meta = (obj_meta_t *)(obj - sizeof(obj_meta_t));

    if (meta->destructor != NULL)
        meta->destructor(obj);

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
