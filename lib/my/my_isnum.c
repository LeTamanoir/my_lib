/*
** EPITECH PROJECT, 2022
** my_isnum.c
** File description:
** returns 1 if char is numeric
*/

int my_isnum(char const *str, int i)
{
    return (
        str[i] >= '0' && str[i] <= '9'
    );
}
