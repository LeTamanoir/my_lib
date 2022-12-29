/*
** EPITECH PROJECT, 2022
** my_map
** File description:
** utils
*/

// from some gourou lol

unsigned int map_hash_key(char *key)
{
    unsigned h = 0x811c9dc5;

    for (int i = 0; key[i]; i++)
        h = (h ^ key[i]) * 0x01000193;

    return h;
}
