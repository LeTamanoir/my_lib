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

Test(my_printf, test_flag_prec_nb_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.20a\n", input);
    cr_assert_stdout_eq_str("0x1.f4000000000000000000p+8\n");
}

Test(my_printf, test_flag_prec_nb_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.20A\n", input);
    cr_assert_stdout_eq_str("0X1.F4000000000000000000P+8\n");
}

Test(my_printf, test_flag_prec_nb_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.20b\n", input);
    cr_assert_stdout_eq_str("00000000000001111011\n");
}

Test(my_printf, test_flag_prec_nb_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%.20c\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_flag_prec_nb_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.20d\n", input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_prec_nb_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.20i\n", input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_prec_nb_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.20e\n", input);
    cr_assert_stdout_eq_str("5.00000000000000000000e+02\n");
}

Test(my_printf, test_flag_prec_nb_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%.20E\n", input);
    cr_assert_stdout_eq_str("1.50000000000000000000E+00\n");
}

Test(my_printf, test_flag_prec_nb_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.20f\n", input);
    cr_assert_stdout_eq_str("500.00000000000000000000\n");
}

Test(my_printf, test_flag_prec_nb_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%.20F\n", input);
    cr_assert_stdout_eq_str("1.50000000000000000000\n");
}

Test(my_printf, test_flag_prec_nb_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.20g\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_flag_prec_nb_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%.20G\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_flag_prec_nb_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%.20n\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_flag_prec_nb_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.20o\n", input);
    cr_assert_stdout_eq_str("00000000000000000173\n");
}

Test(my_printf, test_flag_prec_nb_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%.20p%n\n", &hello, &verif);
    cr_assert_eq(verif, 22);
}

Test(my_printf, test_flag_prec_nb_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%.20s\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_flag_prec_nb_with_s_small_w, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%.3s\n", input);
    cr_assert_stdout_eq_str("Hel\n");
}

Test(my_printf, test_flag_prec_nb_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%.20S\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_flag_prec_nb_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%.20u\n", input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_prec_nb_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.20x\n", input);
    cr_assert_stdout_eq_str("0000000000000000007b\n");
}

Test(my_printf, test_flag_prec_nb_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.20X\n", input);
    cr_assert_stdout_eq_str("0000000000000000007B\n");
}

Test(my_printf, test_flag_prec_nb_with_per, .init = redirect_all_std)
{
    my_printf("%.20%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_flag_prec_star_with_a, .init = redirect_all_std)
{
    int precision = 20;
    double input = 500.00;
    my_printf("%.*a\n", precision, input);
    cr_assert_stdout_eq_str("0x1.f4000000000000000000p+8\n");
}

Test(my_printf, test_flag_prec_star_with_up_a, .init = redirect_all_std)
{
    int precision = 20;
    double input = 500.00;
    my_printf("%.*A\n", precision, input);
    cr_assert_stdout_eq_str("0X1.F4000000000000000000P+8\n");
}

Test(my_printf, test_flag_prec_star_with_b, .init = redirect_all_std)
{
    int precision = 20;
    int input = 123;
    my_printf("%.*b\n", precision, input);
    cr_assert_stdout_eq_str("00000000000001111011\n");
}

Test(my_printf, test_flag_prec_star_with_c, .init = redirect_all_std)
{
    int precision = 20;
    char input = 'a';
    my_printf("%.*c\n", precision, input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_flag_prec_star_with_d, .init = redirect_all_std)
{
    int precision = 20;
    int input = 123;
    my_printf("%.*d\n", precision, input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_prec_star_with_i, .init = redirect_all_std)
{
    int precision = 20;
    int input = 123;
    my_printf("%.*i\n", precision, input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_prec_star_with_e, .init = redirect_all_std)
{
    int precision = 20;
    double input = 500.00;
    my_printf("%.*e\n", precision, input);
    cr_assert_stdout_eq_str("5.00000000000000000000e+02\n");
}

Test(my_printf, test_flag_prec_star_with_up_e, .init = redirect_all_std)
{
    int precision = 20;
    double input = 1.5;
    my_printf("%.*E\n", precision, input);
    cr_assert_stdout_eq_str("1.50000000000000000000E+00\n");
}

Test(my_printf, test_flag_prec_star_with_f, .init = redirect_all_std)
{
    int precision = 20;
    double input = 500.00;
    my_printf("%.*f\n", precision, input);
    cr_assert_stdout_eq_str("500.00000000000000000000\n");
}

Test(my_printf, test_flag_prec_star_with_up_f, .init = redirect_all_std)
{
    int precision = 20;
    double input = 1.5;
    my_printf("%.*F\n", precision, input);
    cr_assert_stdout_eq_str("1.50000000000000000000\n");
}

Test(my_printf, test_flag_prec_star_with_g, .init = redirect_all_std)
{
    int precision = 20;
    double input = 500.00;
    my_printf("%.*g\n", precision, input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_flag_prec_star_with_up_g, .init = redirect_all_std)
{
    int precision = 20;
    double input = 1.5;
    my_printf("%.*G\n", precision, input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_flag_prec_star_with_n, .init = redirect_all_std)
{
    int precision = 20;
    int verif = 0;
    my_printf("a%.*n\n", precision, &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_flag_prec_star_with_o, .init = redirect_all_std)
{
    int precision = 20;
    int input = 123;
    my_printf("%.*o\n", precision, input);
    cr_assert_stdout_eq_str("00000000000000000173\n");
}

Test(my_printf, test_flag_prec_star_with_p, .init = redirect_all_std)
{
    int precision = 20;
    char *hello;
    int verif = 0;
    my_printf("%.*p%n\n", precision, &hello, &verif);
    cr_assert_eq(verif, 22);
}


Test(my_printf, test_flag_prec_star_with_s, .init = redirect_all_std)
{
    int precision = 20;
    char *input = "Hello";
    my_printf("%.*s\n", precision, input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_flag_prec_star_with_up_s, .init = redirect_all_std)
{
    int precision = 20;
    char *input = "Hello";
    my_printf("%.*S\n", precision, input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_flag_prec_star_with_u, .init = redirect_all_std)
{
    int precision = 20;
    unsigned int input = 123;
    my_printf("%.*u\n", precision, input);
    cr_assert_stdout_eq_str("00000000000000000123\n");
}

Test(my_printf, test_flag_prec_star_with_x, .init = redirect_all_std)
{
    int precision = 20;
    int input = 123;
    my_printf("%.*x\n", precision, input);
    cr_assert_stdout_eq_str("0000000000000000007b\n");
}

Test(my_printf, test_flag_prec_star_with_up_x, .init = redirect_all_std)
{
    int precision = 20;
    int input = 123;
    my_printf("%.*X\n", precision, input);
    cr_assert_stdout_eq_str("0000000000000000007B\n");
}

Test(my_printf, test_flag_prec_star_with_per, .init = redirect_all_std)
{
    int precision = 20;
    my_printf("%.*%\n", precision);
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_flag_prec_z_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.a\n", input);
    cr_assert_stdout_eq_str("0x2p+8\n");
}

Test(my_printf, test_flag_prec_z_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.A\n", input);
    cr_assert_stdout_eq_str("0X2P+8\n");
}

Test(my_printf, test_flag_prec_z_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.b\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_flag_prec_z_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%.c\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_flag_prec_z_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.d\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_flag_prec_z_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.i\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_flag_prec_z_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.e\n", input);
    cr_assert_stdout_eq_str("5e+02\n");
}

Test(my_printf, test_flag_prec_z_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%.E\n", input);
    cr_assert_stdout_eq_str("2E+00\n");
}

Test(my_printf, test_flag_prec_z_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.f\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_flag_prec_z_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%.F\n", input);
    cr_assert_stdout_eq_str("2\n");
}

Test(my_printf, test_flag_prec_z_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%.g\n", input);
    cr_assert_stdout_eq_str("5e+02\n");
}

Test(my_printf, test_flag_prec_z_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%.G\n", input);
    cr_assert_stdout_eq_str("2\n");
}


Test(my_printf, test_flag_prec_z_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%.n\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_flag_prec_z_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.o\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_flag_prec_z_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%.p%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_flag_prec_z_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%.s\n", input);
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, test_flag_prec_z_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%.S\n", input);
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, test_flag_prec_z_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%.u\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_flag_prec_z_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.x\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_flag_prec_z_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%.X\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_flag_prec_z_with_per, .init = redirect_all_std)
{
    my_printf("%.%\n");
    cr_assert_stdout_eq_str("%\n");
}
