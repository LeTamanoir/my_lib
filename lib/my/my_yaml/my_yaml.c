/*
** EPITECH PROJECT, 2022
** my_yaml
** File description:
** VERY SIMPLE and LIMITED YAML parser
*/

#include "my_map.h"
#include "my_str.h"
#include "my_file.h"

static const int APPROX_LINE_WD = 100;
static const char LINE_DELIM = '\n';
static const char DATA_DELIM = ':';

#include "my_stdio.h"

map_t *yaml_parse(char const *file_path)
{
    file_t *file = file_create(file_path, F_R);
    if (file == NULL)
        return NULL;

    file_get_content(file);
    map_t *map = map_create(file->stats.st_size / APPROX_LINE_WD);
    vec_void_t *content = str_split(file->content, LINE_DELIM);
    str_t *line_temp = NULL;
    vec_void_t *line_split = NULL;

    for (int i = 0; i < content->base.size; i++) {
        line_temp = str_create(content->data[i]);
        line_split = str_split(line_temp, DATA_DELIM);
        str_free(line_temp);

        // if (line)

        my_printf("str[%d] = %s\n", i, content->data[i]);

        my_printf("line_split[0] = %s\n", line_split->data[0]);
        my_printf("line_split[1] = %s\n\n", line_split->data[1]);
    }

    vec_void_free(content, &free);

    return map;
}

