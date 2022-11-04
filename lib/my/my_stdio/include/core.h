/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations of core functions
*/

#include <stdarg.h>

#include "buffer.h"

#pragma once

int compute_char(va_list ap, buffer_t *buffer, const char *format);
