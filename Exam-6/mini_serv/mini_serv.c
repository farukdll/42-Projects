#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_client{
    int id;
    char msg[1024];
} t_client;

t_client clients[1024 * 4];
int next_id = 0, max_fd = 0;
fd_set sockets, write_sock, read_sock;
char buffer_read[120000], buffer_write[120000];

void ft_err(const char *msg)
{
    write(2, msg, strlen(msg));
    exit(1);
}

void send_all(int not)
{
    for (int i = 0; i <= max_fd; i++)
        if (FD_ISSET(i, &write_sock) && i != not)
            send(i, buffer_write, strlen(buffer_write), 0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        ft_err("Wrong number arguments\n");
    int sockfd;
    struct sockaddr_in servaddr, cli;
    socklen_t len;
    // Socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
      ft_err("Fatal error\n");
    bzero(&servaddr, sizeof(servaddr));
    // Assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(atoi(av[1]));
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        ft_err("Fatal error\n");
    if (listen(sockfd, 10) != 0)
        ft_err("Fatal error\n");
    len = sizeof(cli);
    max_fd = sockfd;
    FD_ZERO(&sockets);
    FD_SET(sockfd, &sockets);
    bzero(clients, sizeof(clients));
    
    while (1)
    {
        read_sock = write_sock = sockets;
        if (select(max_fd + 1, &read_sock, &write_sock, NULL, NULL) < 0)
            continue ;
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &read_sock) && fd == sockfd)
            {
                int connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
                if (connfd < 0)
                    continue ;
                clients[connfd].id = next_id++;
                max_fd = connfd > max_fd ? connfd : max_fd;
                FD_SET(connfd, &sockets);
                sprintf(buffer_write, "server: client %d just arrived\n", clients[connfd].id);
                send_all(connfd);
                break;
            }
            if (FD_ISSET(fd, &read_sock) && fd != sockfd)
            {
                int res = recv(fd, buffer_read, 65536, 0);
                if(res <= 0)
                {
                    sprintf(buffer_write, "server: client %d just left\n", clients[fd].id);
                    send_all(fd);
                    FD_CLR(fd, &sockets);
                    close(fd);
                    break;
                }
                else
                {
                    for(int i = 0, j = strlen(clients[fd].msg); i < res; i++, j++)
                    {
                        clients[fd].msg[j] = buffer_read[i];
                        if(clients[fd].msg[j] == '\n')
                        {
                            clients[fd].msg[j] = '\0';
                            sprintf(buffer_write, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                            send_all(fd);
                            bzero(&clients[fd].msg, sizeof(clients[fd].msg));
                            j = -1;
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}