/*
** EPITECH PROJECT, 2022
** my_isalpha.c
** File description:
** return 1 if char is alpha
*/

int my_isalpha(char const *str, int i)
{
    return (
        (str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z')
    );
}
