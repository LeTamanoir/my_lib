/*
** EPITECH PROJECT, 2023
** my_vec
** File description:
** vector
*/

#ifndef INCLUDE_MY_VEC_
    #define INCLUDE_MY_VEC_
    #include <stddef.h>

    #define VEC_META size_t capacity; size_t size; size_t __elem_size;
    #define VEC_DEF(t, n) typedef struct { VEC_META t data[0]; } vec_##n##_t;


typedef struct vec_s {
    VEC_META
    char data[0];
} vec_t;

VEC_DEF(void *, void)
VEC_DEF(int, int)
VEC_DEF(char, char)
VEC_DEF(long, long)
VEC_DEF(float, float)
VEC_DEF(double, double)
VEC_DEF(size_t, size)

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
void vec_foreach(void *vec, void (*fn)(void *, size_t, void *), void *data);

/**
 * @brief clears a vector
 *
 * @param vec   the vector to clear
 */
void vec_clear(void *vec);

/**
 * @brief removes an element from a vector at a given index
 *
 * @param vec   the vector to remove the element from
 * @param idx   the index of the element to remove
 */
void vec_remove(void *vec, size_t idx);

/**
 * @brief inserts an element into a vector at a given index
 *
 * @param vec   the ADRESS of the vector to insert the element in
 * @param elem  the element to insert
 * @param idx   the index at which the element will be inserted
 */
void vec_insert(void *vec, void *elem, size_t idx);

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
 * @param vec   the ADRESS of the vector to append the element to
 * @param elem  the ADRESS of element to add
 */
void vec_pushback(void *vec, void *elem);

/**
 * @brief sorts a vector
 *
 * @param vec       the vector to sort
 * @param cmp_fn    function to compare 2 elements
 *                  if cmp_fn(a, b) < 0 then a < b
 *                  if cmp_fn(a, b) > 0 then a > b
 *                  else a == b
 */
void vec_sort(void *vec, int (*cmp_fn)(void *, void *));

/**
 * @brief removes the last element of a vector
 *
 * @param vec   the vector to remove the last element from
 */
void vec_popback(void *vec);

/**
 * @brief frees a vector composed of pointers
 *        every element must ve freeable with a single free call
 *
 * @param ptr       the vector to free
 */
void vec_free(void *ptr);

/**
 * @brief gets an element from a vector at a given index
 *
 * @param vec the vector to get the element from
 * @param idx the index of the element to get
 * @return the element at the given index
 */
void *vec_at(void *vec, size_t idx);

/**
 * @brief creates a vector
 *        use obj_get_meta to modify the destructor (if needed)
 *
 * @param nb_data   the number of elements in the vector
 * @param el_size   the size of an element of the vector
 * @return the created vector
 */
void *vec_create(size_t nb_data, size_t el_size);

/**
 * @brief filters a vector
 *
 * @param vec       the vector to filter
 * @param keep_fn   the function to filter the elements
 *                  if keep_fn(elem) == 1 then the element will be kept
 * @return a new vector with the filterd elements
 */
vec_t *vec_filter(void *vec, int (*keep_fn)(void *));

/**
 * @brief finds an item from a vector with a given search function
 *
 * @param vec       the vector to search
 * @param find_fn   the function to describe what you look for
 *                  if find_fn(elem) == 1 then the element will be returned
 * @return the item if it exists or NULL
 */
void *vec_find(void *vec, int (*find_fn)(void *));


#endif /* INCLUDE_MY_VEC_ */
