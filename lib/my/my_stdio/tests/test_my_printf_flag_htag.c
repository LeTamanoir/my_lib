/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Tests for flag #
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"
#include "specifiers.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_flag_htag_with_b, .init = redirect_all_std)
{
    my_printf("%#b\n", 21);
    cr_assert_stdout_eq_str("0b10101\n");
}

Test(my_printf, test_flag_htag_with_o, .init = redirect_all_std)
{
    my_printf("%#o\n", 42);
    cr_assert_stdout_eq_str("052\n");
}

Test(my_printf, test_flag_htag_with_x, .init = redirect_all_std)
{
    my_printf("%#x\n", 84);
    cr_assert_stdout_eq_str("0x54\n");
}

Test(my_printf, test_flag_htag_with_up_x, .init = redirect_all_std)
{
    my_printf("%#X\n", 168);
    cr_assert_stdout_eq_str("0XA8\n");
}

Test(my_printf, test_flag_htag_with_b_zero, .init = redirect_all_std)
{
    my_printf("%#b\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_printf, test_flag_htag_with_o_zero, .init = redirect_all_std)
{
    my_printf("%#o\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_printf, test_flag_htag_with_x_zero, .init = redirect_all_std)
{
    my_printf("%#x\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_printf, test_flag_htag_with_up_x_zero, .init = redirect_all_std)
{
    my_printf("%#X\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_printf, test_flag_htag_with_a, .init = redirect_all_std)
{
    my_printf("%#a\n", 1.5);
    cr_assert_stdout_eq_str("0x1.8p+0\n");
}

Test(my_printf, test_flag_htag_with_a_zero, .init = redirect_all_std)
{
    my_printf("%#a\n", 500.00);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_flag_htag_with_up_a, .init = redirect_all_std)
{
    my_printf("%#A\n", 1.5);
    cr_assert_stdout_eq_str("0X1.8P+0\n");
}

Test(my_printf, test_flag_htag_with_up_a_zero, .init = redirect_all_std)
{
    my_printf("%#A\n", 500.00);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_flag_htag_with_e, .init = redirect_all_std)
{
    my_printf("%#e\n", 1.5);
    cr_assert_stdout_eq_str("1.500000e+00\n");
}

Test(my_printf, test_flag_htag_with_e_zero, .init = redirect_all_std)
{
    my_printf("%#e\n", 500.00);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_flag_htag_with_up_e, .init = redirect_all_std)
{
    my_printf("%#E\n", 1.5);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_flag_htag_with_up_e_zero, .init = redirect_all_std)
{
    my_printf("%#E\n", 500.00);
    cr_assert_stdout_eq_str("5.000000E+02\n");
}

Test(my_printf, test_flag_htag_with_f, .init = redirect_all_std)
{
    my_printf("%#f\n", 1.5);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_flag_htag_with_f_zero, .init = redirect_all_std)
{
    my_printf("%#f\n", 500.00);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_flag_htag_with_up_f, .init = redirect_all_std)
{
    my_printf("%#F\n", 1.5);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_flag_htag_with_up_f_zero, .init = redirect_all_std)
{
    my_printf("%#F\n", 500.00);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_flag_htag_with_g, .init = redirect_all_std)
{
    my_printf("%#g\n", 1.5);
    cr_assert_stdout_eq_str("1.50000\n");
}

Test(my_printf, test_flag_htag_with_g_zero, .init = redirect_all_std)
{
    my_printf("%#g\n", 500.00);
    cr_assert_stdout_eq_str("500.000\n");
}

Test(my_printf, test_flag_htag_with_up_g, .init = redirect_all_std)
{
    my_printf("%#G\n", 1.5);
    cr_assert_stdout_eq_str("1.50000\n");
}

Test(my_printf, test_flag_htag_with_up_g_zero, .init = redirect_all_std)
{
    my_printf("%#G\n", 500.00);
    cr_assert_stdout_eq_str("500.000\n");
}
