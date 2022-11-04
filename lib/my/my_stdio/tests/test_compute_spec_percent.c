/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %%
*/

#include <criterion/criterion.h>

#include "specifiers.h"

Test(compute_spec_percent, sent_an_int) {
    int input = 0;
    char *res = compute_spec_percent(&input);
    cr_assert_str_eq(res, "%");
}

Test(compute_spec_percent, sent_an_char) {
    char *input = "Hello world!";
    char *res = compute_spec_percent(&input);
    cr_assert_str_eq(res, "%");
}

Test(compute_spec_percent, sent_an_double) {
    double input = 486.6878;
    char *res = compute_spec_percent(&input);
    cr_assert_str_eq(res, "%");
}

Test(compute_spec_percent, sent_an_float) {
    float input = 5.4;
    char *res = compute_spec_percent(&input);
    cr_assert_str_eq(res, "%");
}
