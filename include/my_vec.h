/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vector
*/

#ifndef INCLUDE_MY_VEC_
    #define INCLUDE_MY_VEC_
    #include "my_stdlib.h"
    #define VEC_SIZE    (32)


typedef struct vec_base_s {
    int capacity;
    int size;
    int el_size;
} vec_base_t;

typedef struct vec_s {
    vec_base_t base;
    char *data;
} vec_t;

typedef struct vec_int_s {
    vec_base_t base;
    int *data;
} vec_int_t;

typedef struct vec_void_s {
    vec_base_t base;
    void **data;
} vec_void_t;

int get_padded_size(int size, int pad);

void vec_clear(vec_t *vec);
void vec_remove(vec_t *vec, int idx);
void vec_insert(vec_t *vec, void *elem, int idx);
void vec_resize(vec_t *vec, int new_size);
void vec_push_back(vec_t *vec, void *elem);
void vec_void_free(vec_void_t *vec);
void vec_free(vec_t *vec);
vec_t *vec_create(int nb_data, int el_size);


#endif /* INCLUDE_MY_VEC_ */
