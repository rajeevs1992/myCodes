#include<stdio.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
    int s,in;
    FILE *fp=fopen("test","w");;
    char buf[100];
    s = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_addr.s_addr = inet_addr("127.0.0.1");
    peer.sin_port = htons(3456);
    while(1)
    {
        connect(s,(struct sockaddr *)&peer,sizeof(peer));
        write(s,"src/test\0",10);
        while(read(s,buf,100)!=0)
            fwrite(buf,100,1,fp);
        fclose(fp);
        close(in);
        break;
    }
    return 0;
}
