/*
** EPITECH PROJECT, 2022
** my_sort_int_array.c
** File description:
** sorts an integer array in ascending order
*/

static int my_get_min(int *array, int size, int i)
{
    for (int j = i; j < size; j++) {
        if (array[i] > array[j])
            i = j;
    }

    return i;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        int min = my_get_min(array, size, i);
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}
