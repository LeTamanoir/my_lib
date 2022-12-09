/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }

    for (; i < n; i++) {
        dest[i] = '\0';
    }

    return dest;
}
