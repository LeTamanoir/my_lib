/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** specifier oct %o
*/

#include "my_string.h"
#include "my_stdlib.h"
#include "spec_int_utils.h"

char *compute_spec_o(void *ptr)
{
    unsigned long long int oct = *(unsigned long long int *)ptr;
    char const *base = "01234567";

    int base_len = my_strlen(base);
    int new_length = get_base_nbr_length(oct, base_len);
    int utils[] = { new_length - 1, base_len };
    char *str = my_calloc('\0', sizeof(char) * (new_length + 1));

    compute_number(str, base, oct, utils);

    return str;
}
