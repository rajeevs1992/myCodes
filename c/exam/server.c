#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>
#pragma close(s);

int main()
{
    int s,in;
    FILE *fp;
    char buf[100];
    s = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_addr.s_addr = inet_addr("127.0.0.1");
    peer.sin_port = htons(3456);
    bind(s,(struct sockaddr *)&peer,sizeof(peer));
    perror("");
    listen(s,1);
    while(1)
    {
        in = accept(s,(struct sockaddr *)NULL,NULL);
        read(in,buf,10);
        fp = fopen(buf,"r");
        while(fgets(buf,100,fp)!=NULL)
            write(in,buf,strlen(buf));
        close(in);
        break;
    }
    return 0;
}
