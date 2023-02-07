/*
** EPITECH PROJECT, 2022
** matric.c
** File description:
** matrix helper functions
*/

#include <stdarg.h>

#include "my_stdlib.h"
#include "my_stdio.h"
#include "my_matrix.h"

void matrix_print(mat_t *mat, int prec)
{
    for (int y = 0; y < mat->y; y++) {
        for (int x = 0; x < mat->x; x++) {
            my_printf("%s%.*f", (x != 0 ? "\t" : ""), prec, mat->m[y][x]);
        }

        my_printf("\n");
    }
}

mat_t *matrix_dup(mat_t *mat)
{
    mat_t *copy = matrix_create((vec2i_t){.x = mat->x, .y = mat->y});

    for (int y = 0; y < mat->y; y++)
        for (int x = 0; x < mat->x; x++)
            copy->m[y][x] = mat->m[y][x];

    return copy;
}

void matrix_fill(mat_t *mat, ...)
{
    va_list ap;

    va_start(ap, mat);
    for (int i = 0; i < mat->y; i++) {
        for (int j = 0; j < mat->x; j++) {
            mat->m[i][j] = va_arg(ap, double);
        }
    }
    va_end(ap);
}
