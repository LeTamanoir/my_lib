/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** my_stdlib declarations
*/

#ifndef INCLUDE_MY_STDLIB_
    #define INCLUDE_MY_STDLIB_
    #include <stdlib.h>

    #define SMART           __attribute__((cleanup(auto_free)))


void auto_free(void *ptr);

void *my_calloc(size_t count, size_t elem_size);
char *my_itoa(long int nb);
int my_atoi(char const *str);
double my_atof(char const *str);
void *my_memcpy(void *dest, const void *src, size_t n);
int my_memcmp(void const *m1, void const *m2, size_t el);
void *my_memset(void *dest, char c, size_t len);
void vfree(int argc, ...);


#endif /* INCLUDE_MY_STDLIB_ */
