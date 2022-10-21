/*
** EPITECH PROJECT, 2022
** my_isprintable.c
** File description:
** returns 1 if char is printable
*/

int my_isprintable(char const *str, int i)
{
    return (
        str[i] >= ' ' && str[i] <= '~'
    );
}
