/*
** EPITECH PROJECT, 2022
** my_network
** File description:
** server
*/

#include "my_network.h"
#include "my_stdio.h"
#include "my_math.h"
#include "my_stdlib.h"
#include "my_obj.h"

static int server_connect(server_t *srv, int max_conn)
{
    if ((srv->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
    if (bind(srv->sock, (struct sockaddr *)&srv->addr, sizeof(srv->addr)) < 0)
        return -1;
    if (listen(srv->sock, max_conn) < 0)
        return -1;

    srv->max_sock = srv->sock;
    return 0;
}

static vec_client_t *init_clients(int max_conn)
{
    vec_client_t *clients =
        (vec_client_t *)vec_create(max_conn, sizeof(client_t));
    client_t temp = {0};

    while (max_conn--) {
        temp.sock = -1;
        temp.read = str_ncreate("", NETWORK_BUFF_SIZE);
        temp.write = str_ncreate("", NETWORK_BUFF_SIZE);
        vec_push_back((vec_t **)&clients, &temp);
    }

    return clients;
}

server_t *server_create(int port, int max_conn, void (*cb)(client_t *))
{
    server_t *srv = obj_alloc(sizeof(server_t));
    my_memset(&srv->addr, 0, sizeof(srv->addr));
    srv->sock = 0;
    srv->clients = init_clients(max_conn);
    srv->addr.sin_family = AF_INET;
    srv->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    srv->addr.sin_port = htons(port);
    srv->callback = cb;

    if (server_connect(srv, max_conn) < 0)
        return NULL;
    my_printf("[INFO] server listening at: localhost:%d\n", port);
    return srv;
}

int client_create(char *server_ip, int port)
{
    int sock = 0;
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0)
        return -1;
    if (connect(sock,
        (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        return -1;
    return sock;
}
