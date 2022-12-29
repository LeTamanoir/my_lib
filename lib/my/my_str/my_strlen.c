/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** returns the number of characters of a string
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (*str++)
        len++;

    return len;
}
