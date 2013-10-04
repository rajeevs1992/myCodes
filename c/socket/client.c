#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/socket.h>
int main()
{
    int s;
    struct sockaddr_in server;
    char buf[20];
    s = socket(AF_INET,SOCK_STREAM,0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(4545);
    connect(s,(struct sockaddr *)&server,sizeof(server));
    read(s,buf,20);
    puts(buf);
    write(s,"Hello from client",20);
    close(s);
    return 0;
}
/*
Output:
    Server:                     Client:
        Hello                   Hello
        Hello from client       
    */
