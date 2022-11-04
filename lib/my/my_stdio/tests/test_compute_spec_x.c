/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %x and %X
*/

#include <criterion/criterion.h>

#include "specifiers.h"

Test(compute_spec_lo_x, upper_to_lower)
{
    unsigned long long int input;
    input = (unsigned int)0x8A4;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "8a4");
}

Test(compute_spec_lo_x, simple_lower)
{
    unsigned long long int input;
    input = (unsigned int)0x8a4;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "8a4");
}

Test(compute_spec_lo_x, int_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)42;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "2a");
}

Test(compute_spec_lo_x, sizeup_int_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)59874577;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "3919d11");
}

Test(compute_spec_lo_x, bin_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)0b101010;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "2a");
}

Test(compute_spec_lo_x, oct_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)0475;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "13d");
}

Test(compute_spec_lo_x, test_max_unsigned_lohex)
{
    unsigned long long int input;
    input = (unsigned int)0xffffffff;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "ffffffff");
}

Test(compute_spec_lo_x, convert_max_unsigned_uphex_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)0xFFFFFFFF;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "ffffffff");
}

Test(compute_spec_lo_x, convert_max_unsigned_int_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)4294967295;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "ffffffff");
}

Test(compute_spec_lo_x, convert_max_unsigned_oct_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)037777777777;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "ffffffff");
}

Test(compute_spec_lo_x, convert_max_unsigned_bin_to_lohex)
{
    unsigned long long int input;
    input = (unsigned int)0b11111111111111111111111111111111;
    char *res = compute_spec_lo_x(&input);
    cr_assert_str_eq(res, "ffffffff");
}


Test(compute_spec_up_x, lower_to_upper)
{
    unsigned long long int input;
    input = (unsigned int)0x8a4;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "8A4");
}

Test(compute_spec_up_x, simple_upper)
{
    unsigned long long int input;
    input = (unsigned int)0x8A4;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "8A4");
}

Test(compute_spec_up_x, int_to_hex)
{
    unsigned long long int input;
    input = (unsigned int)42;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "2A");
}

Test(compute_spec_up_x, sizeup_int_to_hex)
{
    unsigned long long int input;
    input = (unsigned int)59874577;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "3919D11");
}

Test(compute_spec_up_x, bin_to_hex)
{
    unsigned long long int input;
    input = (unsigned int)0b101010;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "2A");
}

Test(compute_spec_up_x, oct_to_hex)
{
    unsigned long long int input;
    input = (unsigned int)0475;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "13D");
}

Test(compute_spec_up_x, test_max_unsigned_uphex)
{
    unsigned long long int input;
    input = (unsigned int)0xFFFFFFFF;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "FFFFFFFF");
}

Test(compute_spec_up_x, convert_max_unsigned_lohex_to_uphex)
{
    unsigned long long int input;
    input = (unsigned int)0xffffffff;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "FFFFFFFF");
}

Test(compute_spec_up_x, convert_max_unsigned_int_to_uphex)
{
    unsigned long long int input;
    input = (unsigned int)4294967295;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "FFFFFFFF");
}

Test(compute_spec_up_x, convert_max_unsigned_oct_to_uphex)
{
    unsigned long long int input;
    input = (unsigned int)037777777777;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "FFFFFFFF");
}

Test(compute_spec_up_x, convert_max_unsigned_bin_to_uphex)
{
    unsigned long long int input;
    input = (unsigned int)0b11111111111111111111111111111111;
    char *res = compute_spec_up_x(&input);
    cr_assert_str_eq(res, "FFFFFFFF");
}
