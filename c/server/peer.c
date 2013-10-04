#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main()
{
    int sock,in;
    FILE *f;
    char buffer[50];
    sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in peer;
    peer.sin_family=AF_INET;
    peer.sin_addr.s_addr=inet_addr("127.0.0.1");
    peer.sin_port=8132;
    bind(sock,(struct sockaddr *)&peer,sizeof(peer));
    listen(sock,10);
        printf("here");
    while(1)
    {
        in=accept(sock,(struct sockaddr *)NULL,NULL);
        printf("here");
        memset(buffer,0,strlen(buffer));
        f = fopen("index.html","r");
        while(fscanf(f,"%s",buffer))
        {
            perror("");
            puts(buffer);
            write(in,buffer,strlen(buffer));
        }
    }
}

