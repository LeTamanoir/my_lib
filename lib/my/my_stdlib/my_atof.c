/*
** EPITECH PROJECT, 2022
** my_atof
** File description:
** atof clone
*/

double my_atof(char const *str)
{
    double sign = 1;
    double number = 0;
    double pow_10 = 1;
    int idx = 0;
    int inc_pow = 0;

    while (str[idx] != '\0') {
        if (str[idx] == '-')
            sign *= -1;
        if (str[idx] != '+' && str[idx] != '-' &&
            str[idx] >= '0' && str[idx] <= '9') {
            number = number * 10 + (str[idx] - '0');
            pow_10 = (inc_pow) ? pow_10 * 10 : pow_10;
        }
        if (str[idx] == '.') inc_pow = 1;
        if (str[idx] != '+' && str[idx] != '-' && str[idx] != '.' &&
            (str[idx] > '9' || str[idx] < '0')) break;
        idx++;
    }
    return sign * (number / pow_10);
}
