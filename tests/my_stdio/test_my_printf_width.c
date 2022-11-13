/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for width
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

Test(my_printf, test_width_nb_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%20a\n", input);
    cr_assert_stdout_eq_str("           0x1.f4p+8\n");
}

Test(my_printf, test_width_nb_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%20A\n", input);
    cr_assert_stdout_eq_str("           0X1.F4P+8\n");
}

Test(my_printf, test_width_nb_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%20b\n", input);
    cr_assert_stdout_eq_str("             1111011\n");
}

Test(my_printf, test_width_nb_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%20c\n", input);
    cr_assert_stdout_eq_str("                   a\n");
}

Test(my_printf, test_width_nb_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%20d\n", input);
    cr_assert_stdout_eq_str("                 123\n");
}

Test(my_printf, test_width_nb_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%20i\n", input);
    cr_assert_stdout_eq_str("                 123\n");
}

Test(my_printf, test_width_nb_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%20e\n", input);
    cr_assert_stdout_eq_str("        5.000000e+02\n");
}

Test(my_printf, test_width_nb_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%20E\n", input);
    cr_assert_stdout_eq_str("        1.500000E+00\n");
}

Test(my_printf, test_width_nb_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%20f\n", input);
    cr_assert_stdout_eq_str("          500.000000\n");
}

Test(my_printf, test_width_nb_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%20F\n", input);
    cr_assert_stdout_eq_str("            1.500000\n");
}

Test(my_printf, test_width_nb_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%20g\n", input);
    cr_assert_stdout_eq_str("                 500\n");
}

Test(my_printf, test_width_nb_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%20G\n", input);
    cr_assert_stdout_eq_str("                 1.5\n");
}


Test(my_printf, test_width_nb_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%20n\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_width_nb_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%20o\n", input);
    cr_assert_stdout_eq_str("                 173\n");
}

Test(my_printf, test_width_nb_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%20p%n\n", &hello, &verif);
    cr_assert_eq(verif, 20);
}


Test(my_printf, test_width_nb_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%20s\n", input);
    cr_assert_stdout_eq_str("               Hello\n");
}

Test(my_printf, test_width_nb_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%20S\n", input);
    cr_assert_stdout_eq_str("               Hello\n");
}

Test(my_printf, test_width_nb_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%20u\n", input);
    cr_assert_stdout_eq_str("                 123\n");
}

Test(my_printf, test_width_nb_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%20x\n", input);
    cr_assert_stdout_eq_str("                  7b\n");
}

Test(my_printf, test_width_nb_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%20X\n", input);
    cr_assert_stdout_eq_str("                  7B\n");
}

Test(my_printf, test_width_nb_with_per, .init = redirect_all_std)
{
    my_printf("%20%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_width_star_with_a, .init = redirect_all_std)
{
    int width = 20;
    double input = 500.00;
    my_printf("%*a\n", width, input);
    cr_assert_stdout_eq_str("           0x1.f4p+8\n");
}

Test(my_printf, test_width_star_with_up_a, .init = redirect_all_std)
{
    int width = 20;
    double input = 500.00;
    my_printf("%*A\n", width, input);
    cr_assert_stdout_eq_str("           0X1.F4P+8\n");
}

Test(my_printf, test_width_star_with_b, .init = redirect_all_std)
{
    int width = 20;
    int input = 123;
    my_printf("%*b\n", width, input);
    cr_assert_stdout_eq_str("             1111011\n");
}

Test(my_printf, test_width_star_with_c, .init = redirect_all_std)
{
    int width = 20;
    char input = 'a';
    my_printf("%*c\n", width, input);
    cr_assert_stdout_eq_str("                   a\n");
}

Test(my_printf, test_width_star_with_d, .init = redirect_all_std)
{
    int width = 20;
    int input = 123;
    my_printf("%*d\n", width, input);
    cr_assert_stdout_eq_str("                 123\n");
}

Test(my_printf, test_width_star_with_i, .init = redirect_all_std)
{
    int width = 20;
    int input = 123;
    my_printf("%*i\n", width, input);
    cr_assert_stdout_eq_str("                 123\n");
}

Test(my_printf, test_width_star_with_e, .init = redirect_all_std)
{
    int width = 20;
    double input = 500.00;
    my_printf("%*e\n", width, input);
    cr_assert_stdout_eq_str("        5.000000e+02\n");
}

Test(my_printf, test_width_star_with_up_e, .init = redirect_all_std)
{
    int width = 20;
    double input = 1.5;
    my_printf("%*E\n", width, input);
    cr_assert_stdout_eq_str("        1.500000E+00\n");
}

Test(my_printf, test_width_star_with_f, .init = redirect_all_std)
{
    int width = 20;
    double input = 500.00;
    my_printf("%*f\n", width, input);
    cr_assert_stdout_eq_str("          500.000000\n");
}

Test(my_printf, test_width_star_with_up_f, .init = redirect_all_std)
{
    int width = 20;
    double input = 1.5;
    my_printf("%*F\n", width, input);
    cr_assert_stdout_eq_str("            1.500000\n");
}

Test(my_printf, test_width_star_with_g, .init = redirect_all_std)
{
    int width = 20;
    double input = 500.00;
    my_printf("%*g\n", width, input);
    cr_assert_stdout_eq_str("                 500\n");
}

Test(my_printf, test_width_star_with_up_g, .init = redirect_all_std)
{
    int width = 20;
    double input = 1.5;
    my_printf("%*G\n", width, input);
    cr_assert_stdout_eq_str("                 1.5\n");
}


Test(my_printf, test_width_star_with_n, .init = redirect_all_std)
{
    int width = 20;
    int verif = 0;
    my_printf("a%*n\n", width, &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_width_star_with_o, .init = redirect_all_std)
{
    int width = 20;
    int input = 123;
    my_printf("%*o\n", width, input);
    cr_assert_stdout_eq_str("                 173\n");
}

Test(my_printf, test_width_star_with_p, .init = redirect_all_std)
{
    int width = 20;
    char *hello;
    int verif = 0;
    my_printf("%*p%n\n", width, &hello, &verif);
    cr_assert_eq(verif, 20);
}


Test(my_printf, test_width_star_with_s, .init = redirect_all_std)
{
    int width = 20;
    char *input = "Hello";
    my_printf("%*s\n", width, input);
    cr_assert_stdout_eq_str("               Hello\n");
}

Test(my_printf, test_width_star_with_up_s, .init = redirect_all_std)
{
    int width = 20;
    char *input = "Hello";
    my_printf("%*S\n", width, input);
    cr_assert_stdout_eq_str("               Hello\n");
}

Test(my_printf, test_width_star_with_u, .init = redirect_all_std)
{
    int width = 20;
    unsigned int input = 123;
    my_printf("%*u\n", width, input);
    cr_assert_stdout_eq_str("                 123\n");
}

Test(my_printf, test_width_star_with_x, .init = redirect_all_std)
{
    int width = 20;
    int input = 123;
    my_printf("%*x\n", width, input);
    cr_assert_stdout_eq_str("                  7b\n");
}

Test(my_printf, test_width_star_with_up_x, .init = redirect_all_std)
{
    int width = 20;
    int input = 123;
    my_printf("%*X\n", width, input);
    cr_assert_stdout_eq_str("                  7B\n");
}

Test(my_printf, test_width_star_with_per, .init = redirect_all_std)
{
    int width = 20;
    my_printf("%*%\n", width);
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_width_star_neg_with_a, .init = redirect_all_std)
{
    int width = -20;
    double input = 500.00;
    my_printf("%*a\n", width, input);
    cr_assert_stdout_eq_str("0x1.f4p+8           \n");
}

Test(my_printf, test_width_star_neg_with_up_a, .init = redirect_all_std)
{
    int width = -20;
    double input = 500.00;
    my_printf("%*A\n", width, input);
    cr_assert_stdout_eq_str("0X1.F4P+8           \n");
}

Test(my_printf, test_width_star_neg_with_b, .init = redirect_all_std)
{
    int width = -20;
    int input = 123;
    my_printf("%*b\n", width, input);
    cr_assert_stdout_eq_str("1111011             \n");
}

Test(my_printf, test_width_star_neg_with_c, .init = redirect_all_std)
{
    int width = -20;
    char input = 'a';
    my_printf("%*c\n", width, input);
    cr_assert_stdout_eq_str("a                   \n");
}

Test(my_printf, test_width_star_neg_with_d, .init = redirect_all_std)
{
    int width = -20;
    int input = 123;
    my_printf("%*d\n", width, input);
    cr_assert_stdout_eq_str("123                 \n");
}

Test(my_printf, test_width_star_neg_with_i, .init = redirect_all_std)
{
    int width = -20;
    int input = 123;
    my_printf("%*i\n", width, input);
    cr_assert_stdout_eq_str("123                 \n");
}

Test(my_printf, test_width_star_neg_with_e, .init = redirect_all_std)
{
    int width = -20;
    double input = 500.00;
    my_printf("%*e\n", width, input);
    cr_assert_stdout_eq_str("5.000000e+02        \n");
}

Test(my_printf, test_width_star_neg_with_up_e, .init = redirect_all_std)
{
    int width = -20;
    double input = 1.5;
    my_printf("%*E\n", width, input);
    cr_assert_stdout_eq_str("1.500000E+00        \n");
}

Test(my_printf, test_width_star_neg_with_f, .init = redirect_all_std)
{
    int width = -20;
    double input = 500.00;
    my_printf("%*f\n", width, input);
    cr_assert_stdout_eq_str("500.000000          \n");
}

Test(my_printf, test_width_star_neg_with_up_f, .init = redirect_all_std)
{
    int width = -20;
    double input = 1.5;
    my_printf("%*F\n", width, input);
    cr_assert_stdout_eq_str("1.500000            \n");
}

Test(my_printf, test_width_star_neg_with_g, .init = redirect_all_std)
{
    int width = -20;
    double input = 500.00;
    my_printf("%*g\n", width, input);
    cr_assert_stdout_eq_str("500                 \n");
}

Test(my_printf, test_width_star_neg_with_up_g, .init = redirect_all_std)
{
    int width = -20;
    double input = 1.5;
    my_printf("%*G\n", width, input);
    cr_assert_stdout_eq_str("1.5                 \n");
}


Test(my_printf, test_width_star_neg_with_n, .init = redirect_all_std)
{
    int width = -20;
    int verif = 0;
    my_printf("a%*n\n", width, &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_width_star_neg_with_o, .init = redirect_all_std)
{
    int width = -20;
    int input = 123;
    my_printf("%*o\n", width, input);
    cr_assert_stdout_eq_str("173                 \n");
}

Test(my_printf, test_width_star_neg_with_p, .init = redirect_all_std)
{
    int width = -20;
    char *hello;
    int verif = 0;
    my_printf("%*p%n\n", width, &hello, &verif);
    cr_assert_eq(verif, 20);
}


Test(my_printf, test_width_star_neg_with_s, .init = redirect_all_std)
{
    int width = -20;
    char *input = "Hello";
    my_printf("%*s\n", width, input);
    cr_assert_stdout_eq_str("Hello               \n");
}

Test(my_printf, test_width_star_neg_with_up_s, .init = redirect_all_std)
{
    int width = -20;
    char *input = "Hello";
    my_printf("%*S\n", width, input);
    cr_assert_stdout_eq_str("Hello               \n");
}

Test(my_printf, test_width_star_neg_with_u, .init = redirect_all_std)
{
    int width = -20;
    unsigned int input = 123;
    my_printf("%*u\n", width, input);
    cr_assert_stdout_eq_str("123                 \n");
}

Test(my_printf, test_width_star_neg_with_x, .init = redirect_all_std)
{
    int width = -20;
    int input = 123;
    my_printf("%*x\n", width, input);
    cr_assert_stdout_eq_str("7b                  \n");
}

Test(my_printf, test_width_star_neg_with_up_x, .init = redirect_all_std)
{
    int width = -20;
    int input = 123;
    my_printf("%*X\n", width, input);
    cr_assert_stdout_eq_str("7B                  \n");
}

Test(my_printf, test_width_star_neg_with_per, .init = redirect_all_std)
{
    int width = -20;
    my_printf("%*%\n", width);
    cr_assert_stdout_eq_str("%\n");
}
