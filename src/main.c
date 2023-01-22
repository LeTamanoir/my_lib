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

int main(void)
{
    char *temp = "Hello world";

    my_printf("|%d| |%s| |%c| |%f|", 1234, temp, 't', 1234.5678);

    return 0;
}
