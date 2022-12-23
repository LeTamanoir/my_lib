/*
** EPITECH PROJECT, 2022
** my_file
** File description:
** get_line
*/

#include "my_file.h"
#include "my_str.h"
#include "my_stdio.h"
#include "my_stdlib.h"

int get_nl_idx(char *buff, int size)
{
    for (int i = 0; i < size; i++)
        if (buff[i] == '\n')
            return i;

    return size;
}

int add_from_cache(file_t *file)
{
    str_t *cache = file->__cache;
    int new_nl = get_nl_idx(cache->data, cache->length);
    int add_next = new_nl != cache->length;

    str_nadd(file->content, cache->data, new_nl);
    str_slice(cache, new_nl + add_next, cache->length);

    return !add_next;
}

int add_from_read(file_t *file)
{
    str_t *cache = file->__cache;
    int size = 0;
    int new_nl = 0;

    while ((size = read(file->fd, cache->data, cache->capacity)) != 0) {
        cache->length = size;
        new_nl = get_nl_idx(cache->data, cache->length);

        if (new_nl != cache->length) {
            str_nadd(file->content, cache->data, new_nl);
            str_slice(cache, new_nl + 1, cache->length);
            break;
        }
    }

    return size;
}
