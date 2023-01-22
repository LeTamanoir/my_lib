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
#include "my_fmt.h"

int keep_word(vec_t *v, size_t i)
{
    return ((vec_str_t *)v)->data[i]->length > 0;
}

int compare_words(vec_t *v, size_t i, size_t j)
{
    SMART str_t *s1 = str_tolowcase(str_dup(((vec_str_t*)v)->data[i]));
    SMART str_t *s2 = str_tolowcase(str_dup(((vec_str_t*)v)->data[j]));

    return str_compare(s1, s2);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    SMART str_t *temp = str_create(av[1]);
    SMART vec_str_t *split = str_split(temp, str_temp(" \t"));
    SMART vec_str_t *words = (vec_str_t*)vec_filter((vec_t *)split, &keep_word);
    SMART str_t *buff = NULL;

    vec_sort((vec_t *)words, &compare_words);

    buff = str_join(words, str_temp(" "));
    str_println(buff);

    return 0;
}
