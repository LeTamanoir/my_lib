/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copies a string into an other
*/

char *my_strcpy(char *dest, char const *src)
{
    int index = 0;

    while (src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }

    dest[index] = '\0';

    return dest;
}
