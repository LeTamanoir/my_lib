/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %f and %F
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

Test(compute_spec_lo_f, simple_lofloat_big_round, .init = redirect_all_std) {
    my_printf("%.3f\n", 9.99999);
    cr_assert_stdout_eq_str("10.000\n");
}

Test(compute_spec_lo_f, simple_lofloat_null, .init = redirect_all_std) {
    my_printf("%.0f\n", 1.5);
    cr_assert_stdout_eq_str("2\n");
}

Test(compute_spec_lo_f, simple_lofloat, .init = redirect_all_std) {
    my_printf("%f\n", 1.00 / 3.00);
    cr_assert_stdout_eq_str("0.333333\n");
}

Test(compute_spec_lo_f, simple_neg_lofloat, .init = redirect_all_std) {
    my_printf("%f\n", -1.00 / 3.00);
    cr_assert_stdout_eq_str("-0.333333\n");
}

Test(compute_spec_lo_f, lofloat_with_big_pres, .init = redirect_all_std) {
    my_printf("%.1000f\n", 1.00 / 2.00);
    cr_assert_stdout_eq_str("0.50000000000000000000000000000000000000000000\
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
000000000000000000000000000000000\n");
}

Test(compute_spec_lo_f, nannannan, .init = redirect_all_std) {
    double in = nan("");
    my_printf("%f\n", in);
    cr_assert_stdout_eq_str("nan\n");
}

Test(compute_spec_lo_f, error_inf) {
    double input;
    input = (double)5.00 / 0.00;
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "inf");
}

Test(compute_spec_lo_f, error_negative_inf) {
    double input;
    input = (double)-5.00 / 0.00;
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "-inf");
}

Test(compute_spec_lo_f, error_nan) {
    double input;
    input = (double)nan("");
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "nan");
}

Test(compute_spec_lo_f, error_negative_nan) {
    double input;
    input = (double)0.00 / 0.00;
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "-nan");
}

Test(compute_spec_lo_f, long_double_error_inf) {
    double input;
    input = (double)5.00 / 0.00;
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "inf");
}

Test(compute_spec_lo_f, long_double_error_negative_inf) {
    double input;
    input = (double)-5.00 / 0.00;
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "-inf");
}

Test(compute_spec_lo_f, long_double_error_nan) {
    double input;
    input = (double)nan("");
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "nan");
}

Test(compute_spec_lo_f, long_double_error_negative_nan) {
    double input;
    input = (double)0.00 / 0.00;
    char *res = compute_spec_lo_f(&input);
    cr_assert_str_eq(res, "-nan");
}

Test(compute_spec_up_f, simple_upfloat, .init = redirect_all_std) {
    my_printf("%F\n", 1.00 / 3.00);
    cr_assert_stdout_eq_str("0.333333\n");
}

Test(compute_spec_up_f, simple_neg_upfloat, .init = redirect_all_std) {
    my_printf("%f\n", -1.00 / 3.00);
    cr_assert_stdout_eq_str("-0.333333\n");
}

Test(compute_spec_up_f, upfloat_with_big_pres, .init = redirect_all_std) {
    my_printf("%.1000F\n", 1.00 / 2.00);
    cr_assert_stdout_eq_str("0.50000000000000000000000000000000000000000000\
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
000000000000000000000000000000000\n");
}

Test(compute_spec_up_f, error_inf) {
    double input;
    input = (double)5.00 / 0.00;
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "INF");
}

Test(compute_spec_up_f, error_negative_inf) {
    double input;
    input = (double)-5.00 / 0.00;
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "-INF");
}

Test(compute_spec_up_f, error_nan) {
    double input;
    input = (double)nan("");
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "NAN");
}

Test(compute_spec_up_f, error_negative_nan) {
    double input;
    input = (double)0.00 / 0.00;
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "-NAN");
}

Test(compute_spec_up_f, long_double_error_inf) {
    double input;
    input = (double)5.00 / 0.00;
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "INF");
}

Test(compute_spec_up_f, long_double_error_negative_inf) {
    double input;
    input = (double)-5.00 / 0.00;
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "-INF");
}

Test(compute_spec_up_f, long_double_error_nan) {
    double input;
    input = (double)nan("");
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "NAN");
}

Test(compute_spec_up_f, long_double_error_negative_nan) {
    double input;
    input = (double)(0.00 / 0.00);
    char *res = compute_spec_up_f(&input);
    cr_assert_str_eq(res, "-NAN");
}
