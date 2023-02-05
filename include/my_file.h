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

    #include "my_str.h"

    #define F_R         (O_RDONLY)
    #define F_W         (O_WRONLY)
    #define F_RW        (O_RDWR)
    #define F_A         (O_APPEND)
    #define F_C         (O_CREAT)
    #define F_T         (O_TRUNC)


typedef struct file_s {
    int fd;
    str_t *file_path;
    str_t *content;
    str_t *current_line;
    str_t *__cache;
    struct stat stats;
} file_t;

/**
 * @brief creates a new file instance
 *
 * @param file_path     the path of the file to open
 * @param file_mode     the mode in which the file will be open
 * @return a new file instance or NULL if there was an error
 */
file_t *file_create(char const *file_path, int const file_mode);

/**
 * @brief gets a new line in a file stored in a string
 *
 * @param file  the file to get the line from
 * @return the new line in the file
 */
str_t *file_get_line(file_t *file);

/**
 * @brief loads the content of the file into file->content
 *
 * @param file  the file for wichi you want to load the content
 * @return the content of the file
 */
str_t *file_get_content(file_t *file);

/**
 * @brief writes a char * into a file
 *
 * @param file  the file to write to
 * @param str   the char* to write
 */
void file_write(file_t *file, char const *str);

/**
 * @brief writes a str_t into a file
 *
 * @param file  the file to write to
 * @param str   the str_t to write
 */
void file_strwrite(file_t *file, str_t const *str);

/**
 * @brief writes a formatted char* into a file (using printf syntax)
 *
 * @param file  the file to write to
 * @param fmt   the format string
 * @param ...   printf like arguments
 */
void file_fwrite(file_t *file, char const *fmt, ...);

/**
 * @brief closes a file
 *
 * @param file  the file to close
 */
void file_close(file_t *file);

/**
 * @brief closes a file and frees its dependecies
 *
 * @param ptr  the file to close and free
 */
void file_free(void *ptr);

/**
 * @brief create a file instance from a FD
 *
 * @param fd    the FD
 * @return the created file instance
 */
file_t *file_dcreate(int fd);


#endif /* INCLUDE_MY_FILE_ */
