/*
** EPITECH PROJECT, 2022
** my_obj
** File description:
** utils
*/

#include <stdarg.h>
#include "my_stdlib.h"
#include "my_obj.h"

obj_meta_t *obj_get_meta(void *obj)
{
    obj_meta_t *meta = (obj - sizeof(obj_meta_t));

    return meta;
}