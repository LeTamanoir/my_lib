/*
** EPITECH PROJECT, 2022
** my_detect_overflow.c
** File description:
** helper function to detect int overflows
*/

int my_detect_overflow(int number, int to_multiply)
{
    long int correct_number = (long)number * (long)to_multiply;

    return correct_number != number * to_multiply;
}
