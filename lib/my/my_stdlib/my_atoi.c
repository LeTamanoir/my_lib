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
    int idx = 0;

    while (str[idx] != '\0') {
        if (str[idx] == '-')
            sign *= -1;
        if (str[idx] != '+' && str[idx] != '-' &&
            str[idx] >= '0' && str[idx] <= '9') {
            error = test_overflow(number, str[idx] - '0', sign);
            number = number * 10 + (str[idx] - '0');
        }
        if (error) return 0;
        if (str[idx] != '+' && str[idx] != '-' &&
            (str[idx] > '9' || str[idx] < '0')) break;
        idx++;
    }
    return sign * number;
}
