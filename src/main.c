/*
** EPITECH PROJECT, 2022
** [PROJECT-NAME]
** File description:
** [PROJECT-NAME] main entry
*/

#include "my_stdlib.h"
#include "my_str.h"
#include "my_array.h"
#include "my_stdlib.h"
#include "my_stdio.h"

int main(void)
{

    char **arr = my_calloc(0, sizeof(char *) * 2);
    arr[0] = my_strdup("Hello");
    arr[1] = NULL;


    my_printf("size: %d\n", arr_len(arr));

    arr_free(arr);

    return 0;
}
