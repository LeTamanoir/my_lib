/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for speficier %d and %i
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

Test(my_printf, test_int_modifier_unknow, .init = redirect_all_std)
{
    int out = 123;
    my_printf("%wd", out);
    cr_assert_stdout_eq_str("%wd");
}

Test(my_printf, test_int_modifier_l, .init = redirect_all_std)
{
    long int out = 123;
    my_printf("%ld", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_int_modifier_ll, .init = redirect_all_std)
{
    long long int out = 123;
    my_printf("%lld", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_int_modifier_h, .init = redirect_all_std)
{
    short int out = 123;
    my_printf("%hd", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_int_modifier_hh, .init = redirect_all_std)
{
    signed char out = 122;
    my_printf("%hhd", out);
    cr_assert_stdout_eq_str("122");
}

Test(my_printf, test_int_modifier_j, .init = redirect_all_std)
{
    intmax_t out = 123;
    my_printf("%jd", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_int_modifier_z, .init = redirect_all_std)
{
    size_t out = 123;
    my_printf("%zd", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_int_modifier_tt, .init = redirect_all_std)
{
    ptrdiff_t out = 123;
    my_printf("%td", out);
    cr_assert_stdout_eq_str("123");
}

Test(compute_spec_d, simple_short_int) {
    long long int short_input;
    short_input = (short int)15685;
    char *res = compute_spec_d(&short_input);
    cr_assert_str_eq(res, "15685");
}

Test(compute_spec_d, simple_negative_short_int) {
    long long int short_input;
    short_input = (short int)-2549;
    char *res = compute_spec_d(&short_input);
    cr_assert_str_eq(res, "-2549");
}

Test(compute_spec_d, min_short_int) {
    long long int short_input;
    short_input = (short int)-32768;
    char *res = compute_spec_d(&short_input);
    cr_assert_str_eq(res, "-32768");
}

Test(compute_spec_d, max_short_int) {
    long long int short_input;
    short_input = (short int)32767;
    char *res = compute_spec_d(&short_input);
    cr_assert_str_eq(res, "32767");
}

Test(compute_spec_d, simple_int) {
    long long int input;
    input = (int)486;
    char *res = compute_spec_d(&input);
    cr_assert_str_eq(res, "486");
}

Test(compute_spec_d, simple_negative_int) {
    long long int input;
    input = (int)-484;
    char *res = compute_spec_d(&input);
    cr_assert_str_eq(res, "-484");
}

Test(compute_spec_d, min_int) {
    long long int input;
    input = (int)-2147483648;
    char *res = compute_spec_d(&input);
    cr_assert_str_eq(res, "-2147483648");
}

Test(compute_spec_d, max_int) {
    long long int input;
    input = (int)2147483647;
    char *res = compute_spec_d(&input);
    cr_assert_str_eq(res, "2147483647");
}

Test(compute_spec_d, simple_long_int) {
    long long int long_input;
    long_input = (long int)123456789075;
    char *res = compute_spec_d(&long_input);
    cr_assert_str_eq(res, "123456789075");
}

Test(compute_spec_d, simple_negative_long_int) {
    long long int long_input;
    long_input = (long int)-123456789075;
    char *res = compute_spec_d(&long_input);
    cr_assert_str_eq(res, "-123456789075");
}

Test(compute_spec_d, max_long_int) {
    long long int long_input;
    long_input = (long int)9223372036854775807;
    char *res = compute_spec_d(&long_input);
    cr_assert_str_eq(res, "9223372036854775807");
}
