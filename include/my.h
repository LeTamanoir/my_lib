/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** declarations for my lib
*/

#include <bits/types/FILE.h>

#pragma once

// stdio functions

int my_printf(const char *format, ...);

int my_sprintf(char *str, const char *format, ...);

int my_dprintf(int fd, const char * format, ...);

int my_fprintf(FILE *stream, const char *format, ...);


// print helpers

void my_putchar(char c);

int my_putstr(char const *str);

int my_putstderr(char const *str);

int my_put_nbr(int nb);

int printf(const char *restrict format, ...);


// compute helpers

int my_pow(int number, int power);

int my_int_sqrt(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_nbr_length(long long nb);

long long my_ll_pow(long long number, int power);

char *my_itoa(long long nb);

// str helpers

int my_strlen(char const *str);

void my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

void my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char const *src);

char **my_str_to_word_array(char const *str);

int my_show_word_array(char * const *tab);


// character helpers

int my_isalpha(char chr);

int my_islower(char chr);

int my_isnum(char chr);

int my_isprintable(char chr);

int my_isupper(char chr);

int my_isalphanum(char chr);


// misc

int my_detect_overflow(int number, int to_multiply);

int my_putnbr_base(int nbr, char const *base);

int my_showmem(char const *str, int size);

int my_getnbr_base(char const *str, char const *base);

char *my_convert_base(
    char const *nbr,
    char const *base_from,
    char const *base_to
);

void my_swap(int *a, int *b);

void *my_calloc(char pad, int size);
