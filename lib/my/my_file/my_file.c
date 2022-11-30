/*
** EPITECH PROJECT, 2022
** my_file.c
** File description:
** my_file utils
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my_stdlib.h"
#include "my_string.h"

#include "./include/getters.h"
#include "./include/setters.h"
#include "my_file.h"

static int file_is_valid(char const *file_path)
{
    struct stat file_stat;
    int st = lstat(file_path, &file_stat);
    int fd = open(file_path, O_RDONLY);

    if (fd == -1) return 1;
    if (st != 0) return 1;
    if (!S_ISREG(file_stat.st_mode)) {
        return 1;
    }

    close(fd);
    return 0;
}

file_t *file_create(char const *file_path, int const file_mode)
{
    if (file_is_valid(file_path) != 0) {
        return NULL;
    }
    file_t *file = malloc(sizeof(file_t));

    file->file_path = my_strdup(file_path);
    file->content = string_create("");
    file->__line = string_create("");
    file->fd = open(file_path, file_mode);

    file->get_content = &file_get_content;
    file->get_line = &file_get_line;
    file->write = &file_write;
    file->fwrite = &file_fwrite;

    return file;
}

void file_close(file_t *file)
{
    close(file->fd);
}

void file_free(file_t *file)
{
    if (file->fd != -1) {
        file_close(file);
    }
    string_free(file->content);
    string_free(file->__line);
    free(file->file_path);
    free(file);
}
