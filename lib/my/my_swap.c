/*
** EPITECH PROJECT, 2022
** my_swap.c
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
