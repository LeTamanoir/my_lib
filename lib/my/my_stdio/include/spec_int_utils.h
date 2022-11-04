/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** declarations for the utils
*/

#pragma once

int my_int_nbr_length(long long int nb);

int my_uint_nbr_length(unsigned long long int nb);

int get_base_nbr_length(unsigned long long int nb, int base);

void compute_number(
    char *str, char const *base,
    unsigned long long int nb, int *utils
);

void remove_useless_zeros(char *str);
