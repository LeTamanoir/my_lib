/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** vector
*/

#ifndef INCLUDE_MY_VEC_
    #define INCLUDE_MY_VEC_
    #include <stddef.h>

    #define VEC_META size_t capacity; size_t size; size_t __elem_size


typedef struct {
    VEC_META;
    char data[0];
} vec_t;

typedef struct {
    VEC_META;
    void *data[0];
} vec_void_t;

typedef struct {
    VEC_META;
    char data[0];
} vec_char_t;

typedef struct {
    VEC_META;
    int data[0];
} vec_int_t;

typedef struct {
    VEC_META;
    long data[0];
} vec_long_t;

typedef struct {
    VEC_META;
    float data[0];
} vec_float_t;

typedef struct {
    VEC_META;
    double data[0];
} vec_double_t;

typedef struct {
    VEC_META;
    size_t data[0];
} vec_size_t_t;


size_t get_padded_size(size_t size);

/**
 * @brief runs a functions on every element of a vector
 *
 * @param vec   the vector to preform the logic on
 * @param fn    the function to call, it will be called like this:
 *              fn(current_elem_in_vec, data)
 *              if you want to block further execution return 1
 *              else return 0
 * @param data  additionnal data that you can use in the fn
 */
void vec_foreach(vec_t *vec, void (*fn)(void *, size_t, void *), void *data);

/**
 * @brief clears a vector
 *
 * @param vec   the vector to clear
 */
void vec_clear(vec_t *vec);

/**
 * @brief removes an element from a vector at a given index
 *
 * @param vec   the vector to remove the element from
 * @param idx   the index of the element to remove
 */
void vec_remove(vec_t *vec, size_t idx);

/**
 * @brief inserts an element into a vector at a given index
 *
 * @param vec   the vector to insert the element in
 * @param elem  the element to insert
 * @param idx   the index at which the element will be inserted
 */
void vec_insert(vec_t **vec, void *elem, size_t idx);

/**
 * @brief resizes a vector to a new given size
 *
 * @param vec       the vector to resize
 * @param new_size  the new size
 * @return the resized vector
 */
vec_t **vec_resize(vec_t **vec, size_t new_size);

/**
 * @brief adds an element at the back of a vector
 *
 * @param vec   the vector to append the element to
 * @param elem  the element to add
 */
void vec_pushback(vec_t **vec, void *elem);

/**
 * @brief sorts a vector
 *
 * @param vec       the vector to sort
 * @param cmp_fn    function to compare 2 elements
 *                  if cmp_fn(a, b) < 0 then a < b
 *                  if cmp_fn(a, b) > 0 then a > b
 *                  else a == b
 */
void vec_sort(vec_t *vec, int (*cmp_fn)(void *, void *));

/**
 * @brief removes the last element of a vector
 *
 * @param vec   the vector to remove the last element from
 */
void vec_popback(vec_t *vec);

/**
 * @brief frees a vector composed of pointers
 *        every element must ve freeable with a single free call
 *
 * @param vec       the vector to free
 */
void vec_free(vec_t *vec);

/**
 * @brief gets an element from a vector at a given index
 *
 * @param vec the vector to get the element from
 * @param idx the index of the element to get
 * @return the element at the given index
 */
void *vec_at(vec_t *vec, size_t idx);

/**
 * @brief creates a vector with vec_free as its default destructor
 *        use obj_set_destructor to modify it if needed
 *
 * @param nb_data   the number of elements in the vector
 * @param el_size   the size of an element of the vector
 * @return the created vector
 */
vec_t *vec_create(size_t nb_data, size_t el_size);

/**
 * @brief filters a vector
 *
 * @param vec       the vector to filter
 * @param keep_fn   the function to filter the elements
 *                  if keep_fn(elem) == 1 then the element will be kept
 * @return a new vector with the filterd elements
 */
vec_t *vec_filter(vec_t *vec, int (*keep_fn)(void *));

/**
 * @brief finds an item from a vector with a given search function
 *
 * @param vec       the vector to search
 * @param find_fn   the function to describe what you look for
 *                  if find_fn(elem) == 1 then the element will be returned
 * @return the item if it exists or NULL
 */
void *vec_find(vec_t *vec, int (*find_fn)(void *));


#endif /* INCLUDE_MY_VEC_ */
