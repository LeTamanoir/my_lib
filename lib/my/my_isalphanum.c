/*
** EPITECH PROJECT, 2022
** my_isalphanum.c
** File description:
** returns 1 if char is alphanum
*/

int my_isalphanum(char const *str, int i)
{
    return (
        (str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= '0' && str[i] <= '9')
    );
}
