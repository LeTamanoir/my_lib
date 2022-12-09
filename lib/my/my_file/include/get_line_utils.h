/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file getters
*/

#include "my_file.h"
#include "my_str.h"

#pragma once

void clear_buffer(char *buffer);
int get_newline_idx(char *buffer, int size);
void add_from_cache(file_t *file, str_t *line, int *can_stop);
int add_from_read(file_t *file, str_t *line);
