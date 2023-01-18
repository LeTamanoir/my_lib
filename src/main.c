/*
** EPITECH PROJECT, 2022
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include "my_str.h"
#include "my_stdio.h"
#include "my_vec.h"
#include "my_map.h"
#include "my_yaml.h"

int keep_fn(vec_t *v, size_t i)
{
    return (((vec_str_t*)v)->data[i]->length > 0);
}

int compare_fn(vec_t *v, size_t i, size_t j)
{
    SMART_STR str_t *s1 = str_lowcase(str_dup(((vec_str_t*)v)->data[i]));
    SMART_STR str_t *s2 = str_lowcase(str_dup(((vec_str_t*)v)->data[j]));

    return str_compare(s1, s2);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    SMART_STR str_t *temp = str_create(av[1]);
    SMART_STR str_t *delim = str_create(" ");
    SMART_VEC vec_str_t *split_ = str_split(temp, delim);
    SMART vec_str_t *words = (vec_str_t*)vec_filter((vec_t*)split_, &keep_fn);
    SMART_STR str_t *output = NULL;

    vec_sort((vec_t*)words, &compare_fn);

    output = str_join(words, delim);
    str_cadd(&output, '\n');

    str_print(output);

    return 0;
}
