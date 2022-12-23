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
    struct stat file_stat;
    stat(file->file_path, &file_stat);
    int size = file_stat.st_size;
    str_t *ct = file->content;

    str_resize(ct, size);
    ct->length = read(file->fd, ct->data, size);
    file_close(file);

    return ct->data;
}

char *file_get_line(file_t *file)
{
    int last_line = file->content->length;
    int can_add = 1;
    int size = 0;
    str_t *cache = file->__cache;
    str_t *ct = file->content;

    if (cache->length == -1) {
        file_close(file);
        return NULL;
    }
    if (cache->length != 0)
        can_add = add_from_cache(file);
    if (cache->length == 0 && can_add) {
        size = add_from_read(file);
        if (size == 0 && cache->length == 0)
            cache->length = -1;
    }

    return &(ct->data[last_line]);
}
