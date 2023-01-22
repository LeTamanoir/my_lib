/*
** EPITECH PROJECT, 2022
** my_fmt
** File description:
** formatter declarations
*/

#ifndef INCLUDE_MY_FMT_
    #define INCLUDE_MY_FMT_
    #include <stdarg.h>
    #include <stdint.h>
    #include "my_str.h"

/**
 * @category formats
 *
 * @param %% -> %
 * @param %c -> char
 * @param %S -> str_t
 * @param %s -> string
 * @param %d -> int
 * @param %f -> float
 * @param %b -> base lowercase : expected base
 * @param %B -> base uppercase : expected base
 *
 * @category width
 *
 * @param * -> width in va_arg
 * @param X -> width
 *
 * @category precision
 *
 * @param .* -> prec in va_arg
 * @param .X -> prec
 *
 * @category type indicator
 *
 * @param l -> long
 */

typedef struct fmt_state_s {
    str_t *buffer;
    va_list *ap;
    char is_long;
    int precision;
} fmt_state_t;

typedef struct fmt_map_s {
    char fmt;
    void (*fmt_fn)(fmt_state_t *);
} fmt_map_t;

// DON'T USE THESE
void fmt_add_int(fmt_state_t *state);
void fmt_add_str(fmt_state_t *state);
void fmt_add_str_t(fmt_state_t *state);
void fmt_add_char(fmt_state_t *state);
void fmt_add_float(fmt_state_t *state);
void fmt_add_lobase(fmt_state_t *state);
void fmt_add_upbase(fmt_state_t *state);


/**
 * @brief creates a formated string
 *
 * @param fmt   the format
 * @param ap    the va_list
 * @return the formatted string
 */
str_t *fmt_create(char const *fmt, va_list *ap);


#endif /* INCLUDE_MY_FMT_ */
