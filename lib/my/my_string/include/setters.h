/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** string setters
*/

#include "my_string.h"

#pragma once

void string_add(string_t *this, char *new);

void string_nadd(string_t *this, char *new, int n);

void string_fadd(string_t *this, char *fmt, ...);

void string_slice(string_t *this, int start, int end);
