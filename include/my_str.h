/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** my_str declarations
*/

#ifndef INCLUDE_MY_STR_
    #define INCLUDE_MY_STR_
    #include <stddef.h>
    #include "my_vec.h"
    #define STR_SIZE     (128)


int my_isalpha(char chr);
int my_islower(char chr);
int my_isnum(char chr);
int my_isprintable(char chr);
int my_isupper(char chr);
int my_str_isfloat(char const *str);
int my_str_isint(char const *str);
int my_isalphanum(char chr);
char my_upcase(char chr);
char my_lowcase(char chr);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);

int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);

typedef struct str_s {
    int length;
    int capacity;
    char *data;
} str_t;

str_t *str_create(char const *init);
vec_void_t *str_split(str_t *str, char delim);
void str_slice(str_t *str, int start, int end);
void str_add(str_t *str, char const *new);
void str_resize(str_t *str, int new_len);
void str_nadd(str_t *str, char const *new, int n);
void str_fadd(str_t *str, char const *fmt, ...);
void str_free(str_t *str);
void str_clear(str_t *str);
void str_trim(str_t *str);


#endif /* INCLUDE_MY_STR_ */
