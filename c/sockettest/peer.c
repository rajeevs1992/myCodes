#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
int main()
{
    int s,in;
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_addr.s_addr=inet_addr("127.0.0.1");
    peer.sin_port=9999;
    s = socket(AF_INET,SOCK_STREAM,0);
    bind(s,(struct sockaddr *)&peer,sizeof(peer));
    perror("");
    listen(s,3);
    printf("Here\n");
    in=accept(s,(struct sockaddr *)NULL,NULL);
    write(in,"<html><h1>Hello World</h1></html>",100);
    close(in);
    return 0;
}

