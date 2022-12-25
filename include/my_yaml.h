/*
** EPITECH PROJECT, 2022
** my_yaml
** File description:
** VERY SIMPLE and LIMITED YAML parser
*/

#ifndef INCLUDE_MY_YAML_
    #define INCLUDE_MY_YAML_
    #include "my_map.h"


typedef struct yaml_elem_s {
    enum {
        INT,
        DOUBLE,
        STRING
    } type;
    void *data;
} yaml_elem_t;

yaml_elem_t *yaml_get(map_t *map, char *key);
map_t *yaml_parse(char const *file_path);


#endif /* INCLUDE_MY_YAML_ */
