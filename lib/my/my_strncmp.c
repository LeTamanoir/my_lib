/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compares the first n bytes of the two given strings
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if ((s1[0] == '\0' && s2[0] == '\0') || n == 0)
        return 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i]) break;
        if (s1[i] == s2[i] && i == n - 1) return 0;
        i++;
    }

    return s1[i] - s2[i];
}
