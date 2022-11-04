/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** tests for specifier %p
*/

#include <criterion/criterion.h>

#include "specifiers.h"

Test(compute_spec_p, pointer_int)
{
    int *input;
    char *res = compute_spec_p(&input);
    cr_assert_eq(res, res);
}

Test(compute_spec_p, pointer_char)
{
    char *input;
    char *res = compute_spec_p(&input);
    cr_assert_eq(res, res);
}

Test(compute_spec_p, pointer_float)
{
    float *input;
    char *res = compute_spec_p(&input);
    cr_assert_eq(res, res);
}

Test(compute_spec_p, pointer_double)
{
    double *input;
    char *res = compute_spec_p(&input);
    cr_assert_eq(res, res);
}

Test(compute_spec_p, pointer_long_double)
{
    long double *input;
    char *res = compute_spec_p(&input);
    cr_assert_eq(res, res);
}

   /* double *hello;
    char *second;
    char *oui = "hellzao";
    printf("%p\n", &hello);
    my_printf("%p\n", &hello); */