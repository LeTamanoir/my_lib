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
    SMART str_t *str = str_create("Hello, World!");

    str_replace(&str, STR_TEMP("Hel"), STR_TEMP("dadas"));

    str_println(str);

    return 0;
}
