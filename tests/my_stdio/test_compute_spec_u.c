/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %u
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include <stdint.h>

#include "specifiers.h"
#include "my_stdio.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_uint_modifier_unknow, .init = redirect_all_std)
{
    int out = 123;
    my_printf("%wu", out);
    cr_assert_stdout_eq_str("%wu");
}

Test(my_printf, test_uint_modifier_l, .init = redirect_all_std)
{
    long int out = 123;
    my_printf("%lu", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_uint_modifier_ll, .init = redirect_all_std)
{
    long long int out = 123;
    my_printf("%llu", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_uint_modifier_h, .init = redirect_all_std)
{
    short int out = 123;
    my_printf("%hu", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_uint_modifier_hh, .init = redirect_all_std)
{
    signed char out = 122;
    my_printf("%hhu", out);
    cr_assert_stdout_eq_str("122");
}

Test(my_printf, test_uint_modifier_j, .init = redirect_all_std)
{
    intmax_t out = 123;
    my_printf("%ju", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_uint_modifier_z, .init = redirect_all_std)
{
    size_t out = 123;
    my_printf("%zu", out);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_uint_modifier_tt, .init = redirect_all_std)
{
    ptrdiff_t out = 123;
    my_printf("%tu", out);
    cr_assert_stdout_eq_str("123");
}

Test(compute_spec_u, simple_unsigned_short_int) {
    unsigned long long int input;
    input = (unsigned short)6535;
    char *res = compute_spec_u(&input);
    cr_assert_str_eq(res, "6535");
}

Test(compute_spec_u, test_max_unsigned_short_int) {
    unsigned long long int input;
    input = (unsigned short)65535;
    char *res = compute_spec_u(&input);
    cr_assert_str_eq(res, "65535");
}

Test(compute_spec_u, simple_unsigned_int) {
    unsigned long long int input;
    input = (unsigned int)2555555555;
    char *res = compute_spec_u(&input);
    cr_assert_str_eq(res, "2555555555");
}

Test(compute_spec_u, test_max_unsigned_int) {
    unsigned long long int input;
    input = (unsigned int)4294967295;
    char *res = compute_spec_u(&input);
    cr_assert_str_eq(res, "4294967295");
}

Test(compute_spec_u, simple_unsigned_long_int) {
    unsigned long long int input;
    input = (unsigned long long)184674907340945961;
    char *res = compute_spec_u(&input);
    cr_assert_str_eq(res, "184674907340945961");
}

Test(compute_spec_u, test_unsigned_long_int) {
    unsigned long long int input;
    input = (unsigned long long)1844674407370955145;
    char *res = compute_spec_u(&input);
    cr_assert_str_eq(res, "1844674407370955145");
}
