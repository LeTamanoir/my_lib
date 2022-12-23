/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** my_file utils
*/

#ifndef INCLUDE_MY_FILE_
    #define INCLUDE_MY_FILE_
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include "my_list.h"
    #include "my_str.h"
    #define F_R         (O_RDONLY)
    #define F_W         (O_WRONLY)
    #define F_RW        (O_RDWR)
    #define F_A         (O_APPEND)
    #define F_C         (O_CREAT)
    #define F_T         (O_TRUNC)


typedef struct file_s {
    int fd;
    char *file_path;
    str_t *content;
    str_t *__cache;
    struct stat stats;
} file_t;

file_t *file_create(char const *file_path, int const file_mode);
char *file_get_line(file_t *file);
char *file_get_content(file_t *file);
void file_write(file_t *file, char *str);
void file_fwrite(file_t *file, char *fmt, ...);
void file_close(file_t *file);
void file_free(file_t *file);


#endif /* INCLUDE_MY_FILE_ */
