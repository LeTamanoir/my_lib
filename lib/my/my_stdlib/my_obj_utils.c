/*
** EPITECH PROJECT, 2022
** my_obj
** File description:
** utils
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_obj.h"

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
