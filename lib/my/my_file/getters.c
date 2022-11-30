/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file getters
*/

#include <sys/stat.h>
#include <fcntl.h>

#include "my_stdlib.h"
#include "my_string.h"
#include "my_file.h"

#include "./include/getters.h"

char *file_get_content(file_t *this)
{
    struct stat file_stat;
    stat(this->file_path, &file_stat);
    int size = file_stat.st_size;

    char *content = my_calloc(0, sizeof(char) * (size + 1));
    read(this->fd, content, size);

    this->content->slice(this->content, 0, 0);
    this->content->add(this->content, content);
    close(this->fd);

    return content;
}

char *file_get_line(file_t *this)
{
    string_t *line = string_create("");
    int last_line = my_strlen(this->content->content);
    int size = 0;

    if (this->__line->length == -1) {
        close(this->fd);
        return NULL;
    }
    if (this->__line->length != 0)
        add_from_cache(this, line);
    if (this->__line->length == 0) {
        size = add_from_read(this, line);

        if (size == 0 && this->__line->length == 0)
            this->__line->length = -1;
    }
    this->content->add(this->content, line->content);
    string_free(line);
    return &(this->content->content[last_line]);
}
