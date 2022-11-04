/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** buffer type declarations
*/

#pragma once

typedef struct buffer_s {
    char *content;
    struct buffer_s *next;
} buffer_t;

buffer_t *create_buffer(void);

buffer_t *increase_buffer(buffer_t *last_node);

buffer_t *add_chr_to_buffer(buffer_t *buffer, char c);

buffer_t *add_str_to_buffer(buffer_t *buffer, char *str);

void print_buffer(buffer_t *buffer, int fd);

int get_buffer_length(buffer_t *node);

#define BUFF_MAX_SIZE 64
