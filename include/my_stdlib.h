/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** my_stdlib declarations
*/

#ifndef INCLUDE_MY_STDLIB_
    #define INCLUDE_MY_STDLIB_
    #include <stdlib.h>


void *my_calloc(char pad, size_t size);
char *my_itoa(long long nb);
int my_atoi(char const *str);
double my_atof(char const *str);
void *my_memcpy(void *dest, const void *src, size_t n);


#endif /* INCLUDE_MY_STDLIB_ */
