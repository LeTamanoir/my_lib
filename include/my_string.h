/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** my_string declarations
*/

#pragma once

int my_isalpha(char chr);

int my_islower(char chr);

int my_isnum(char chr);

int my_isprintable(char chr);

int my_isupper(char chr);

int my_isalphanum(char chr);

char my_upcase(char chr);

char my_lowcase(char chr);


char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char const *src);

int my_strlen(char const *str);

void my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

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

char **my_str_to_word_array(char const *str);

int my_show_word_array(char * const *tab);

typedef struct string_s string_t;
typedef struct string_s {
    char *content;

    void (*add)(string_t *this, char *new);
    void (*fadd)(string_t *this, char *fmt, ...);
} string_t;

string_t *string_create(char *init);
void string_free(string_t *string);
