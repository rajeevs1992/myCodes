#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/socket.h>
int main()
{
    int s,in;
    struct sockaddr_in server;
    char buf[20];
    s = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(4545);
    bind(s,(struct sockaddr *)&server,sizeof(server));
    listen(s,1);
    while(1)
    {
        in=accept(s,(struct sockaddr *)NULL,NULL);
        memset(buf,0,strlen(buf));
        gets(buf);
        write(in,buf,20);
        read(in,buf,20);
        puts(buf);
        close(in);
    }
    close(s);
    return 0;
}

