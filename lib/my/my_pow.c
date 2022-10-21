/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** returns the power of number
*/

#include "my.h"

int my_pow(int number, int power)
{
    int num = 1;

    for (int i = 0; i < power; i++) {
        int test = my_detect_overflow(num, number);
        if (test) return -1;
        num = num * number;
    }

    return num;
}
