/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** my_file utils
*/

#include <unistd.h>
#include <fcntl.h>

#include "my_list.h"
#include "my_str.h"

#pragma once

#define F_R         (O_RDONLY)
#define F_W         (O_WRONLY)
#define F_RW        (O_RDWR)

#define F_A         (O_APPEND)
#define F_C         (O_CREAT)
#define F_T         (O_TRUNC)

#define F_BUFF_SIZE    (128)

typedef struct file_s {
    int fd;
    char *file_path;
    str_t *content;
    str_t *__line;
} file_t;

file_t *file_create(char const *file_path, int const file_mode);
char *file_get_line(file_t *file);
char *file_get_content(file_t *file);
void file_write(file_t *file, char *str);
void file_fwrite(file_t *file, char *fmt, ...);
void file_free(file_t *file);
