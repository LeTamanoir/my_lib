/*
** EPITECH PROJECT, 2022
** my_network
** File description:
** utils
*/

#include "my_network.h"
#include "my_stdio.h"
#include "my_math.h"
#include "my_str.h"
#include "my_stdlib.h"
#include "my_obj.h"

int read_client(client_t *client)
{
    static char buff_temp[NETWORK_BUFF_SIZE] = {0};
    ssize_t size = 0;

    size = read(client->sock, buff_temp, NETWORK_BUFF_SIZE);

    if (client->read->length < NETWORK_BUFF_SIZE)
        str_nadd(&client->read, buff_temp, size);
    return size;
}

int write_client(client_t *client)
{
    str_t **write_buff = &client->write;
    size_t size = 0;

    if ((*write_buff)->length == 0)
        return -1;
    size = write(client->sock, (*write_buff)->data, (*write_buff)->length);

    if (size == (*write_buff)->length)
        str_clear(write_buff);
    else if (size < (*write_buff)->length)
        str_slice(write_buff, size, (*write_buff)->length);

    return size;
}

int write_server(int sock, str_t *buff)
{
    size_t size = 0;

    size = write(sock, buff->data, buff->length);

    return size;
}

int read_server(int sock, str_t **buff)
{
    static char buff_temp[NETWORK_BUFF_SIZE] = {0};
    size_t size = 0;

    size = read(sock, buff_temp, NETWORK_BUFF_SIZE);
    str_nadd(buff, buff_temp, size);

    return size;
}
