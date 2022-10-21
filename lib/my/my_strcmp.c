/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compares the two given strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1[0] == '\0' && s2[0] == '\0')
        return 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) break;
        if (s1[i + 1] == '\0' && s2[i + 1] == '\0') return 0;
        i++;
    }

    if (s1[i] - s2[i] > 0)
        return 1;
    else
        return -1;
}
