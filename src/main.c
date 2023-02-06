/*
** EPITECH PROJECT, 2022
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include "my_str.h"
#include "my_stdio.h"
#include "my_stdlib.h"
#include "my_vec.h"
#include "my_map.h"
#include "my_yaml.h"
#include "my_fmt.h"
#include "my_obj.h"

int main(void)
{
    SMART str_t *str = str_create("");

    while (str->length < 1000000) {
        str_add(&str, "Hello World !\n");
    }

    str_println(str);

    return 0;
}
