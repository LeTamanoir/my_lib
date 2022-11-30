/*
** EPITECH PROJECT, 2022
** my_file.h
** File description:
** file getters
*/

#include "my_file.h"
#include "my_string.h"

#pragma once

char *file_get_line(file_t *this);
char *file_get_content(file_t *this);

void clear_buffer(char *buffer);
int get_newline_idx(char *buffer, int size);
void add_from_cache(file_t *this, string_t *line);
int add_from_read(file_t *this, string_t *line);
