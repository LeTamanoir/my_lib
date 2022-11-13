/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for precision
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

Test(my_printf, simple_printf_with_str, .init = redirect_all_std)
{
    my_printf("Welcome to a %s, the number %d, %% Have a \
good day %c %%\n", "simple test", 154 - 4, '!');
    cr_assert_stdout_eq_str("Welcome to a simple test, the\
 number 150, % Have a good day ! %\n");
}

Test(my_printf, simple_printf_using_d, .init = redirect_all_std)
{
    my_printf("if you using 0, you can do %010d%%. To do a right align you \
can use #, like %#10d.\nYou can also write a single number \
like 5 : %5d\n", 15, 15, 15);
    cr_assert_stdout_eq_str("if you using 0, you can do 0000000015%\
. To do a right align you can use #, like         15.\n\
You can also write a single number like 5 :    15\n");
}

Test(my_printf, simple_printf, .init = redirect_all_std)
{
    my_printf("Hi !%.f\n", 1.5);
    cr_assert_stdout_eq_str("Hi !2\n");
}

Test(my_printf, my_printf_using_buffer_size, .init = redirect_all_std)
{
    my_printf("hello today im gonna use all buffer size to test my code\
so, by");
    cr_assert_stdout_eq_str("hello today im gonna use all buffer size \
to test my codeso, by");
}

Test(my_printf, compare_exp_and_float, .init = redirect_all_std)
{
    my_printf("The float of 1234567.0 is %Lf and the exp is \
%e so we can use \
%Lg", (long double)1234567.0, 1234567.0, (long double)1234567.0);
    cr_assert_stdout_eq_str("The float of 1234567.0 is 1234567.000000 \
and the exp is 1.234567e+06 so we can use 1.23457e+06");
}

Test(my_printf, use_default_for_g, .init = redirect_all_std)
{
    my_printf("we going to use g, %g", 1234567.0);
    cr_assert_stdout_eq_str("we going to use g, 1.23457e+06");
}

Test(my_printf, unknow_key, .init = redirect_all_std)
{
    my_printf("we going to use z, %z");
    cr_assert_stdout_eq_str("we going to use z, ");
}

Test(my_printf, my_printf_flag_a_extra_2, .init = redirect_all_std)
{
    my_printf("%a\n", 1.51);
    cr_assert_stdout_eq_str("0x1.828f5c28f5c29p+0\n");
}

#include "exec_specifier.h"

Test(exec_speficier, unknow_key)
{
    fn_map_t null_struct = { 0 };
    cr_assert_null(exec_speficier(NULL, NULL, null_struct));
}

#include <stdio.h>

Test(my_printf, flag_g_random_1, .init = redirect_all_std)
{
    my_printf("%-20g\n", 1234.56);
    my_printf("%#g\n", 1.5);
    my_printf("%.20g\n", 500.00);
    my_printf("%-5g\n", 145.00);
    my_printf("%.20g\n", 1000000000000000000000.0);
    my_printf("%.2g\n", 1000000000000000000000.0);
    my_printf("%g\n", 1000000000000000000000.0);
    my_printf("%.g\n", 1000000000000000000000.0);
    my_printf("%.20g\n", 120000.12312311);
    my_printf("%g\n", 120000.12312311);
    my_printf("%.g\n", 120000.12312311);
    my_printf("%.2g\n", 120000.12312311);

    cr_assert_stdout_eq_str("1234.56             \n1.50000\n500\n145  \n1e+21\n1e+21\n1e+21\n\
1e+21\n120000.1231231099955\n120000\n1e+05\n1.2e+05\n");
}