/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Tests for flags + -
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "specifiers.h"
#include "my_stdio.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_flag_space_with_a, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% a\n", out);
    cr_assert_stdout_eq_str(" 0x1.f4p+8\n");
}

Test(my_printf, test_flag_spa_and_less_with_a, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% a\n", out);
    cr_assert_stdout_eq_str("-0x1.f4p+8\n");
}

Test(my_printf, test_flag_space_with_up_a, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% A\n", out);
    cr_assert_stdout_eq_str(" 0X1.F4P+8\n");
}

Test(my_printf, test_flag_spa_and_less_with_up_a, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% A\n", out);
    cr_assert_stdout_eq_str("-0X1.F4P+8\n");
}

Test(my_printf, test_flag_space_with_d, .init = redirect_all_std)
{
    int out = 500;
    my_printf("% d\n", out);
    cr_assert_stdout_eq_str(" 500\n");
}

Test(my_printf, test_flag_spa_and_less_with_d, .init = redirect_all_std)
{
    int out = -500;
    my_printf("% d\n", out);
    cr_assert_stdout_eq_str("-500\n");
}

Test(my_printf, test_flag_space_with_i, .init = redirect_all_std)
{
    int out = 500;
    my_printf("% i\n", out);
    cr_assert_stdout_eq_str(" 500\n");
}

Test(my_printf, test_flag_spa_and_less_with_i, .init = redirect_all_std)
{
    int out = -500;
    my_printf("% i\n", out);
    cr_assert_stdout_eq_str("-500\n");
}

Test(my_printf, test_flag_space_with_e, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% e\n", out);
    cr_assert_stdout_eq_str(" 5.000000e+02\n");
}

Test(my_printf, test_flag_spa_and_less_with_e, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% e\n", out);
    cr_assert_stdout_eq_str("-5.000000e+02\n");
}

Test(my_printf, test_flag_space_with_up_e, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% E\n", out);
    cr_assert_stdout_eq_str(" 5.000000E+02\n");
}

Test(my_printf, test_flag_spa_and_less_with_up_e, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% E\n", out);
    cr_assert_stdout_eq_str("-5.000000E+02\n");
}

Test(my_printf, test_flag_space_with_f, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% f\n", out);
    cr_assert_stdout_eq_str(" 500.000000\n");
}

Test(my_printf, test_flag_spa_and_less_with_f, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% f\n", out);
    cr_assert_stdout_eq_str("-500.000000\n");
}

Test(my_printf, test_flag_space_with_up_f, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% F\n", out);
    cr_assert_stdout_eq_str(" 500.000000\n");
}

Test(my_printf, test_flag_spa_and_less_with_up_f, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% F\n", out);
    cr_assert_stdout_eq_str("-500.000000\n");
}

Test(my_printf, test_flag_space_with_g, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% g\n", out);
    cr_assert_stdout_eq_str(" 500\n");
}

Test(my_printf, test_flag_spa_and_less_with_g, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% g\n", out);
    cr_assert_stdout_eq_str("-500\n");
}

Test(my_printf, test_flag_space_with_up_g, .init = redirect_all_std)
{
    double out = 500.00;
    my_printf("% G\n", out);
    cr_assert_stdout_eq_str(" 500\n");
}

Test(my_printf, test_flag_spa_and_less_with_up_g, .init = redirect_all_std)
{
    double out = -500.00;
    my_printf("% G\n", out);
    cr_assert_stdout_eq_str("-500\n");
}

Test(my_printf, test_flag_space_with_p, .init = redirect_all_std)
{
    char *out = "hello";
    int verif = 0;
    my_printf("% p%n\n", &out, &verif);
    cr_assert_eq(verif, 15);
}
