/*
** EPITECH PROJECT, 2022
** int specifier test
** File description:
** tests for specifier %b
*/

#include <criterion/criterion.h>

#include "specifiers.h"

Test(compute_spec_b, simple_short_bin) {
    unsigned long long int bin;
    bin = (unsigned short int)0b111010;
    char *res = compute_spec_b(&bin);
    cr_assert_str_eq(res, "111010");
}

Test(compute_spec_b, simple_bin) {
    unsigned long long int bin;
    bin = (unsigned int)0b10110101001000101011111111;
    char *res = compute_spec_b(&bin);
    cr_assert_str_eq(res, "10110101001000101011111111");
}

Test(compute_spec_b, simple_short_int_to_bin) {
    unsigned long long int integer;
    integer = (unsigned short int)58;
    char *res = compute_spec_b(&integer);
    cr_assert_str_eq(res, "111010");
}

Test(compute_spec_b, simple_int_to_bin) {
    unsigned long long int integer;
    integer = (unsigned int)47483647;
    char *res = compute_spec_b(&integer);
    cr_assert_str_eq(res, "10110101001000101011111111");
}

Test(compute_spec_b, simple_long_int_to_bin) {
    unsigned long long int integer;
    integer = (unsigned long long int)281474976710655;
    char *res = compute_spec_b(&integer);
    cr_assert_str_eq(res, "111111111111111111111111111111111111111111111111");
}

Test(compute_spec_b, simple_short_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned short int)0x3A;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "111010");
}

Test(compute_spec_b, simple_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned int)0x2D48AFF;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "10110101001000101011111111");
}

Test(compute_spec_b, simple_long_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned long int)0x1FFFFFFFF;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "111111111111111111111111111111111");
}

Test(compute_spec_b, simple_long_long_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned long long int)0xFFFFFFFFFFFF;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "111111111111111111111111111111111111111111111111");
}

Test(compute_spec_b, simple_oct_to_bin) {
    unsigned long long int oct;
    oct = (unsigned int)0265105377;
    char *res = compute_spec_b(&oct);
    cr_assert_str_eq(res, "10110101001000101011111111");
}

Test(compute_spec_b, simple_long_oct_to_bin) {
    unsigned long long int oct;
    oct = (unsigned long int)077777777777;
    char *res = compute_spec_b(&oct);
    cr_assert_str_eq(res, "111111111111111111111111111111111");
}

Test(compute_spec_b, simple_long_long_oct_to_bin) {
    unsigned long long int oct;
    oct = (unsigned long long int)07777777777777777;
    char *res = compute_spec_b(&oct);
    cr_assert_str_eq(res, "111111111111111111111111111111111111111111111111");
}

Test(compute_spec_b, ushort_int_max_bin) {
    unsigned long long int bin;
    bin = (unsigned short int)0b1111111111111111;
    char *res = compute_spec_b(&bin);
    cr_assert_str_eq(res, "1111111111111111");
}

Test(compute_spec_b, uint_max_bin) {
    unsigned long long int bin;
    bin = (unsigned int)0b11111111111111111111111111111111;
    char *res = compute_spec_b(&bin);
    cr_assert_str_eq(res, "11111111111111111111111111111111");
}

Test(compute_spec_b, ulong_int_max_bin) {
    unsigned long long int bin;
    bin = (unsigned long int){
    0b1111111111111111111111111111111111111111111111111111111111111111
    };
    char *res = compute_spec_b(&bin);
    cr_assert_str_eq(res, "1111111111111111111111111111111111111111"
    "111111111111111111111111");
}

Test(compute_spec_b, ushort_int_max_oct_to_bin) {
    unsigned long long int oct;
    oct = (unsigned short int)0177777;
    char *res = compute_spec_b(&oct);
    cr_assert_str_eq(res, "1111111111111111");
}

Test(compute_spec_b, uint_max_oct_to_bin) {
    unsigned long long int oct;
    oct = (unsigned int)037777777777;
    char *res = compute_spec_b(&oct);
    cr_assert_str_eq(res, "11111111111111111111111111111111");
}

Test(compute_spec_b, ulong_int_max_oct_to_bin) {
    unsigned long long int oct;
    oct = (unsigned long int)01777777777777777777777;
    char *res = compute_spec_b(&oct);
    cr_assert_str_eq(res, "1111111111111111111111111111111111111111"
    "111111111111111111111111");
}

Test(compute_spec_b, ushort_int_max_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned short int)0xFFFF;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "1111111111111111");
}

Test(compute_spec_b, uint_max_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned int)0xFFFFFFFF;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "11111111111111111111111111111111");
}

Test(compute_spec_b, ulong_int_max_hex_to_bin) {
    unsigned long long int hex;
    hex = (unsigned long int)0xFFFFFFFFFFFFFFFF;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "1111111111111111111111111111111111111111"
    "111111111111111111111111");
}

Test(compute_spec_b, ushort_int_max_int_to_bin) {
    unsigned long long int hex;
    hex = (unsigned short int)65535;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "1111111111111111");
}

Test(compute_spec_b, uint_max_int_to_bin) {
    unsigned long long int hex;
    hex = (unsigned int)4294967295U;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "11111111111111111111111111111111");
}

Test(compute_spec_b, ulong_int_max_int_to_bin) {
    unsigned long long int hex;
    hex = (unsigned long int)18446744073709551615UL;
    char *res = compute_spec_b(&hex);
    cr_assert_str_eq(res, "1111111111111111111111111111111111111111\
111111111111111111111111");
}
