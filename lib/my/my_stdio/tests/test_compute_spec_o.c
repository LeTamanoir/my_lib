/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %o
*/

#include <criterion/criterion.h>

#include "specifiers.h"

Test(compute_spec_o, oct) {
    unsigned long long int input;
    input = (unsigned int)042;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "42");
}

Test(compute_spec_o, hex_to_oct) {
    unsigned long long int input;
    input = (unsigned int)0x42;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "102");
}

Test(compute_spec_o, int_to_oct) {
    unsigned long long int input;
    input = (unsigned int)42;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "52");
}

Test(compute_spec_o, bin_to_oct) {
    unsigned long long int input;
    input = (unsigned int)0b101010;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "52");
}

Test(compute_spec_o, test_max_unsigned_oct) {
    unsigned long long int input;
    input = (unsigned int)037777777777;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "37777777777");
}

Test(compute_spec_o, convert_max_unsigned_int_to_oct) {
    unsigned long long int input;
    input = (unsigned int)4294967295;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "37777777777");
}

Test(compute_spec_o, convert_max_unsigned_hex_to_oct) {
    unsigned long long int input;
    input = (unsigned int)0xFFFFFFFF;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "37777777777");
}

Test(compute_spec_o, convert_max_unsigned_bin_to_oct) {
    unsigned long long int input;
    input = (unsigned int)0b11111111111111111111111111111111;
    char *res = compute_spec_o(&input);
    cr_assert_str_eq(res, "37777777777");
}
