/*
** EPITECH PROJECT, 2022
** my_detect_overflow.c
** File description:
** helper function to detect int overflows
*/

int my_detect_overflow(long number, long to_multiply)
{
    return number * to_multiply != (int)((int)number * (int)to_multiply);
}
