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

#include "get_line_utils.h"

char *file_get_content(file_t *file)
{
    struct stat file_stat;
    stat(file->file_path, &file_stat);
    int size = file_stat.st_size;

    char *content = my_calloc(0, sizeof(char) * (size + 1));
    read(file->fd, content, size);

    str_slice(file->content, 0, 0);
    str_add(file->content, content);
    close(file->fd);
    file->fd = -1;

    return content;
}

char *file_get_line(file_t *file)
{
    str_t *line = str_create("");
    int last_line = my_strlen(file->content->content);
    int size = 0;
    int can_stop = 0;

    if (file->__line->length == -1) {
        close(file->fd);
        file->fd = -1;
        return NULL;
    }
    if (file->__line->length != 0)
        add_from_cache(file, line, &can_stop);
    if (file->__line->length == 0 && !can_stop) {
        size = add_from_read(file, line);
        if (size == 0 && file->__line->length == 0)
            file->__line->length = -1;
    }
    str_add(file->content, line->content);
    str_free(line);
    return &(file->content->content[last_line]);
}
