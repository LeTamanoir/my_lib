/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file getters
*/

#include <sys/stat.h>
#include <fcntl.h>

#include "my_stdlib.h"
#include "my_str.h"
#include "my_file.h"
#include "my_file.h"
#include "get_line_utils.h"

char *file_get_content(file_t *file)
{
    str_t **ct = &file->content;

    str_resize(ct, file->stats.st_size);
    (*ct)->length = read(file->fd, (char*)(*ct)->data, file->stats.st_size);
    (*ct)->data[(*ct)->length] = '\0';
    file_close(file);

    return (*ct)->data;
}

char *file_get_line(file_t *file)
{
    int last_line = file->content->length;
    int can_add = 1;
    int size = 0;
    str_t *cache = file->__cache;
    str_t *ct = file->content;

    if (file->__cache == NULL) {
        file_close(file);
        return NULL;
    }
    if (cache->length != 0)
        can_add = add_from_cache(file);
    if (cache->length == 0 && can_add)
        size = add_from_read(file);
    if (size == 0 && cache->length == 0) {
        free(file->__cache);
        file->__cache = NULL;
    }
    return &(ct->data[last_line]);
}
