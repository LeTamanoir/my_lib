/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Tests for flag 0
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

Test(my_printf, test_flag_zero_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%020a\n", input);
    cr_assert_stdout_eq_str("0x000000000001.f4p+8\n");
}

Test(my_printf, test_flag_zero_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%020A\n", input);
    cr_assert_stdout_eq_str("0X000000000001.F4P+8\n");
}

Test(my_printf, test_flag_zero_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%020b\n", input);
    cr_assert_stdout_eq_str("00000000000001111011\n");
}

Test(my_printf, test_flag_zero_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%020c\n", input);
    cr_assert_stdout_eq_str("                   a\n");
}

Test(my_printf, test_flag_zero_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%020d\n", input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_zero_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%020i\n", input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_zero_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%020e\n", input);
    cr_assert_stdout_eq_str("000000005.000000e+02\n");
}

Test(my_printf, test_flag_zero_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%020E\n", input);
    cr_assert_stdout_eq_str("000000001.500000E+00\n");
}

Test(my_printf, test_flag_zero_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%020f\n", input);
    cr_assert_stdout_eq_str("0000000000500.000000\n");
}

Test(my_printf, test_flag_zero_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%020F\n", input);
    cr_assert_stdout_eq_str("0000000000001.500000\n");
}

Test(my_printf, test_flag_zero_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%020g\n", input);
    cr_assert_stdout_eq_str("00000000000000000500\n");
}

Test(my_printf, test_flag_zero_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%020G\n", input);
    cr_assert_stdout_eq_str("000000000000000001.5\n");
}


Test(my_printf, test_flag_zero_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%020n\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_flag_zero_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%020o\n", input);
    cr_assert_stdout_eq_str("00000000000000000173\n");
}

Test(my_printf, test_flag_zero_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%020p%n\n", &hello, &verif);
    cr_assert_eq(verif, 20);
}


Test(my_printf, test_flag_zero_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%020s\n", input);
    cr_assert_stdout_eq_str("               Hello\n");
}

Test(my_printf, test_flag_zero_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%020S\n", input);
    cr_assert_stdout_eq_str("               Hello\n");
}

Test(my_printf, test_flag_zero_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%020u\n", input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_zero_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%020x\n", input);
    cr_assert_stdout_eq_str("0000000000000000007b\n");
}

Test(my_printf, test_flag_zero_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%020X\n", input);
    cr_assert_stdout_eq_str("0000000000000000007B\n");
}

Test(my_printf, test_flag_zero_with_per, .init = redirect_all_std)
{
    my_printf("%020%\n");
    cr_assert_stdout_eq_str("%\n");
}
