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

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    my_printf("%f\n", 1.0 / 3.0);
    my_printf("%f\n", 1.0 / 3.0);
    my_printf("%f\n", -1.0 / 3.0);
    my_printf("%f\n", -1.0 * 3.0);
    my_printf("%f\n", -1.0 * 30.0);
    my_printf("%f\n", 1.0 / 3.0);
    my_printf("%f\n", 1.0 * 3.0);
    my_printf("%f\n", 1.0 * 30.0);

    return 0;
}
