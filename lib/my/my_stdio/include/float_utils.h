/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** utils for float specifiers
*/

#pragma once

typedef union inspector_u {
    double nb;
    long bytes;
} inspector_t;

char *handle_errors_float(double nb, int upper);

char *compute_double(double nb);

#define DOUBLE_PRECISION (2048 * 2)

void round_float(char **float_str, char next_chr, char spec);
