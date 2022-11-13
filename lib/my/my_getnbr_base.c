/*
** EPITECH PROJECT, 2022
** my_getnbr_base.c
** File description:
** returns a number into base 10 from a given base
*/

#include "my_math.h"
#include "my_string.h"

static int get_chr_base(char digit, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (base[i] == digit) {
            return i;
        }
    }
    return 0;
}

static void compute_sign(char const *str, int *sign_cnt, int *is_neg)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            ++*sign_cnt;
            *is_neg = *is_neg * -1;
        }
        if (str[i] == '+')
            ++*sign_cnt;
    }
}

int my_getnbr_base(char const *str, char const *base)
{
    int base_int = my_strlen(base);
    int str_len = my_strlen(str) - 1;
    int computed_nbr = 0;
    int sign_cnt = 0;
    int is_neg = 1;
    if (base_int <= 1 || str[0] == '0') return 0;
    compute_sign(str, &sign_cnt, &is_neg);

    for (int i = sign_cnt; str[i] != '\0'; i++) {
        int my_pow_res = my_pow(base_int, str_len - i);
        int nbr_from_chr = get_chr_base(str[i], base);
        if (my_pow_res == -1) return 0;
        computed_nbr += nbr_from_chr * my_pow_res;
    }

    return computed_nbr * is_neg;
}
