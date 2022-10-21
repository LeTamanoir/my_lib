/*
** EPITECH PROJECT, 2022
** my_showmem.c
** File description:
** prints number into a given base
*/

#include "my.h"

static void print_adress(int row)
{
    for (int i = 0; i < 6 - row / 16 + (row == 0); i++)
        my_putchar('0');
    my_putnbr_base(row * 16, "0123456789abcdef");
}

static int print_hexdump(char const *str, int row, int size)
{
    for (int i = row * 16; i < (row + 1) * 16; i++) {
        if (i >= size)
            return ((row + 1) * 16 - i) * 2.5 - (i % 2 == 0);

        if (str[i] >= '\0' && str[i] <= '\x0F')
            my_putchar('0');
        my_putnbr_base(str[i], "0123456789abcdef");

        if ((i + 1) % 2 == 0)
            my_putchar(' ');
    }

    return -1;
}

static void print_trailwing_space(int nbr)
{
    if (nbr == -1) return;

    for (int i = 0; i <= nbr; i++) {
        my_putchar(' ');
    }
}

static void print_text(char const *str, int row, int size)
{
    for (int i = row * 16; i < (row + 1) * 16; i++) {
        if (i >= size)
            return;
        if (str[i] >= ' ' && str[i] <= '~') {
            my_putchar(str[i]);
            continue;
        }

        my_putchar('.');
    }
}

int my_showmem(char const *str, int size)
{
    int row = 0;
    int max_row = size / 16 + (size % 16 != 0);

    while (row < max_row) {
        print_adress(row);
        my_putchar(':');
        my_putchar(' ');
        int last_chr = print_hexdump(str, row, size);
        print_trailwing_space(last_chr);
        print_text(str, row, size);
        my_putchar('\n');
        row++;
    }

    return 0;
}
