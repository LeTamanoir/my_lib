/*
** EPITECH PROJECT, 2022
** my_network
** File description:
** runtime
*/

#include "my_network.h"
#include "my_stdio.h"
#include "my_math.h"
#include "my_str.h"
#include "my_stdlib.h"
#include "my_obj.h"

void close_client(client_t *client)
{
    close(client->sock);
    client->sock = -1;
    str_clear(&client->read);
    str_clear(&client->write);
}

static int iterate_clients(client_t *client, server_t *srv)
{
    int rm_client = 0;

    if (client->sock == -1)
        return 0;
    if (FD_ISSET(client->sock, &srv->write_set) &&
        client->write->length > 0) {
        write_client(client);
        return 1;
    }
    if (FD_ISSET(client->sock, &srv->read_set)) {
        rm_client = (read_client(client) == 0);
        srv->callback(client);
        if (rm_client)
            close_client(client);
        return 1;
    }
    return 0;
}

static void update_socks(server_t *srv)
{
    vec_client_t *clients = srv->clients;

    FD_ZERO(&srv->read_set);
    FD_ZERO(&srv->write_set);
    FD_SET(srv->sock, &srv->read_set);
    for (size_t i = 0; i < clients->size; ++i) {
        if (clients->data[i].sock == -1)
            continue;
        FD_SET(clients->data[i].sock, &srv->read_set);
        FD_SET(clients->data[i].sock, &srv->write_set);
    }
}

int server_run(server_t *serv)
{
    fd_set *read_sck = &serv->read_set;
    fd_set *write_sck = &serv->write_set;

    while (1) {
        update_socks(serv);

        if (select(serv->max_sock + 1, read_sck, write_sck, NULL, NULL) < 0)
            return 1;
        if (FD_ISSET(serv->sock, read_sck)) {
            accept_client(serv);
            continue;
        }
        vec_for_each((vec_t *)serv->clients,
            (int (*)(void *, void *))&iterate_clients, serv);
    }
    return 0;
}
