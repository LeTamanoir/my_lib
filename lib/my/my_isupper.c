/*
** EPITECH PROJECT, 2022
** my_isupper.c
** File description:
** returns 1 if char is upper
*/

int my_isupper(char const *str, int i)
{
    return (
        str[i] >= 'A' && str[i] <= 'Z'
    );
}
