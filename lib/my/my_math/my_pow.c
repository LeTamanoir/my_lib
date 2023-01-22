/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** pow functions
*/

int my_pow(long long number, int power)
{
    long long num = 1;

    for (int i = 0; i < power; i++)
        num = num * number;

    return num;
}

long int my_powl(long int number, int power)
{
    long int num = 1;

    for (int i = 0; i < power; i++)
        num = num * number;

    return num;
}

long long int my_powll(long long int number, int power)
{
    long long int num = 1;

    for (int i = 0; i < power; i++)
        num = num * number;

    return num;
}
