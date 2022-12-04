/*
** EPITECH PROJECT, 2022
** my_stdio
** File description:
** lk_list utils declarations
*/

#include "my_lk_list.h"

#pragma once

lk_node_t *create_new_node(void);
void lk_list_insert(lk_list_t *this, lk_node_t *node);
void lk_list_add(lk_list_t *this, void *value);
