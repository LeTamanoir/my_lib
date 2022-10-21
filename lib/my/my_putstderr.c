/*
** EPITECH PROJECT, 2022
** my_putstderr.c
** File description:
** printfs a string to the error output
*/

#include <unistd.h>

void my_putstderr(char const *str)
{
    while (*str != '\0') {
        write(2, str, 1);
        str++;
    }
}
