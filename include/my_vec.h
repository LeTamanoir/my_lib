/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vector
*/

#ifndef INCLUDE_MY_VEC_
    #define INCLUDE_MY_VEC_
    #include "my_stdlib.h"
    #define MAX_VEC_ELEM_SIZE   (1024)


typedef struct vec_base_s {
    size_t capacity;
    size_t size;
    size_t el_size;
} vec_base_t;

typedef struct vec_s {
    vec_base_t base;
    char data[0];
} vec_t;

typedef struct vec_int_s {
    vec_base_t base;
    int data[0];
} vec_int_t;

typedef struct vec_void_s {
    vec_base_t base;
    void *data[0];
} vec_void_t;

size_t get_padded_size(size_t size);

void vec_for_each(vec_t *vec, void (*fn)(void *, void *), void *data);
void vec_clear(vec_t *vec);
void vec_remove(vec_t *vec, size_t idx);
void vec_insert(vec_t **vec, void *elem, size_t idx);
void vec_resize(vec_t **vec, size_t new_size);
void vec_push_back(vec_t **vec, void *elem);
void vec_sort(vec_t *vec, int (*key)(vec_t *, int));
void vec_swap(vec_t *vec, size_t i, size_t j);
void vec_free(vec_t *vec, void (*free_fn)(void *));
vec_t *vec_create(size_t nb_data, size_t el_size);


#endif /* INCLUDE_MY_VEC_ */
