#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<netinet/ip.h>
#include<sys/socket.h>
#include<arpa/inet.h>

struct sockaddr_in local;
void client(int port)
{
    int s=socket (AF_INET, SOCK_STREAM, 0);
    
    printf("Write ip address for connection:\n");
    char buf1[BUFSIZ];
    scanf("%s",&buf1);
    printf("Now write:\n");
    local.sin_addr.s_addr = inet_addr(buf1);
    local.sin_port = htons(port);
    local.sin_family = AF_INET;
    
    connect(s, (struct sockaddr*) &local, sizeof(local));
    
    char buf[BUFSIZ];
    do
    {
        scanf("%s", &buf);
        send(s, buf, strlen(buf)+1, MSG_NOSIGNAL);
    } while (strcmp(buf, "OFF"));
    close(s);
}

int main(int c, char **v)
{
    int port;
    printf("Enter port:\n");
    scanf("%d", &port);
    
    client(port);
}
