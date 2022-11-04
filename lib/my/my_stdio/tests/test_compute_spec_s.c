/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %s and %S
*/

#include <stddef.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"
#include "specifiers.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(compute_spec_lo_s, simple_str) {
    char *res = compute_spec_lo_s("Hello world");
    cr_assert_str_eq(res, "Hello world");
}

Test(my_specifier_int, string_with_many_char) {
    char *res = compute_spec_lo_s("H e L l O w O r l D");
    cr_assert_str_eq(res, "H e L l O w O r l D");
}

Test(my_specifier_int, string_back_n) {
    char *res = compute_spec_lo_s("Hello world\n");
    cr_assert_str_eq(res, "Hello world\n");
}

Test(compute_spec_lo_s, simple_str_with_number) {
    char *res = compute_spec_lo_s("01234 56789");
    cr_assert_str_eq(res, "01234 56789");
}

Test(my_specifier_int, string_with_many_numbers_and_spaces) {
    char *res = compute_spec_lo_s("0 1 2 3 4 5 6 7 8 9");
    cr_assert_str_eq(res, "0 1 2 3 4 5 6 7 8 9");
}

Test(my_specifier_int, string_double_back_n) {
    char *res = compute_spec_lo_s("Hello\n world\n");
    cr_assert_str_eq(res, "Hello\n world\n");
}

Test(my_specifier_int, string_with_many_back_n) {
    char *res = compute_spec_lo_s("0\n1\n2\n3\n4\n5\n6\n7\n8\n9");
    cr_assert_str_eq(res, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9");
}

Test(my_specifier_int, string_with_many_upper_alpha) {
    char *res = compute_spec_lo_s("AbCdEfGhIjKlMnOpQrStUvWxYz0123456789");
    cr_assert_str_eq(res, "AbCdEfGhIjKlMnOpQrStUvWxYz0123456789");
}

Test(compute_spec_up_s, simple_test_with_str, .init = redirect_all_std)
{
    my_printf("%s\n", "hello");
    cr_assert_stdout_eq_str("hello\n");
}

Test(compute_spec_up_s, up_non_printable_char_s, .init = redirect_all_std)
{
    char *str = "Hello\xc8";
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("Hello\\310\n");
}

Test(compute_spec_up_s, tilde_non_printable_char_s, .init = redirect_all_std)
{
    char *str = "Hello ~today\x7E";
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("Hello ~today~\n");
}

Test(compute_spec_up_s, space_non_printable_char_s, .init = redirect_all_std)
{
    char *str = "Hello ~today\x20";
    my_printf("%S\n", str);
    cr_assert_stdout_eq_str("Hello ~today \n");
}

Test(compute_spec_up_s, str_eq_null, .init = redirect_all_std)
{
    char *str = NULL;
    my_printf("%s\n", str);
    cr_assert_stdout_eq_str("(null)\n");
}