/*
** EPITECH PROJECT, 2022
** my_base.h
** File description:
** my_base declarations
*/


#pragma once

int my_putnbr_base(int nbr, char const *base);

int my_getnbr_base(char const *str, char const *base);

char *my_convert_base(
    char const *nbr,
    char const *base_from,
    char const *base_to
);
