/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** linked_list declarations
*/

#ifndef INCLUDE_MY_LIST_
    #define INCLUDE_MY_LIST_
    #include <stddef.h>
    #include "my_vec.h"

typedef struct node_s {
    void *data;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *front;
    node_t *back;
    size_t size;
} list_t;

VEC_DEF(list_t *, list);

/**
 * @brief creates a doubly linked list with list_free as its default destructor
 *        use obj_get_meta to modify it if needed
 *
 * @return a new list
 */
list_t *list_create(void);

/**
 * @brief frees a list and its content
 *        each node's data must be free-able with only one free call
 *
 * @param ptr      the list to free
 */
void list_free(void *ptr);

/**
 * @brief adds a new element to the front of a list
 *
 * @param list  the list to add the element to
 * @param data the data of the element
 */
void list_pushfront(list_t *list, void *data);

/**
 * @brief removes an element from a list without freeing it
 *
 * @param list the list to remove the element from
 * @param elem the element to remove
 */
void list_unlink(list_t *list, node_t *elem);

/**
 * @brief inserts a new element after another one
 *
 * @param list  the list to add the element to
 * @param after the element to add the new element after
 * @param data  the data of the new element
 */
void list_insert(list_t *list, node_t *after, void *data);

/**
 * @brief removes an element from a list
 *
 * @param list the list to remove the element from
 * @param elem the element to remove
 */
void list_remove(list_t *list, node_t *elem);

/**
 * @brief adds a new element to the back of a list
 *
 * @param list  the list to add the element to
 * @param data the data of the element
 */
void list_pushback(list_t *list, void *data);

/**
 * @brief removes the first element of a list
 *
 * @param list  the list to remove the element from
 */
void list_popfront(list_t *list);

/**
 * @brief removes the last element of a list
 *
 * @param list  the list to remove the element from
 */
void list_popback(list_t *list);

/**
 * @brief runs a functions on every element of a list
 *
 * @param list  the list to preform the logic on
 * @param fn    the function to call, it will be called like this:
 *              fn(current_elem_in_list->data, data);
 * @param data  additionnal data that you can use in the fn
 */
void list_foreach(list_t *list, void (*fn)(void *, void *), void *data);

/**
 * @brief sorts a linked list
 *
 * @param list      the list to sort
 * @param cmp_fn    the function to use to compare two elements
 */
void list_sort(list_t *list, int (*cmp_fn)(void *, void *));

/**
 * @brief frees a node of a list
 *
 * @param node  the node to free
 */
void node_free(node_t *node);

/**
 * @brief creates a node for a list
 *
 * @return a new node
 */
node_t *node_create(void);


#endif /* INCLUDE_MY_LIST_ */
