/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %c
*/

#include <criterion/criterion.h>

#include "specifiers.h"

Test(compute_spec_c, simple_lower_char) {
    char *input = "a";
    char *res = compute_spec_c(input);
    cr_assert_str_eq(res, "a");
}

Test(compute_spec_c, simple_upper_char) {
    char *input = "A";
    char *res = compute_spec_c(input);
    cr_assert_str_eq(res, "A");
}

Test(compute_spec_c, simple_char_nb) {
    char *input = "5";
    char *res = compute_spec_c(input);
    cr_assert_str_eq(res, "5");
}

Test(compute_spec_c, char_return) {
    char *input = "\n:";
    char *res = compute_spec_c(input);
    cr_assert_str_eq(res, "\n");
}
