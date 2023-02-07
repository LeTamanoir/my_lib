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

mat_t *matrix_create(vec2i_t d)
{
    mat_t *mat = my_malloc(sizeof(mat_t));
    mat->m = my_malloc(sizeof(double *) * d.y);
    mat->x = d.x;
    mat->y = d.y;

    for (int i = 0; i < d.y; i++) {
        mat->m[i] = my_malloc(sizeof(double) * d.x);

        for (int j = 0; j < d.x; j++) {
            mat->m[i][j] = 0.0;
        }
    }

    return mat;
}

void matrix_free(mat_t *mat)
{
    for (int i = 0; i < mat->y; i++)
        my_free(mat->m[i]);

    my_free(mat->m);
    my_free(mat);
}
