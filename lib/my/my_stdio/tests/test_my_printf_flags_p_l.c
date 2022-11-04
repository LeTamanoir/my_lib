/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Tests for flags + -
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

Test(my_printf, test_flag_less_with_d, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%-d\n", out);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_flag_less_with_i, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%-i\n", out);
    cr_assert_stdout_eq_str("500\n");
}

Test(my_printf, test_flag_less_nb_with_d, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%-5d\n", out);
    cr_assert_stdout_eq_str("500  \n");
}

Test(my_printf, test_flag_less_nb_with_i, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%-5i\n", out);
    cr_assert_stdout_eq_str("500  \n");
}

Test(my_printf, test_flag_plus_with_d, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%+d\n", out);
    cr_assert_stdout_eq_str("+500\n");
}

Test(my_printf, test_flag_plus_with_i, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%+i\n", out);
    cr_assert_stdout_eq_str("+500\n");
}

Test(my_printf, test_flag_plus_nb_with_d, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%+5d\n", out);
    cr_assert_stdout_eq_str(" +500\n");
}

Test(my_printf, test_flag_plus_nb_with_i, .init = redirect_all_std)
{
    int out = 500;
    my_printf("%+5i\n", out);
    cr_assert_stdout_eq_str(" +500\n");
}

Test(my_printf, test_flag_merge_low_with_d, .init = redirect_all_std)
{
    int out = -500;
    my_printf("%-d\n", out);
    cr_assert_stdout_eq_str("-500\n");
}

Test(my_printf, test_flag_merge_low_with_i, .init = redirect_all_std)
{
    int out = -500;
    my_printf("%-i\n", out);
    cr_assert_stdout_eq_str("-500\n");
}

Test(my_printf, test_flag_merge_low_nb_with_d, .init = redirect_all_std)
{
    int out = -500;
    my_printf("%-5d\n", out);
    cr_assert_stdout_eq_str("-500 \n");
}

Test(my_printf, test_flag_merge_low_nb_with_i, .init = redirect_all_std)
{
    int out = -500;
    my_printf("%-5i\n", out);
    cr_assert_stdout_eq_str("-500 \n");
}

Test(my_printf, test_flag_merge_plus_nb_with_d, .init = redirect_all_std)
{
    int out = -500;
    my_printf("%+5d\n", out);
    cr_assert_stdout_eq_str(" -500\n");
}

Test(my_printf, test_flag_merge_plus_nb_with_i, .init = redirect_all_std)
{
    int out = -500;
    my_printf("%+5i\n", out);
    cr_assert_stdout_eq_str(" -500\n");
}

Test(my_printf, test_flag_less_with_c, .init = redirect_all_std)
{
    char out = 'a';
    my_printf("%-c\n", out);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_flag_plus_with_c, .init = redirect_all_std)
{
    char out = 'a';
    my_printf("%+c\n", out);
    cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, test_flag_less_nb_with_c, .init = redirect_all_std)
{
    char out = 'a';
    my_printf("%-5c\n", out);
    cr_assert_stdout_eq_str("a    \n");
}

Test(my_printf, test_flag_plus_nb_with_c, .init = redirect_all_std)
{
    char out = 'a';
    my_printf("%+5c\n", out);
    cr_assert_stdout_eq_str("    a\n");
}

Test(my_printf, test_flag_less_with_s, .init = redirect_all_std)
{
    char *out = "Hello world";
    my_printf("%-s\n", out);
    cr_assert_stdout_eq_str("Hello world\n");
}

Test(my_printf, test_flag_plus_with_s, .init = redirect_all_std)
{
    char *out = "Hello world";
    my_printf("%+s\n", out);
    cr_assert_stdout_eq_str("Hello world\n");
}

Test(my_printf, test_flag_less_nb_with_s, .init = redirect_all_std)
{
    char *out = "Hello world";
    my_printf("%-15s\n", out);
    cr_assert_stdout_eq_str("Hello world    \n");
}

Test(my_printf, test_flag_plus_nb_with_s, .init = redirect_all_std)
{
    char *out = "Hello world";
    my_printf("%+15s\n", out);
    cr_assert_stdout_eq_str("    Hello world\n");
}

Test(my_printf, test_flag_less_with_p, .init = redirect_all_std)
{
    char *out = "Hello world";
    int verif = 0;
    my_printf("%-p%n\n", &out, &verif);
    cr_assert_eq(verif, 14);
}

Test(my_printf, test_flag_plus_with_p, .init = redirect_all_std)
{
    char *out = "Hello world";
    int verif = 0;
    my_printf("%+p%n\n", &out, &verif);
    cr_assert_eq(verif, 15);
}

Test(my_printf, test_flag_less_nb_with_p, .init = redirect_all_std)
{
    char *out = "Hello world";
    int verif = 0;
    my_printf("%-30p%n\n", &out, &verif);
    cr_assert_eq(verif, 30);
}

Test(my_printf, test_flag_plus_nb_with_p, .init = redirect_all_std)
{
    char *out = "Hello world";
    int verif = 0;
    my_printf("%+30p%n\n", &out, &verif);
    cr_assert_eq(verif, 30);
}

Test(my_printf, test_flag_less_with_up_s, .init = redirect_all_std)
{
    char *out = "backslash n is \n in hexa";
    int verif = 0;
    my_printf("%-S\n", out);
    cr_assert_stdout_eq_str("backslash n is \\012 in hexa\n");
}

Test(my_printf, test_flag_plus_with_up_s, .init = redirect_all_std)
{
    char *out = "backslash n is \n in hexa";
    int verif = 0;
    my_printf("%+S\n", out);
    cr_assert_stdout_eq_str("backslash n is \\012 in hexa\n");
}

Test(my_printf, test_flag_less_nb_with_up_s, .init = redirect_all_std)
{
    char *out = "backslash n is \n in hexa";
    int verif = 0;
    my_printf("%-30S\n", out);
    cr_assert_stdout_eq_str("backslash n is \\012 in hexa   \n");
}

Test(my_printf, test_flag_plus_nb_with_up_s, .init = redirect_all_std)
{
    char *out = "backslash n is \n in hexa";
    int verif = 0;
    my_printf("%+30S\n", out);
    cr_assert_stdout_eq_str("   backslash n is \\012 in hexa\n");
}

Test(my_printf, test_flag_less_with_u, .init = redirect_all_std)
{
    unsigned int out = 1234567890;
    my_printf("%-u\n", out);
    cr_assert_stdout_eq_str("1234567890\n");
}

Test(my_printf, test_flag_plus_with_u, .init = redirect_all_std)
{
    unsigned int out = 1234567890;
    my_printf("%+u\n", out);
    cr_assert_stdout_eq_str("1234567890\n");
}

Test(my_printf, test_flag_less_nb_with_u, .init = redirect_all_std)
{
    unsigned int out = 1234567890;
    my_printf("%-20u\n", out);
    cr_assert_stdout_eq_str("1234567890          \n");
}

Test(my_printf, test_flag_plus_nb_with_u, .init = redirect_all_std)
{
    unsigned int out = 1234567890;
    my_printf("%+20u\n", out);
    cr_assert_stdout_eq_str("          1234567890\n");
}

Test(my_printf, test_flag_less_with_x, .init = redirect_all_std)
{
    unsigned int out = 0x1A2C;
    my_printf("%-x\n", out);
    cr_assert_stdout_eq_str("1a2c\n");
}

Test(my_printf, test_flag_plus_with_x, .init = redirect_all_std)
{
    unsigned int out = 0x1A2C;
    my_printf("%+x\n", out);
    cr_assert_stdout_eq_str("1a2c\n");
}

Test(my_printf, test_flag_less_nb_with_x, .init = redirect_all_std)
{
    unsigned int out = 0x1A2C;
    my_printf("%-10x\n", out);
    cr_assert_stdout_eq_str("1a2c      \n");
}

Test(my_printf, test_flag_plus_nb_with_x, .init = redirect_all_std)
{
    unsigned int out = 0x1A2C;
    my_printf("%+10x\n", out);
    cr_assert_stdout_eq_str("      1a2c\n");
}

Test(my_printf, test_flag_less_with_up_x, .init = redirect_all_std)
{
    unsigned int out = 0x1a2c;
    my_printf("%-X\n", out);
    cr_assert_stdout_eq_str("1A2C\n");
}

Test(my_printf, test_flag_plus_with_up_x, .init = redirect_all_std)
{
    unsigned int out = 0x1a2c;
    my_printf("%+X\n", out);
    cr_assert_stdout_eq_str("1A2C\n");
}

Test(my_printf, test_flag_less_nb_with_up_x, .init = redirect_all_std)
{
    unsigned int out = 0x1a2c;
    my_printf("%-10X\n", out);
    cr_assert_stdout_eq_str("1A2C      \n");
}

Test(my_printf, test_flag_plus_nb_with_up_x, .init = redirect_all_std)
{
    unsigned int out = 0x1a2c;
    my_printf("%+10X\n", out);
    cr_assert_stdout_eq_str("      1A2C\n");
}

Test(my_printf, test_flag_less_with_b, .init = redirect_all_std)
{
    unsigned int out = 0b1010;
    my_printf("%-b\n", out);
    cr_assert_stdout_eq_str("1010\n");
}

Test(my_printf, test_flag_plus_with_b, .init = redirect_all_std)
{
    unsigned int out = 0b1010;
    my_printf("%+b\n", out);
    cr_assert_stdout_eq_str("1010\n");
}

Test(my_printf, test_flag_less_nb_with_b, .init = redirect_all_std)
{
    unsigned int out = 0b1010;
    my_printf("%-10b\n", out);
    cr_assert_stdout_eq_str("1010      \n");
}

Test(my_printf, test_flag_plus_nb_with_b, .init = redirect_all_std)
{
    unsigned int out = 0b1010;
    my_printf("%+10b\n", out);
    cr_assert_stdout_eq_str("      1010\n");
}

Test(my_printf, test_flag_less_with_o, .init = redirect_all_std)
{
    unsigned int out = 01234;
    my_printf("%-o\n", out);
    cr_assert_stdout_eq_str("1234\n");
}

Test(my_printf, test_flag_plus_with_o, .init = redirect_all_std)
{
    unsigned int out = 01234;
    my_printf("%+o\n", out);
    cr_assert_stdout_eq_str("1234\n");
}

Test(my_printf, test_flag_less_nb_with_o, .init = redirect_all_std)
{
    unsigned int out = 01234;
    my_printf("%-10o\n", out);
    cr_assert_stdout_eq_str("1234      \n");
}

Test(my_printf, test_flag_plus_nb_with_o, .init = redirect_all_std)
{
    unsigned int out = 01234;
    my_printf("%+10o\n", out);
    cr_assert_stdout_eq_str("      1234\n");
}

Test(my_printf, test_flag_less_with_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%-f\n", out);
    cr_assert_stdout_eq_str("142.000000\n");
}

Test(my_printf, test_flag_plus_with_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%+f\n", out);
    cr_assert_stdout_eq_str("+142.000000\n");
}

Test(my_printf, test_flag_less_nb_with_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%-15f\n", out);
    cr_assert_stdout_eq_str("142.000000     \n");
}

Test(my_printf, test_flag_plus_nb_with_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%+15f\n", out);
    cr_assert_stdout_eq_str("    +142.000000\n");
}

Test(my_printf, test_flag_less_with_up_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%-F\n", out);
    cr_assert_stdout_eq_str("142.000000\n");
}

Test(my_printf, test_flag_plus_with_up_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%+F\n", out);
    cr_assert_stdout_eq_str("+142.000000\n");
}

Test(my_printf, test_flag_less_nb_with_up_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%-15F\n", out);
    cr_assert_stdout_eq_str("142.000000     \n");
}

Test(my_printf, test_flag_plus_nb_with_up_f, .init = redirect_all_std)
{
    double out = 142.00;
    my_printf("%+15F\n", out);
    cr_assert_stdout_eq_str("    +142.000000\n");
}

Test(my_printf, test_flag_less_with_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-e\n", out);
    cr_assert_stdout_eq_str("1.450000e+02\n");
}

Test(my_printf, test_flag_plus_with_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+e\n", out);
    cr_assert_stdout_eq_str("+1.450000e+02\n");
}

Test(my_printf, test_flag_less_nb_with_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-15e\n", out);
    cr_assert_stdout_eq_str("1.450000e+02   \n");
}

Test(my_printf, test_flag_plus_nb_with_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+15e\n", out);
    cr_assert_stdout_eq_str("  +1.450000e+02\n");
}

Test(my_printf, test_flag_less_with_up_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-E\n", out);
    cr_assert_stdout_eq_str("1.450000E+02\n");
}

Test(my_printf, test_flag_plus_with_up_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+E\n", out);
    cr_assert_stdout_eq_str("+1.450000E+02\n");
}

Test(my_printf, test_flag_less_nb_with_up_e, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-15E\n", out);
    cr_assert_stdout_eq_str("1.450000E+02   \n");
}

Test(my_printf, test_flag_less_with_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-g\n", out);
    cr_assert_stdout_eq_str("145\n");
}

Test(my_printf, test_flag_plus_with_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+g\n", out);
    cr_assert_stdout_eq_str("+145\n");
}

Test(my_printf, test_flag_less_nb_with_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-5g\n", out);
    cr_assert_stdout_eq_str("145  \n");
}

Test(my_printf, test_flag_plus_nb_with_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+5g\n", out);
    cr_assert_stdout_eq_str(" +145\n");
}

Test(my_printf, test_flag_less_with_up_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-G\n", out);
    cr_assert_stdout_eq_str("145\n");
}

Test(my_printf, test_flag_plus_with_up_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+G\n", out);
    cr_assert_stdout_eq_str("+145\n");
}

Test(my_printf, test_flag_less_nb_with_up_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-5G\n", out);
    cr_assert_stdout_eq_str("145  \n");
}

Test(my_printf, test_flag_plus_nb_with_up_g, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+5G\n", out);
    cr_assert_stdout_eq_str(" +145\n");
}

Test(my_printf, test_flag_less_with_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-A\n", out);
    cr_assert_stdout_eq_str("0X1.22P+7\n");
}

Test(my_printf, test_flag_plus_with_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+A\n", out);
    cr_assert_stdout_eq_str("+0X1.22P+7\n");
}

Test(my_printf, test_flag_less_nb_with_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-15A\n", out);
    cr_assert_stdout_eq_str("0X1.22P+7      \n");
}

Test(my_printf, test_flag_plus_nb_with_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+15A\n", out);
    cr_assert_stdout_eq_str("     +0X1.22P+7\n");
}

Test(my_printf, test_flag_less_with_up_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-A\n", out);
    cr_assert_stdout_eq_str("0X1.22P+7\n");
}

Test(my_printf, test_flag_plus_with_up_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+A\n", out);
    cr_assert_stdout_eq_str("+0X1.22P+7\n");
}

Test(my_printf, test_flag_less_nb_with_up_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%-15A\n", out);
    cr_assert_stdout_eq_str("0X1.22P+7      \n");
}

Test(my_printf, test_flag_plus_nb_with_up_a, .init = redirect_all_std)
{
    double out = 145.00;
    my_printf("%+15A\n", out);
    cr_assert_stdout_eq_str("     +0X1.22P+7\n");
}

Test(my_printf, test_flag_less_with_per, .init = redirect_all_std)
{
    my_printf("%-%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_flag_plus_with_per, .init = redirect_all_std)
{
    my_printf("%+%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_flag_less_nb_with_per, .init = redirect_all_std)
{
    my_printf("%-15%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, test_flag_plus_nb_with_per, .init = redirect_all_std)
{
    my_printf("%+15%\n");
    cr_assert_stdout_eq_str("%\n");
}
