/*
** EPITECH PROJECT, 2023
** my_stdlib
** File description:
** my_ftoa
*/

#include "my_stdlib.h"
#include "my_math.h"
#include "my_str.h"

char *my_fftoa(double nb, int precision)
{
    char *int_ = my_itoa((long int)nb);
    char *float_ = NULL;
    char *res = NULL;

    nb -= (long int)nb;
    float_ = my_itoa((long int)(MY_FABS(nb) * my_powl(10, precision)));
    res = my_malloc(sizeof(char) * (my_strlen(int_) + my_strlen(float_) + 2));
    my_strcpy(res, int_);
    if (precision > 0) {
        my_strcat(res, ".");
        my_strcat(res, float_);
    }
    my_vfree(2, int_, float_);
    return res;
}
