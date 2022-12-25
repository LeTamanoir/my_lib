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

int main(void)
{
    map_t *map = yaml_parse("./test.yaml");

    my_printf("map[%s] = %d\n", "tot", *(int*)yaml_get(map, "tot")->data);

    map_free(map);

    return 0;
}
