/*
** EPITECH PROJECT, 2022
** my_file
** File description:
** get_line
*/

#include "my_file.h"
#include "my_string.h"

void clear_buffer(char *buffer)
{
    for (int i = 0; i < F_BUFF_SIZE; i++) {
        buffer[i] = 0;
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

void add_from_cache(file_t *this, string_t *line)
{
    int new_line_idx = get_newline_idx(
        this->__line->content, this->__line->length
    );

    line->nadd(line, this->__line->content, new_line_idx
    );

    int slice_st = new_line_idx + (new_line_idx != this->__line->length);
    int slice_en = this->__line->length;

    this->__line->slice(this->__line, slice_st, slice_en);
}

int add_from_read(file_t *this, string_t *line)
{
    char buffer[F_BUFF_SIZE] = {0};
    int size = 0;
    int new_line_idx = 0;

    while ((size = read(this->fd, buffer, F_BUFF_SIZE)) != 0) {
        new_line_idx = get_newline_idx(buffer, F_BUFF_SIZE);
        line->nadd(line, buffer, new_line_idx);
        if (new_line_idx != F_BUFF_SIZE) {
            this->__line->nadd(this->__line, &(buffer[new_line_idx + 1]),
                F_BUFF_SIZE - new_line_idx - 1);
            break;
        }
        clear_buffer(buffer);
    }

    return size;
}
