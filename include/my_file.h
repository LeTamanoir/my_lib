/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** my_file utils
*/

#include <unistd.h>
#include <fcntl.h>

#include "my_lk_list.h"
#include "my_string.h"

#pragma once

#define F_R         (O_RDONLY)
#define F_W         (O_WRONLY)
#define F_RW        (O_RDWR)

#define F_A         (O_APPEND)
#define F_C         (O_CREAT)
#define F_T         (O_TRUNC)

#define F_BUFF_SIZE    (128)

typedef struct file_s file_t;
typedef struct file_s {
    int fd;
    char *file_path;
    string_t *content;
    string_t *__line;

    char *(*get_line)(file_t *this);
    char *(*get_content)(file_t *this);

    void (*write)(file_t *this, char *new);
    void (*fwrite)(file_t *this, char *fmt, ...);
} file_t;

file_t *file_create(char const *file_path, int const file_mode);
void file_free(file_t *file);
