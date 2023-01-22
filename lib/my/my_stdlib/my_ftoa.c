/*
** EPITECH PROJECT, 2022
** my_stdlib
** File description:
** my_ftoa
*/

#include "my_math.h"
#include "my_str.h"

char *my_ftoa(double nb, int precision)
{
    char *int_part = my_itoa((long int)nb);
    nb -= (long int)nb;
    char *float_part = my_itoa((long int)(nb * my_powl(10, precision)));

    char *res = malloc(sizeof(char) *
        (my_strlen(int_part) + my_strlen(float_part) + 2));

    my_strcpy(res, int_part);
    if (precision > 0) {
        my_strcat(res, ".");
        my_strcat(res, float_part);
    }
    vfree(2, int_part, float_part);

    return res;
}
