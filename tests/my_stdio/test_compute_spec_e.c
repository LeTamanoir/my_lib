/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %e and %E
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <math.h>

#include "specifiers.h"
#include "my_stdio.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(compute_spec_lo_e, simple_loexp, .init = redirect_all_std) {
    my_printf("%e\n", 1.00 / 3.00);
    cr_assert_stdout_eq_str("3.333333e-01\n");
}

Test(compute_spec_lo_e, simple_loexp_negative, .init = redirect_all_std) {
    my_printf("%e\n", -1.00 / 3.00);
    cr_assert_stdout_eq_str("-3.333333e-01\n");
}

Test(compute_spec_lo_e, simple_loexp_big_nb, .init = redirect_all_std) {
    my_printf("%e\n", 100000000000000000.0);
    cr_assert_stdout_eq_str("1.000000e+17\n");
}

Test(compute_spec_lo_e, simple_loexp_small_nb, .init = redirect_all_std) {
    my_printf("%e\n", 1.0);
    cr_assert_stdout_eq_str("1.000000e+00\n");
}

Test(compute_spec_lo_e, simple_loexp_small_nb_no_dec, .init = redirect_all_std) {
    my_printf("%e\n", 0.4);
    cr_assert_stdout_eq_str("4.000000e-01\n");
}

Test(compute_spec_lo_e, simple_loexp_small_nb_mult_dec, .init = redirect_all_std) {
    my_printf("%e\n", 0.004);
    cr_assert_stdout_eq_str("4.000000e-03\n");
}

Test(compute_spec_lo_e, simple_loexp_very_small_nb, .init = redirect_all_std) {
    my_printf("%e\n", 1.000005);
    cr_assert_stdout_eq_str("1.000005e+00\n");
}

Test(compute_spec_lo_e, null_with_e, .init = redirect_all_std) {
    my_printf("%e\n", 0.00);
    cr_assert_stdout_eq_str("0.000000e+00\n");
}

Test(compute_spec_lo_e, loexp_with_big_pres, .init = redirect_all_std) {
    my_printf("%.1000e\n", 1.00 / 2.00);
    cr_assert_stdout_eq_str("5.00000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
000000000000000000000000000000000e-01\n");
}

Test(compute_spec_lo_e, error_inf) {
    double input = INFINITY;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "inf");
}

Test(compute_spec_lo_e, error_negative_inf) {
    double input = -INFINITY;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "-inf");
}

Test(compute_spec_lo_e, error_nan) {
    double input = NAN;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "nan");
}

Test(compute_spec_lo_e, error_negative_nan) {
    double input = -NAN;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "-nan");
}

Test(compute_spec_lo_e, long_double_error_inf) {
    double input = INFINITY;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "inf");
}

Test(compute_spec_lo_e, long_double_error_negative_inf) {
    double input = -INFINITY;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "-inf");
}

Test(compute_spec_lo_e, long_double_error_nan) {
    double input = NAN;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "nan");
}

Test(compute_spec_lo_e, long_double_error_negative_nan) {
    double input = -NAN;
    char *res = compute_spec_lo_e(&input);
    cr_assert_str_eq(res, "-nan");
}


Test(compute_spec_up_e, simple_upexp, .init = redirect_all_std) {
    my_printf("%E\n", 1.00 / 3.00);
    cr_assert_stdout_eq_str("3.333333E-01\n");
}

Test(compute_spec_up_e, upexp_with_big_pres, .init = redirect_all_std) {
    my_printf("%.1000E\n", 1.00 / 2.00);
    cr_assert_stdout_eq_str("5.00000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
00000000000000000000000000000000000000000000000000000000000000000000000\
000000000000000000000000000000000E-01\n");
}

Test(compute_spec_up_e, error_inf) {
    double input = INFINITY;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "inf");
}

Test(compute_spec_up_e, error_negative_inf) {
    double input = -INFINITY;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "-inf");
}

Test(compute_spec_up_e, error_nan) {
    double input = NAN;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "nan");
}

Test(compute_spec_up_e, error_negative_nan) {
    double input = -NAN;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "-nan");
}

Test(compute_spec_up_e, long_double_error_inf) {
    double input = INFINITY;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "inf");
}

Test(compute_spec_up_e, long_double_error_negative_inf) {
    double input = -INFINITY;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "-inf");
}

Test(compute_spec_up_e, long_double_error_nan) {
    double input = NAN;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "nan");
}

Test(compute_spec_up_e, long_double_error_negative_nan) {
    double input = -NAN;
    char *res = compute_spec_up_e(&input);
    cr_assert_str_eq(res, "-nan");
}
