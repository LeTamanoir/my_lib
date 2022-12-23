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

int main(void)
{
    // str_t *toto = str_create("Etienne est un putain de gros chauve pas bo !!!");

    // my_printf("_%s_\n", toto->data);

    // vec_void_t *test = str_split(toto, ' ');

    // for (int i = 0; i < test->base.size; i++) {
    //     my_printf("_%s_ ", (char*)test->data[i]);
    // }
    // vec_void_free(test);
    // str_free(toto);

    // my_puts("");

    map_t *map = map_create(10);
    char key1[] = "Helloa";
    char key2[] = "Hellob";
    char key3[] = "Helloc";
    char key4[] = "Hellod";

    map_set(map, key1, my_strdup("je suis chauve 1"));
    map_set(map, key2, my_strdup("je suis chauve 2"));
    map_set(map, key3, my_strdup("je suis chauve 3"));
    map_set(map, key4, my_strdup("je suis chauve 4"));
    map_set(map, "cacaa", my_strdup("cacaa"));

    my_printf("map[%s] = %s\n", key1, map_get(map, key1));
    my_printf("map[%s] = %s\n", key2, map_get(map, key2));
    my_printf("map[%s] = %s\n", key3, map_get(map, key3));
    my_printf("map[%s] = %s\n", key4, map_get(map, key4));
    my_printf("map[%s] = %s\n", "cacaa", map_get(map, "cacaa"));

    my_printf("map {size: %d, el_size: %d, capacity: %d}\n",
        map->elems->base.size,
        map->elems->base.el_size,
        map->elems->base.capacity
    );

    for (int i = 0; i < map->elems->base.capacity; i++) {
        vec_void_t *temp = map->elems->data[i];
        if (temp == NULL) continue;

        my_printf("map[%d] {size: %d, el_size: %d, capacity: %d}\n",
            i,
            temp->base.size,
            temp->base.el_size,
            temp->base.capacity
        );
    }

    map_free(map);

    return 0;
}
