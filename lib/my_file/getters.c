/*
** EPITECH PROJECT, 2023
** my_file.h
** File description:
** file getters
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my_stdlib.h"
#include "my_str.h"
#include "my_file.h"
#include "my_obj.h"

int add_from_cache(file_t *file);
int add_from_read(file_t *file);

str_t *file_get_content(file_t *file)
{
    str_t **ct = &file->content;

    str_resize(ct, file->stats.st_size);
    ssize_t read_len = read(file->fd, (*ct)->data, file->stats.st_size);
    if (read_len == -1)
        return NULL;
    (*ct)->length = read_len;
    file_close(file);

    return *ct;
}

str_t *file_getline(file_t *file)
{
    int can_add = 1;
    int size = 0;
    str_t **cache = &file->__cache;
    str_t **line = str_clear(&file->current_line);

    if (file->__cache == NULL) {
        file_close(file);
        return NULL;
    }
    if ((*cache)->length != 0)
        can_add = add_from_cache(file);
    if ((*cache)->length == 0 && can_add)
        size = add_from_read(file);
    if (size == 0 && (*cache)->length == 0) {
        obj_free(file->__cache);
        file->__cache = NULL;
    }
    return *line;
}
