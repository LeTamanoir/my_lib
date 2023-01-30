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
#include "my_str.h"
#include "my_file.h"
#include "my_obj.h"

static int const BUFF_SIZE = 4096;

static int file_is_valid(char const *file_path)
{
    struct stat file_stat;
    int st = stat(file_path, &file_stat);
    int fd = open(file_path, O_RDONLY);

    if (fd == -1 || st != 0 || !S_ISREG(file_stat.st_mode))
        return 1;

    close(fd);
    return 0;
}

file_t *file_create(char const *file_path, int const file_mode)
{
    if (file_is_valid(file_path) != 0)
        return NULL;

    file_t *file = obj_alloc(sizeof(file_t));

    if (file == NULL)
        return NULL;

    obj_set_destructor(file, (void (*)(void *))&file_free);
    stat(file_path, &file->stats);
    file->file_path = str_create(file_path);
    file->content = str_create("");
    file->__cache = str_create("");
    file->current_line = str_create("");
    if (!file->__cache || !file->file_path || !file->content)
        return NULL;
    str_resize(&file->__cache, BUFF_SIZE);
    file->fd = open(file_path, file_mode);

    return file;
}

file_t *file_dcreate(int fd)
{
    file_t *file = obj_alloc(sizeof(file_t));

    if (file == NULL)
        return NULL;

    obj_set_destructor(file, (void (*)(void *))&file_free);
    file->file_path = str_create("");
    file->content = str_create("");
    file->__cache = str_create("");
    file->current_line = str_create("");
    if (!file->__cache || !file->file_path || !file->content)
        return NULL;
    str_resize(&file->__cache, BUFF_SIZE);
    file->fd = fd;

    return file;
}

void file_close(file_t *file)
{
    close(file->fd);
    file->fd = -1;
}

void file_free(file_t *file)
{
    if (file->fd != -1 &&
        file->fd != STDIN_FILENO &&
        file->fd != STDOUT_FILENO &&
        file->fd != STDERR_FILENO)
        file_close(file);
    obj_free(file->content);
    if (file->__cache != NULL)
        obj_free(file->__cache);
    obj_free(file->file_path);
    obj_free(file->current_line);
}
