/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** va_arg free
*/

#include <stdarg.h>
#include "my_stdlib.h"

void my_free(void *ptr)
{
    free(ptr - sizeof(alloc_meta_t));
}

void vfree(int argc, ...)
{
    va_list ap;

    va_start(ap, argc);
    while (argc--)
        my_free(va_arg(ap, void *));
    va_end(ap);
}
