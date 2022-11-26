/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** my_stdio declarations
*/

#include <unistd.h>

#pragma once

int my_printf(const char *format, ...);

int my_sprintf(char *str, const char *format, ...);

int my_dprintf(int fd, const char * format, ...);

void my_putchar(char c);

int my_putstr(char const *str);

int my_putstderr(char const *str);

int my_put_nbr(int nb);

int my_puts(char const *str);

int my_showmem(char const *str, int size);
