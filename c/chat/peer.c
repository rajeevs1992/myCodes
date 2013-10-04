#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/socket.h>
int main()
{
    int sock,port,in;
    char buffer[50],address[20];
    memset(buffer,0,strlen(buffer));
    sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in peer;
    peer.sin_family=AF_INET;
    printf("Enter address \n");
    scanf("%s",address);
    peer.sin_addr.s_addr=inet_addr(address);
    peer.sin_port=3456;
    fflush(stdin);
    if(bind(sock,(struct sockaddr *)&peer,sizeof(peer))==-1)
    {
        connect(sock,(struct sockaddr *)&peer,sizeof(peer));
        while(1)
        {
            memset(buffer,0,strlen(buffer));
            read(sock,buffer,50);
            printf("\nAlice: %s\n",buffer);
            printf("\nBob: ");
            fgets(buffer,50,stdin);
            write(sock,buffer,strlen(buffer));
            memset(buffer,0,strlen(buffer));
        }
    }
    else
    {
        listen(sock,1);
        in=accept(sock,(struct sockaddr *)NULL,NULL);
        while(1)
        {
            memset(buffer,0,strlen(buffer));
            printf("\nAlice: ");
            fgets(buffer,50,stdin);
            write(in,buffer,strlen(buffer));

            memset(buffer,0,strlen(buffer));

            read(in,buffer,50);
            printf("\nBob: %s\n",buffer);
        }
    }
}

Output:

Alice's System:           Bob's System
---------------           ------------
Alice:Hi                   Alice:Hi
Bob:Hello                  Bob:Hello
