/*
** EPITECH PROJECT, 2022
** my_vec
** File description:
** misc
*/

int get_padded_size(int size, int pad)
{
    int size_pad = 0;

    while (size_pad < size)
        size_pad += pad;

    return size_pad;
}
