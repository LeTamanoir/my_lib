/*
** EPITECH PROJECT, 2022
** my_math
** File description:
** declarations
*/

#include <math.h>

#pragma once

int my_pow(int number, int power);
int my_int_sqrt(int nb);
int my_is_prime(int nb);
void my_sort_int_array(int *tab, int size);
int my_nbr_length(long long nb);
long long my_ll_pow(long long number, int power);

typedef struct vec_s {
    int x;
    int y;
} vec_t;
