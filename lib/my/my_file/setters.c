/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file setters
*/

#include <fcntl.h>
#include <stdarg.h>

#include "my_string.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_file.h"

void file_write(file_t *this, char *new)
{
    write(this->fd, new, my_strlen(new));
}

void file_fwrite(file_t *this, char *fmt, ...)
{
    va_list ap;
    char *dest;

    va_start(ap, fmt);
    my_vasprintf(&dest, fmt, &ap);
    va_end(ap);

    (*this->write)(this, dest);

    free(dest);
}
