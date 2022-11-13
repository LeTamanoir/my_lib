/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %g and %G
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

Test(compute_spec_lo_g, prefer_spe_e, .init = redirect_all_std) {
    my_printf("%g\n", 1234567.0);
    cr_assert_stdout_eq_str("1.23457e+06\n");
}

Test(compute_spec_lo_g, prefer_spe_f, .init = redirect_all_std) {
    my_printf("%g\n", 123456.0);
    cr_assert_stdout_eq_str("123456\n");
}

Test(compute_spec_lo_g, prefer_spe_f_test, .init = redirect_all_std) {
    my_printf("%-20g\n", 1234.56);
    cr_assert_stdout_eq_str("1234.56             \n");
}

Test(compute_spec_lo_g, error_inf, .init = redirect_all_std) {
    double input = 5.00 / 0.00;
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("inf\n");
}

Test(compute_spec_lo_g, error_nelo_gative_inf, .init = redirect_all_std) {
    double input = -5.00 / 0.00;
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("-inf\n");
}

Test(compute_spec_lo_g, error_nan, .init = redirect_all_std) {
    double input = 0.00 / 0.00;
    *(long *)&input = (*(long *)&input) ^ (1l << 63);
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("nan\n");
}

Test(compute_spec_lo_g, error_nelo_gative_nan, .init = redirect_all_std) {
    double input = 0.00 / 0.00;
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("-nan\n");
}

Test(compute_spec_lo_g, lonlo_g_double_error_inf, .init = redirect_all_std) {
    double input = 5.00 / 0.00;
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("inf\n");
}

Test(compute_spec_lo_g, lonlo_g_double_error_nelo_gative_inf, .init = redirect_all_std) {
    double input = -5.00 / 0.00;
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("-inf\n");
}

Test(compute_spec_lo_g, lonlo_g_double_error_nan, .init = redirect_all_std) {
    double input = 0.00 / 0.00;
    *(long *)&input = (*(long *)&input) ^ (1l << 63);
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("nan\n");
}

Test(compute_spec_lo_g, lonlo_g_double_error_nelo_gative_nan, .init = redirect_all_std) {
    double input = 0.00 / 0.00;
    my_printf("%g\n", input);
    cr_assert_stdout_eq_str("-nan\n");
}