/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for buffer
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "buffer.h"

int get_buffer_length(buffer_t *node)
{
    int size = 0;

    while (node != NULL) {
        size += my_strlen(node->content);
        node = node->next;
    }

    return size;
}

void print_buffer(buffer_t *buffer, int fd)
{
    int size = get_buffer_length(buffer);
    char *to_write = my_calloc('\0', sizeof(char) * (size + 1));

    while (buffer != NULL) {
        my_strcat(to_write, buffer->content);
        buffer = buffer->next;
    }

    write(fd, to_write, size);

    free(to_write);
}
