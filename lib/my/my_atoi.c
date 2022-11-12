/*
** EPITECH PROJECT, 2022
** my_atoi.c
** File description:
** returns a number from a string
*/

static int test_overflow(int number, int to_add, int sign)
{
    int calc = number * 10 + to_add;

    if (sign == -1)
        calc--;

    return calc < 0;
}

int my_atoi(char const *str)
{
    int sign = 1;
    int number = 0;
    int error = 0;

    while (*str != '\0') {
        if (*str == '-')
            sign = sign * -1;
        if (*str != '+' && *str != '-' && *str >= '0' && *str <= '9') {
            error = test_overflow(number, *str - 48, sign);
            number = number * 10 + (*str - 48);
        }
        if (error)
            return 0;
        if (*str != '+' && *str != '-' && (*str > '9' || *str < '0'))
            break;
        str++;
    }
    return sign * number;
}
