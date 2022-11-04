/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for length
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

Test(my_printf, test_length_l_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%la\n", input);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_length_l_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%lA\n", input);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_length_l_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%lb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_l_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%lc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_l_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%ld\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_l_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%li\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_l_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%le\n", input);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_length_l_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%lE\n", input);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_length_l_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%lf\n", input);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_length_l_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%lF\n", input);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_length_l_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%lg\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_length_l_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%lG\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_length_l_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf(" %n\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_l_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%lo\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_l_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%lp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_l_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%ls\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_l_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%lS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_l_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%lu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_l_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%lx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_l_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%lX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_l_with_per, .init = redirect_all_std)
{
    my_printf("%l%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_ll_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%llb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_ll_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%llc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_ll_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%lld\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_ll_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%lli\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_ll_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%lln\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_ll_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%llo\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_ll_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%llp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_ll_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%lls\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_ll_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%llS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_ll_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%llu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_ll_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%llx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_ll_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%llX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_ll_with_per, .init = redirect_all_std)
{
    my_printf("%ll%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_h_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%ha\n", input);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_length_h_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hA\n", input);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_length_h_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_h_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%hc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_h_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hd\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_h_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hi\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_h_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%he\n", input);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_length_h_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%hE\n", input);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_length_h_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hf\n", input);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_length_h_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%hF\n", input);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_length_h_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hg\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_length_h_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%hG\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_length_h_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%hn\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_h_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%ho\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_h_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%hp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_h_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%hs\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_h_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%hS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_h_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%hu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_h_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_h_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_h_with_per, .init = redirect_all_std)
{
    my_printf("%h%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_hh_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hha\n", input);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_length_hh_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hhA\n", input);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_length_hh_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hhb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_hh_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%hhc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_hh_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hhd\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_hh_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hhi\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_hh_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hhe\n", input);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_length_hh_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%hhE\n", input);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_length_hh_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hhf\n", input);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_length_hh_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%hhF\n", input);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_length_hh_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%hhg\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_length_hh_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%hhG\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_length_hh_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%hhn\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_hh_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hho\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_hh_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%hhp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_hh_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%hhs\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_hh_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%hhS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_hh_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%hhu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_hh_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hhx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_hh_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%hhX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_hh_with_per, .init = redirect_all_std)
{
    my_printf("%hh%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_up_l_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%Lb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_up_l_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%Lc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_up_l_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%Ld\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_up_l_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%Li\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_up_l_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%Ln\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_up_l_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%Lo\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_up_l_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%Lp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_up_l_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%Ls\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_up_l_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%LS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_up_l_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%Lu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_up_l_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%Lx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_up_l_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%LX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_up_l_with_per, .init = redirect_all_std)
{
    my_printf("%L%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_j_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%ja\n", input);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_length_j_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%jA\n", input);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_length_j_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%jb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_j_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%jc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_j_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%jd\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_j_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%ji\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_j_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%je\n", input);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_length_j_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%jE\n", input);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_length_j_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%jf\n", input);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_length_j_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%jF\n", input);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_length_j_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%jg\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_length_j_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%jG\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_length_j_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%jn\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_j_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%jo\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_j_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%jp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_j_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%js\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_j_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%jS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_j_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%ju\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_j_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%jx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_j_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%jX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_j_with_per, .init = redirect_all_std)
{
    my_printf("%j%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_z_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%za\n", input);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_length_z_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%zA\n", input);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_length_z_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%zb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_z_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%zc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_z_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%zd\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_z_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%zi\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_z_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%ze\n", input);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_length_z_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%zE\n", input);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_length_z_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%zf\n", input);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_length_z_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%zF\n", input);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_length_z_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%zg\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_length_z_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%zG\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_length_z_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%zn\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_z_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%zo\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_z_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%zp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_z_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%zs\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_z_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%zS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_z_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%zu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_z_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%zx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_z_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%zX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_z_with_per, .init = redirect_all_std)
{
    my_printf("%z%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_length_t_with_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%ta\n", input);
    cr_assert_stdout_eq_str("0x1.f4p+8\n");
}

Test(my_printf, test_length_t_with_up_a, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%tA\n", input);
    cr_assert_stdout_eq_str("0X1.F4P+8\n");
}

Test(my_printf, test_length_t_with_b, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%tb\n", input);
    cr_assert_stdout_eq_str("1111011\n");
}

Test(my_printf, test_length_t_with_c, .init = redirect_all_std)
{
    char input = 'a';
    my_printf("%tc\n", input);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_length_t_with_d, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%td\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_t_with_i, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%ti\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_t_with_e, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%te\n", input);
    cr_assert_stdout_eq_str("5.000000e+02\n");
}

Test(my_printf, test_length_t_with_up_e, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%tE\n", input);
    cr_assert_stdout_eq_str("1.500000E+00\n");
}

Test(my_printf, test_length_t_with_f, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%tf\n", input);
    cr_assert_stdout_eq_str("500.000000\n");
}

Test(my_printf, test_length_t_with_up_f, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%tF\n", input);
    cr_assert_stdout_eq_str("1.500000\n");
}

Test(my_printf, test_length_t_with_g, .init = redirect_all_std)
{
    double input = 500.00;
    my_printf("%tg\n", input);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_length_t_with_up_g, .init = redirect_all_std)
{
    double input = 1.5;
    my_printf("%tG\n", input);
    cr_assert_stdout_eq_str("1.5\n");
}


Test(my_printf, test_length_t_with_n, .init = redirect_all_std)
{
    int verif = 0;
    my_printf("a%tn\n", &verif);
    cr_assert_eq(verif, 1);
}

Test(my_printf, test_length_t_with_o, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%to\n", input);
    cr_assert_stdout_eq_str("173\n");
}

Test(my_printf, test_length_t_with_p, .init = redirect_all_std)
{
    char *hello;
    int verif = 0;
    my_printf("%tp%n\n", &hello, &verif);
    cr_assert_eq(verif, 14);
}


Test(my_printf, test_length_t_with_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%ts\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_t_with_up_s, .init = redirect_all_std)
{
    char *input = "Hello";
    my_printf("%tS\n", input);
    cr_assert_stdout_eq_str("Hello\n");
}

Test(my_printf, test_length_t_with_u, .init = redirect_all_std)
{
    unsigned int input = 123;
    my_printf("%tu\n", input);
    cr_assert_stdout_eq_str("123\n");
}

Test(my_printf, test_length_t_with_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%tx\n", input);
    cr_assert_stdout_eq_str("7b\n");
}

Test(my_printf, test_length_t_with_up_x, .init = redirect_all_std)
{
    int input = 123;
    my_printf("%tX\n", input);
    cr_assert_stdout_eq_str("7B\n");
}

Test(my_printf, test_length_t_with_per, .init = redirect_all_std)
{
    my_printf("%t%\n");
    cr_assert_stdout_eq_str("%\n");
}

