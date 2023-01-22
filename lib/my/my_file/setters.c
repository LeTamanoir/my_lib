/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file setters
*/

#include <fcntl.h>
#include <stdarg.h>

#include "my_str.h"
#include "my_stdlib.h"
#include "my_fmt.h"
#include "my_file.h"

void file_write(file_t *file, char const *str)
{
    write(file->fd, str, my_strlen(str));
}

void file_strwrite(file_t *file, str_t const *str)
{
    str_dprint(file->fd, str);
}

void file_fwrite(file_t *file, char const *fmt, ...)
{
    va_list ap;
    SMART str_t *buff = NULL;

    va_start(ap, fmt);
    buff = fmt_create(fmt, &ap);
    va_end(ap);

    file_strwrite(file, buff);
}
