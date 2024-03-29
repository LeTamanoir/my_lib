/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** my_stdlib declarations
*/

#ifndef INCLUDE_MY_STDLIB_
    #define INCLUDE_MY_STDLIB_
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdbool.h>

    #define SMART           __attribute__((cleanup(auto_free)))
    #define MAX_SWAP_SIZE   (1024)


typedef struct {
    size_t size;
} alloc_meta_t;

void auto_free(void *ptr);

size_t my_nbrlen(long int nb, int base);
char *my_itoa(long int nb);
long int my_atoi(char const *str);
double my_atof(char const *str);

/**
 * @brief ftoa with full precision (slow)
 */
char *my_ftoa(double data, int precision);

/**
 * @brief ftoa with limited precision (fast)
 */
char *my_fftoa(double data, int precision);

void *my_malloc(size_t size);
void my_free(void *ptr);
void my_vfree(int argc, ...);
void *my_realloc(void *ptr, size_t size);
void *my_calloc(size_t count, size_t elem_size);
void my_swap(void *a, void *b, size_t el_size);

int my_memcmp(void const *m1, void const *m2, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *dest, unsigned char c, size_t len);


#endif /* INCLUDE_MY_STDLIB_ */
