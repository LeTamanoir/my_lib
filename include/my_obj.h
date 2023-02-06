/*
** EPITECH PROJECT, 2022
** my_obj
** File description:
** my_obj declarations
*/

#ifndef INCLUDE_MY_OBJ_
    #define INCLUDE_MY_OBJ_
    #include "my_stdlib.h"


typedef struct obj_meta_s {
    void (*destructor)(void *);
} obj_meta_t;


/**
 * @brief allocates an object the default destructor is a simple free
 *
 * @param size  the size of the object
 * @return the allocated object
 */
void *obj_alloc(size_t size);

/**
 * @brief reallocates an object
 *
 * @param obj   the object to reallocate
 * @param size  the new size of the object
 * @return the reallocated object
 */
void *obj_realloc(void *obj, size_t size);

/**
 * @brief retrieves the metadata of an object
 *
 * @param obj   the object to get the metadata from
 * @return the metadata of the object
 */
obj_meta_t *obj_get_meta(void *obj);

/**
 * @brief frees an object
 *
 * @param obj the object to free
 */
void obj_free(void *obj);

/**
 * @brief frees multiple objects
 *
 * @param argc the number of args to free
 * @param ... the objects to free
 */
void obj_vfree(int argc, ...);


#endif /* INCLUDE_MY_OBJ_ */
