/*
** EPITECH PROJECT, 2022
** my_list
** File description:
** linked_list declarations
*/

#ifndef INCLUDE_MY_LIST_
    #define INCLUDE_MY_LIST_


typedef struct node_s {
    void *value;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct list_s {
    node_t *front;
    node_t *back;
    int size;
} list_t;

list_t *list_create(void);
void list_free(list_t *list);

void list_push_front(list_t *list, void *value);
void list_push_back(list_t *list, void *value);
void list_pop_front(list_t *list);
void list_pop_back(list_t *list);

void list_for_each(list_t *list, void (*fn)(void *, void *), void *data);

void node_free(node_t *node);
node_t *node_create(void);


#endif /* INCLUDE_MY_LIST_ */
