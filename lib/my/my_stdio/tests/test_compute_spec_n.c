/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %n
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <stdint.h>

#include "my.h"
#include "specifiers.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(compute_spec_n, simple_flag_n, .init = redirect_all_std)
{
    int out = 0;
    my_printf("Hello world%n", &out);
    cr_assert_eq(out, 11);
}

Test(compute_spec_n, one_char, .init = redirect_all_std)
{
    int out = 0;
    my_printf("H%n", &out);
    cr_assert_eq(out, 1);
}

Test(compute_spec_n, 64_char, .init = redirect_all_std)
{
    int out = 0;
    my_printf("HelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHelloHell%n", &out);
    cr_assert_eq(out, 64);
}

Test(compute_spec_n, 200_char, .init = redirect_all_std)
{
    int out = 0;
    my_printf("%200s%n", "1", &out);
    cr_assert_eq(out, 200);
}

Test(compute_spec_n, 12000_char, .init = redirect_all_std)
{
    int out = 0;
    my_printf("%12000s%n", "1", &out);
    cr_assert_eq(out, 12000);
}

Test(compute_spec_n, use_100k_in_char, .init = redirect_all_std)
{
    int out = 0;
    my_printf("%100000s%n", "1", &out);
    cr_assert_eq(out, 100000);
}

Test(compute_spec_n, no_modifier, .init = redirect_all_std)
{
    int out = 0;
    my_printf("hellothere%n\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, modifier_l, .init = redirect_all_std)
{
    long int out = 0;
    my_printf("hellothere%ln\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, modifier_ll, .init = redirect_all_std)
{
    long long int out = 0;
    my_printf("hellothere%lln\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, no_modifier_h, .init = redirect_all_std)
{
    short int out = 0;
    my_printf("hellothere%hn\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, no_modifier_hh, .init = redirect_all_std)
{
    signed char out;
    my_printf("hellothere%hhn\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, no_modifier_j, .init = redirect_all_std)
{
    intmax_t out = 0;
    my_printf("hellothere%jn\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, no_modifier_z, .init = redirect_all_std)
{
    size_t out = 0;
    my_printf("hellothere%zn\n", &out);
    cr_assert_eq(out, 10);
}

Test(compute_spec_n, no_modifier_tt, .init = redirect_all_std)
{
    ptrdiff_t out = 0;
    my_printf("hellothere%tn\n", &out);
    cr_assert_eq(out, 10);
}
