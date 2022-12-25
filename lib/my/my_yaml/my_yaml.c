/*
** EPITECH PROJECT, 2022
** my_yaml
** File description:
** VERY SIMPLE and LIMITED YAML parser
*/

#include "my_map.h"
#include "my_str.h"
#include "my_file.h"
#include "my_yaml.h"

static const char LINE_DELIM = '\n';
static const char DATA_DELIM = ':';

static void add_type_dispatch(map_t *map, str_t *key, str_t *data)
{
    yaml_elem_t *elem = malloc(sizeof(yaml_elem_t));

    if (my_str_isint(data->data)) {
        elem->data = malloc(sizeof(int));
        elem->type = INT;
        *(int*)elem->data = my_atoi(data->data);
    } else if (my_str_isfloat(data->data)) {
        elem->data = malloc(sizeof(double));
        elem->type = DOUBLE;
        *(double*)elem->data = my_atof(data->data);
    } else {
        elem->data = my_strdup(data->data);
        elem->type = STRING;
    }

    map_set(map, key->data, elem);
}

yaml_elem_t *yaml_get(map_t *map, char *key)
{
    return (yaml_elem_t*)map_get(map, key);
}

map_t *yaml_parse(char const *file_path)
{
    file_t *file = file_create(file_path, F_R);
    if (file == NULL)
        return NULL;

    file_get_content(file);
    vec_void_t *content = str_split(file->content, LINE_DELIM);
    map_t *map = map_create(content->base.size);
    vec_void_t *split_ = NULL;

    for (int i = 0; i < content->base.size; i++) {
        split_ = str_split(content->data[i], DATA_DELIM);
        str_trim(split_->data[0]);
        str_trim(split_->data[1]);
        add_type_dispatch(map, split_->data[0], split_->data[1]);
    }
    vec_void_free(content, (void (*)(void*))&str_free);
    return map;
}
