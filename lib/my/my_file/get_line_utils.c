/*
** EPITECH PROJECT, 2022
** my_file
** File description:
** get_line
*/

#include "my_file.h"
#include "my_str.h"
#include "my_stdio.h"

void clear_buffer(char *buffer)
{
    for (int i = 0; i < F_BUFF_SIZE; i++) {
        buffer[i] = '\0';
    }
}

int get_newline_idx(char *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n') {
            return i;
        }
    }
    return size;
}

void add_from_cache(file_t *file, str_t *line, int *can_stop)
{
    int new_line_idx = get_newline_idx(
        file->__line->content, file->__line->length
    );

    str_nadd(line, file->__line->content, new_line_idx);

    int slice_st = new_line_idx + (new_line_idx != file->__line->length);
    int slice_en = file->__line->length;

    if (new_line_idx == file->__line->length - 1) {
        *can_stop = 1;
    }
    str_slice(file->__line, slice_st, slice_en);
}

int add_from_read(file_t *file, str_t *line)
{
    char buffer[F_BUFF_SIZE + 1] = {0};
    int size = 0;
    int new_line_idx = 0;

    while ((size = read(file->fd, buffer, F_BUFF_SIZE)) != 0) {
        new_line_idx = get_newline_idx(buffer, F_BUFF_SIZE);
        str_nadd(line, buffer, new_line_idx);
        if (new_line_idx != F_BUFF_SIZE) {
            str_nadd(file->__line, &(buffer[new_line_idx + 1]),
                F_BUFF_SIZE - new_line_idx);
            break;
        }
        clear_buffer(buffer);
    }

    return size;
}
