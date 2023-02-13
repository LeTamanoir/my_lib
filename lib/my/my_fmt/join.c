/*
** EPITECH PROJECT, 2022
** my_fmt
** File description:
** join format
*/

#include "my_stdlib.h"
#include "my_fmt.h"

void fmt_add_join(fmt_state_t *state)
{
    vec_str_t *vec = va_arg(*(state->ap), vec_str_t *);
    str_t *delim = va_arg(*(state->ap), str_t *);
    SMART str_t *temp = str_join(vec, delim);

    str_sadd(state->buffer, temp);
}
