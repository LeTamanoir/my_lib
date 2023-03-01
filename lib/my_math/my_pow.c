/*
** EPITECH PROJECT, 2023
** my_pow.c
** File description:
** pow functions
*/

int my_pow(int number, unsigned int power)
{
    int num = 1;

    while (power--)
        num = num * number;

    return num;
}

long int my_powl(long int number, unsigned int power)
{
    long int num = 1;

    while (power--)
        num = num * number;

    return num;
}

long long int my_powll(long long int number, unsigned int power)
{
    long long int num = 1;

    while (power--)
        num = num * number;

    return num;
}
