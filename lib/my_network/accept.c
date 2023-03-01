/*
** EPITECH PROJECT, 2023
** my_network
** File description:
** accept new client
*/

#include "my_network.h"
#include "my_vec.h"
#include "my_str.h"
#include "my_math.h"

static int available_client(void *elem)
{
    return ((client_t*)elem)->sock == -1;
}

int accept_client(server_t *serv)
{
    int new_sock = 0;
    client_t *new = NULL;

    if ((new_sock = accept(serv->sock, (struct sockaddr *)NULL, NULL)) < 0)
        return -1;
    if (new_sock >= FD_SETSIZE)
        return -1;
    if ((new = vec_find(serv->clients, &available_client)) == NULL)
        return -1;
    new->sock = new_sock;
    str_clear(&new->read);
    str_clear(&new->write);
    serv->max_sock = MY_MAX(serv->max_sock, new_sock);
    return new_sock;
}
