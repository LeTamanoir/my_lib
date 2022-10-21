/*
** EPITECH PROJECT, 2022
** my_islower.c
** File description:
** returns 1 if char is lower
*/

int my_islower(char const *str, int i)
{
    return (
        str[i] >= 'a' && str[i] <= 'z'
    );
}
