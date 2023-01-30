/*
** EPITECH PROJECT, 2022
** my_network
** File description:
** my_network declarations
*/

#ifndef INCLUDE_MY_NETWORK_
    #define INCLUDE_MY_NETWORK_
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #include "my_vec.h"
    #include "my_str.h"

    #define NETWORK_BUFF_SIZE   (1024)
    #define NETWORK_CRLF        ("\r\n")


typedef struct client_s {
    int sock;
    str_t *read;  // read data sent from the client.
    str_t *write; // write data to the client
} client_t;

typedef struct vec_client_s {
    vec_base_t base;
    client_t data[0];
} vec_client_t;

typedef struct server_s {
    int sock;
    int max_sock;
    struct sockaddr_in addr;
    fd_set read_set;
    fd_set write_set;

    vec_client_t *clients;
    void (*callback)(client_t *);
} server_t;


int accept_client(server_t *serv);

int server_run(server_t *serv);

server_t *server_create(int port, int max_conn, void (*cb)(client_t *));

int client_create(char *server_ip, int port);

int read_client(client_t *client);
int write_client(client_t *client);

int write_server(int sock, str_t *buff);
int read_server(int sock, str_t **buff);


// int receive_data(int sock, str_t **buff);
// int send_data(int sock, str_t *buff);


#endif /* INCLUDE_MY_NETWORK_ */
