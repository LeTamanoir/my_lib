/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** displays N if param is negative else P
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }

    return (0);
}
